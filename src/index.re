
let port = JsSerial.createSerial("/dev/ttyUSB0", ());
let readline = JsSerial.readLine();

JsSerial.pipe(port, readline)
JsSerial.on(readline, `line(line => Js.log(line)));


