let sceneCreate = Verv.dataCallback((scene, _) => {
  let text =
    scene
    ->PhaserAPI.Scene.add
    ->PhaserAPI.GameObjectFactory.text(64, 200, "Hello World");
  text->PhaserAPI.GameObjects.Text.setColor("white");
})

let titleScene = Verv.createScene(~key="title", ~create=sceneCreate, ());

let game =
  Verv.createGame(
    ~renderer=Verv.auto,
    ~parent="phaser-example",
    ~width=800,
    ~height=600,
    ~scene=titleScene,
  );