open VBase;
let phaser = PhaserAPI.phaser;
let auto = phaser->PhaserAPI.rendererAuto;
let canvas = phaser->PhaserAPI.rendererCanvas;
let headless = phaser->PhaserAPI.rendererHeadless;
let webgl = phaser->PhaserAPI.rendererWebGL;

let createGame = (~renderer, ~parent, ~width, ~height, ~scene) => {
  PhaserAPI.Game.make(
    PhaserAPI.gameConfig(
      ~type_=renderer,
      ~parent,
      ~width,
      ~height,
      ~scene,
      (),
    ),
  );
};

let createScene = (~key, ~init=?, ~preload=?, ~create=?, ~update=?, ()) => {
  let scene = PhaserAPI.Scene.make(PhaserAPI.sceneConfig(~key, ()));

  switch (init) {
  | Some(init) => scene->PhaserAPI.Scene.setInit(init)
  | None => ()
  };

  switch (create) {
  | Some(create) => scene->PhaserAPI.Scene.setCreate(create)
  | None => ()
  };

  switch (preload) {
  | Some(preload) => scene->PhaserAPI.Scene.setPreload(preload)
  | None => ()
  };

  switch (update) {
  | Some(update) => scene->PhaserAPI.Scene.update(update(scene))
  | None => ()
  };

  scene;
};

module Vector2 = Vector2;
module Image = Image;
module Input = Input;
module Tween = Tween;
module Text = Text;
module BitMapText = BitMapText;
module Shape = Shape;
module Scene = Scene;

module MakeLoader = (S: {let scene: PhaserAPI.sceneT;}) => {
  open PhaserAPI;
  let scene = S.scene;

  let loader = scene->Scene.load;
  let keyExists = keyName =>
    scene->Scene.load->LoaderPlugin.keyExists(keyName);

  let loadImage = (imageName, url) => {
    scene
    ->Scene.load
    ->LoaderPlugin.loadImage(LoaderPlugin.imageT(~key=imageName, ~url, ()))
    |> ignore;
  };

  let loadAudio = (audioName, urls) => {
    scene
    ->Scene.load
    ->LoaderPlugin.loadAudio(
        LoaderPlugin.audioConfigT(~key=audioName, ~url=urls, ()),
      )
    |> ignore;
  };

  let loadCSS = (cssName, url) => {
    scene
    ->Scene.load
    ->LoaderPlugin.loadCSS(LoaderPlugin.cssConfigT(~key=cssName, ~url, ()))
    |> ignore;
  };
};

module MakeGameObjFactory = (A: {let scene: PhaserAPI.sceneT;}) => {
  open PhaserAPI;
  let scene = A.scene;
  let factory = scene->Scene.add;

  let addImage = (x, y, texture, ~frame=?, ()) => {
    let image =
      switch (frame) {
      | Some(frame) =>
        factory->GameObjectFactory.imageIntStr(x, y, texture, ~frame, ())
      | None => factory->GameObjectFactory.imageIntStr(x, y, texture, ())
      };
    VervEffect(image);
  };

  let addSprite = (x, y, texture, ~frame=?, ()) => {
    let sprite =
      switch (frame) {
      | Some(frame) =>
        factory->GameObjectFactory.sprite(x, y, texture, ~frame, ())
      | None => factory->GameObjectFactory.sprite(x, y, texture, ())
      };
    VervEffect(sprite);
  };

  let addBlitter = (x, y, key, ~frame=?, ()) => {
    let blitter =
      switch (frame) {
      | Some(frame) =>
        factory->GameObjectFactory.blitter(x, y, key, ~frame, ())
      | None => factory->GameObjectFactory.blitter(x, y, key, ())
      };
    VervEffect(blitter);
  };

  let addPathInt = (x, y) => {
    VervEffect(factory->GameObjectFactory.pathInt(x, y));
  };

  let addPathF = (x, y) => {
    VervEffect(factory->GameObjectFactory.pathFloat(x, y));
  };

  let addText = (x, y, text, color) => {
    let text = factory->GameObjectFactory.text(x, y, text);
    VervEffect(text) |> Text.setColor(color);
  };

  let addBitmapText = (x, y, font, text) => {
    let bitmapText =
      factory->GameObjectFactory.bitmapText(~x, ~y, font, ~text, ());
    VervEffect(bitmapText);
  };

  let addZone = (x, y, width, height) => {
    let zone = factory->GameObjectFactory.zone(x, y, width, height);
    VervEffect(zone);
  };
};

module MakePhysics = (P: {let scene: PhaserAPI.sceneT;}) => {
  open PhaserAPI;
  let scene = P.scene;
};
