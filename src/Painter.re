open Rx;

type painterMsg = string;

type t = {
  grbl: Grbl.t,
  painting: bool,
  subject: Subject.t(painterMsg),
};

let init = (grbl: Grbl.t): t => {
  {grbl, subject: Subject.create(), painting: false};
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
