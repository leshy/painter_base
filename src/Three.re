

module Vector2 = {
  type t;
  [@bs.module "three"] [@bs.new] external make : (float, float) => t = "Vector2";
  
  [@bs.send] external clone: t => t = "clone";

  [@bs.send] external _add: t => t => t = "add";
  let add = (v1: t, v2: t) => {
    clone(v1) -> _add(v2);
  };

  [@bs.send] external _normalize: t => t = "normalize";
  let normalize = (v: t) => {
    clone(v) -> _normalize;
  };

}

  
