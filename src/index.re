
let port = JsSerial.serial("/dev/ttyUSB0", ());
let readline = JsSerial.readline(port);

readline
  -> JsSerial.on(`line(line => line
                       -> Js.String.trim
                       -> Js.log))
  
  -> JsSerial.on(`close(() => {
  Js.log("port closed, exiting");
  Node.Process.exit(0);
}));




