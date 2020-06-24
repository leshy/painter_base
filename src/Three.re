module Vector2 = {
  type t;

  type v =
    | V(float, float)
    | Three(t);

  [@bs.send] external clone: t => t = "clone";

  [@bs.module "three"] [@bs.new]
    external make: (float, float) => t = "Vector2";

  let ensureT = (v: v) => {
    switch (v) {
    | V(x, y) => make(x, y)
    | Three(t) => t
    };
  };

  let ensureTClone = (v: v) => {
    switch (v) {
    | V(x, y) => make(x, y)
    | Three(t) => clone(t)
    };
  };

  [@bs.send]
  external _add: (t, t) => t = "add";
  let add = (v1: v, v2: v) => {
    Three(ensureT(v1)->_add(ensureT(v2)));
  };

  [@bs.send]
  external _normalize: (t) => t = "normalize";
  let normalize = (v: v) => {
    Three(ensureT(v)->_normalize);
  };

  [@bs.send]
  external _length: (t) => float = "length";
  let length = (v: v) => {
    ensureT(v)->_length;
  };

  [@bs.send]
  external _multiplyScalar: (t, float) => t = "multiplyScalar";
  let multiplyScalar = (m: float, v: v) => {
    Three(ensureT(v) -> _multiplyScalar(_, m));
  };
};
