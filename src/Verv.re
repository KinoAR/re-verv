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