module Vector2 = {
  
  type vector =
    | V2(float, float)
    | ThreeInstance;

  [@bs.module "three"] [@bs.new] external make : (float, float) => ThreeInstance = "Vector2";

  [@bs.send] external clone: ThreeInstance => ThreeInstance = "clone";

  let ensureInstance = (v: vector) => {
    switch (v) {
    | V2(x, y) => make(x, y)
    | ThreeInstance => v
    };
  };

  let ensureInstanceClone = (v: vector) => {
    switch (v) {
    | V2(x,y) => make(x, y)
    | ThreeInstance => clone(v)
    };
  };

  [@bs.send] external _add: ThreeInstance => ThreeInstance => ThreeInstance = "add";
  let add = (v1: vector, v2: vector) => {
    ensureInstance(v1) -> _add(ensureInstance(v2));
  };
  
    
  
};

  /* [@bs.send] external _normalize: t => t = "normalize"; */
  /* let normalize = (v: t | vector2) => { */
  /*   ensureTClone(v) -> _normalize; */
  /* }; */


  
