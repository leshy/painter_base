module Vector2 = {
  // Abstract type that we just pass around. We don't access internals of it.
  type threeInstance;

  type vector =
    | V2(float, float)
    | ThreeInstance(threeInstance);

  [@bs.module "three"] [@bs.new]
  external _make: (float, float) => threeInstance = "Vector2";

  let make = (x, y) => ThreeInstance(_make(x, y));

  [@bs.send] external clone: threeInstance => threeInstance = "clone";

  let ensureInstance = (v: vector) => {
    switch (v) {
    | V2(x, y) => _make(x, y)
    | ThreeInstance(threeInstance) => threeInstance
    };
  };

  let ensureInstanceClone = (v: vector) => {
    switch (v) {
    | V2(x, y) => _make(x, y)
    | ThreeInstance(threeInstance) => clone(threeInstance)
    };
  };

  [@bs.send]
  external _add: (threeInstance, threeInstance) => threeInstance = "add";
  let add = (v1: vector, v2: vector) => {
    ensureInstance(v1)->_add(ensureInstance(v2));
  };
};