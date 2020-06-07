type t;
type readline;
type config = {
  baud: int
};

/* 

can I restrict baud rates with a type system? 
can variant types have numbers as names? 
can I map those numbers implicitly to js? 

can readLine function optionally take serialobject or externalCreateSerial and dispatch automatically?

*/

[@bs.module] [@bs.new] external jsCreateSerial : (string, config) => t = "serialport"
[@bs.module] [@bs.new] external jsReadLine : unit => readline = "@serialport/parser-readline"
[@bs.send] external pipe: (t, readline) => t = "pipe"

[@bs.send]
external on: (
    readline,
    [@bs.string] [ | `close(unit => unit) | `line(string => unit)]
  ) => readline = "on"


let serial = (device: string, ~config: config={ baud: 6400 }, ()) => jsCreateSerial(device, config)

let readline = (port: t) => {
  let rl = jsReadLine()
  ignore(pipe(port, rl))
  rl
}

