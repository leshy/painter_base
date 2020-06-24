
type t;
type readline;
type config = {
  baudRate: int
};

[@bs.module] [@bs.new] external jsCreateSerial : (string, config) => t = "serialport"
[@bs.module] [@bs.new] external jsReadLine : unit => readline = "@serialport/parser-readline"
[@bs.send] external pipe: (t, readline) => t = "pipe"
[@bs.send] external jsWrite: (t, string) => unit = "write"
  
[@bs.send] external on: (
    readline,
    [@bs.string] [ | `close(unit => unit) | `data(string => unit)]
) => readline = "on";

  /* let write = (port: t, msg: option(string)) => switch (msg) { */
  /*   | Some(value) => jsWrite(port, value ++ "\n") */
  /*   | None => () */
  /* } */
  
let writeOption = (port: t, msg: option(string)) => switch (msg) {
  | Some(value) => jsWrite(port, value ++ "\n")
  | None => ()
  };

let write = (port: t, msg: string) => {
  Js.log2("<", msg)
  jsWrite(port, msg ++ "\n")
}


let serial = (device: string, ~config: config={ baudRate: 115200 }, ()) => jsCreateSerial(device, config);
  
let readline = (port: t) => {
  let rl = jsReadLine()
  ignore(pipe(port, rl))
  rl
}

