type t;
type readline;
type config = {
  baud: int
};

[@bs.module] [@bs.new] external externalCreateSerial : (string, config) => t = "serialport";
[@bs.module] [@bs.new] external readLine : unit => readline = "@serialport/parser-readline";
[@bs.send] external pipe: (t, readline) => t = "pipe";

[@bs.send]
external on: (
    readline,
    [@bs.string] [ | `close(unit => unit) | `line(string => unit)]
  ) => readline = "on";
  
let createSerial = (port: string, ~config: config={ baud: 6400 }, ()) => externalCreateSerial(port, config)

 

