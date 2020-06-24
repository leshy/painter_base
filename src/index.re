open Three;

let vector3 = Vector2.add(Vector2.V(0.5, 1.5), Vector2.V(0.0, 1.0)) -> Vector2.multiplyScalar(3.0, _)
Js.log(vector3);

let painter = Painter.init(Grbl.init("/dev/ttyUSB0"));
Js.log(painter);
