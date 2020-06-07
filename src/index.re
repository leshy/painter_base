
let port = JsSerial.serial("/dev/ttyUSB0", ~config={ baudRate: 115200 }, ());
let readline = JsSerial.readline(port);

readline
  -> JsSerial.on(`data(line => line
                       -> Js.String.trim
                       -> Js.log))
  
  -> JsSerial.on(`close(() => {
  Js.log("port closed, exiting");
  Node.Process.exit(0);
}));

/* JsSerial.write(port, "test test 1 2 3 \n"); */






