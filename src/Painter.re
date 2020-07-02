open Rx;
open Three;
  
type painterMsg = string;

type stroke =
  | Line(Vector2.t, Vector2.t);

type drawing = list(stroke);

type t = {
  grbl: Grbl.t,
  painting: bool,
  write: Subject.t(stroke),
};

type command =
  | Brush(bool)
  | Move(float, float);

type reply =
  | OK

let commandToGrbl = (command: command): Grbl.command => {
  switch (command) {
  | Brush(state) => state ? Grbl.M3(0) : Grbl.M3(1000)
  | Move(x, y) => Grbl.G1(x, y)
  };
};

let sendCommand = (painter: t, command: command) => {
  commandToGrbl(command) |> Grbl.sendCommand(painter.grbl);
};


let draw = (painter: t, drawing: drawing) => {
  
}

let init = (grbl: Grbl.t): t => {
  {grbl, write: Subject.create(), painting: false};
};

let paint = (painter: t, state: bool): t => {
  state
    ? {
      Grbl.send(painter.grbl, "M3 S1000");
      painter;
    }
    : {
      Grbl.send(painter.grbl, "M3 S0");
      painter;
    };
};



