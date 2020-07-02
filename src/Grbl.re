open Rx;

type grblMsg = string;

type t = {
  serial: JsSerial.t,
  read: Subject.t(grblMsg),
  write: Subject.t(grblMsg),
};

let send = (grbl: t, message: grblMsg) => {
  JsSerial.write(grbl.serial, message);
};

let rec sendMany = (grbl: t, messages: list(grblMsg)) => {
  switch (messages) {
  | [] => None
  | [head, ...tail] =>
    send(grbl, head);
    sendMany(grbl, tail);
  };
};

type command =
  | G0(float, float)
  | G1(float, float)
  | M3(int);

type reply =
  | OK

let commandToString = (command: command): string => {
  switch (command) {
  | G0(x, y) => "G0 " ++ Js.Float.toString(x) ++ " " ++ Js.Float.toString(y)
  | G1(x, y) => "G1 " ++ Js.Float.toString(x) ++ " " ++ Js.Float.toString(y)
  | M3(height) => "M3 S" ++ Js.Int.toString(height)
  };
};

let sendCommand = (grbl: t, command: command) => {
  send(grbl, commandToString(command));
};

let init = (device: string): t => {
  let port = JsSerial.serial(device, ());
  let readline = JsSerial.readline(port);

  let read = Subject.create();
  let write = Subject.create();

  let dispatch = (port: JsSerial.t, msg: string) => {
    Js.log2(">", msg);
    JsSerial.writeOption(
      port,
      switch (msg) {
      | "[MSG:'$H'|'$X' to unlock]" => Some("$X")
      | _ =>
        Subject.next(msg, read);
        None;
      },
    );
  };

  ignore(
    readline
    ->JsSerial.on(`data(line => line->Js.String.trim->dispatch(port, _)))
    ->JsSerial.on(
        `close(
          () => {
            Js.log("port closed, exiting");
            Node.Process.exit(0);
          },
        ),
      ),
  );

  {read, write, serial: port};
};

/* let write = JsSerial.write(port); */
/* write("$X"); */
/* write("G21"); */
/* write("G90"); */
/* write("G10 P1 L20 X0 Y0 Z0"); */
