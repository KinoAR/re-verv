open PhaserAPI;
let phaser = phaser;
let auto = phaser->rendererAuto;
let canvas = phaser->rendererCanvas;
let headless = phaser->rendererHeadless;
let webgl = phaser->rendererWebGL;


let createGame = (~renderer, ~parent, ~width, ~height, ~scene) => {
   Game.make(gameConfig(
     ~type_=renderer,
     ~parent,
     ~width,
     ~height,
     ~scene,
     ()
   ));
};


let zeroCallback = (fn) => {
  ([@bs.this] (this) => {
    fn(this) |> ignore;
  });
};

let dataCallback = (fn) => {
  ([@bs.this] (scene , data) => {
    fn(scene:Scene.t, data) |> ignore;
  })
}


let createScene = (~key, ~init=?, 
  ~preload=?, 
  ~create=?, 
  ~update=?, ()) => {
  let scene = Scene.make(
    sceneConfig(
      ~key,
      ()
    )
  );

  switch(init) {
    | Some(init) => scene->Scene.setInit(init)
    | None => ()
  };

  switch(create) {
    | Some(create) => scene->Scene.setCreate(create);
    | None => ()
  };

  switch(preload) {
    | Some(preload) => scene -> Scene.setPreload(preload)
    | None => ()
  };

  switch(update) {
    | Some(update) => scene -> Scene.update(update(scene))
    | None => ()
  };
  
  scene;
};

module Vector2 = {
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
  
};

module Text = {
  let addText = (scene, x, y, text, color) => {
    let text = scene -> Scene.add -> GameObjectFactory.text(x, y, text);
    text-> GameObjects.Text.setColor(color);
  };
  
};

module BitMapText = {
  let addBitmapText = (scene, x, y, text, color) => {

  };
};

