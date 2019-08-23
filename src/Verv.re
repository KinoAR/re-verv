open PhaserAPI;
type vervTextT = VervText(GameObjects.textT);
type vervImageT = VervImage(GameObjects.imageT);
type vervImageContaerT = VervImageContainer(vervImageT); 
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

module Tween = {

};

module Text = {
  let addText = (scene, x, y, text, color) => {
    let text = scene -> Scene.add -> GameObjectFactory.text(x, y, text);
    text-> GameObjects.Text.setColor(color);
  };

  let setBlendMode = (text, blendMode) => {
   
  };
  
};

module BitMapText = {
  let addBitmapText = (scene, x, y, text, color) => {

  };
};

module Input = {

};

module Image = {
  module PImg = GameObjects.Image; 
  type t = vervImageT;
  let (!>) = (image) => VervImage(image);
  let lift = (image) => VervImage(image);
  let map = (f, vervImage) => switch(vervImage) {
    | VervImage(image) => VervImage(f(image));
  };

  let (<<=) = (vervImage, f) => switch(vervImage) {
    | VervImage(image) => VervImage(f(image));
  };

  let setX = (x, vervImage) => vervImage |> map(PImg.setX(_, x));
  let setY = (y, vervImage) => vervImage |> map(PImg.setY(_, y));
  let setW = (w, vervImage) => vervImage |> map(PImg.setW(_, w));
  let setZ = (z, vervImage) => vervImage |> map(PImg.setZ(_, z));
  
  let flatMap = (f, vervImage) => switch(vervImage) {
    | VervImage(image) => f(image);
  };

  let phaserImage = (vervImage) => vervImage |> flatMap(Tablecloth.identity); 
};

module MakeLoader = (S:{let scene:sceneT;}) => {
  let scene = S.scene;

  let loader =  () => scene -> Scene.load;
  let keyExists = (keyName) => scene -> Scene.load -> LoaderPlugin.keyExists(keyName);


  let loadImage = (imageName, url) => {
    scene -> Scene.load -> LoaderPlugin.loadImage(
      LoaderPlugin.imageT(~key=imageName, ~url, ())
    );
  };

  let loadAudio = (audioName, urls) => {
    scene -> Scene.load -> LoaderPlugin.loadAudio(
      LoaderPlugin.audioConfigT(
        ~key=audioName,
        ~url=urls,
        ()
      )
    )
  };

  let loadCSS = (cssName, url) => {
    scene -> Scene.load -> LoaderPlugin.loadCSS(
      LoaderPlugin.cssConfigT(
        ~key=cssName,
        ~url, 
        ()
      )
    );
  };
};

module MakeGameObjFactory = (A:{let scene:sceneT;}) => {
  let scene = A.scene;

  let addImage = (x, y, texture, ~frame=?, ()) => {
    let factory = scene -> Scene.add;
    switch(frame) {
      | Some(frame) => factory -> GameObjectFactory.imageIntStr(x, y, texture, ~frame, ());
      | None => factory -> GameObjectFactory.imageIntStr(x, y, texture, ());
    }
  };

  let addBitmapText = ()
};