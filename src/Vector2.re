open PhaserAPI;

type vector2T = (int, int);
type vector2FT= (float, float);
type vervVector2T = 
| Vector2(int, int)
| Vector2F(float, float);

let toPhaserVec2 = ((x, y)) => Math.Vector2.make(x, y);
let toPhaserVec2F = ((x, y)) => Math.Vector2.makeF(x, y);

  
let (+!) = ((x, y), (x2, y2)) => (x +. x2, y +. y2);

let toIntVector = (vector2F) => vector2F |> Tablecloth.Tuple2.mapAll(~f=int_of_float);
let toFloatVector = (vector2F) => vector2F |> Tablecloth.Tuple2.mapAll(~f=float_of_int);