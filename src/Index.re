let sceneCreate = Verv.dataCallback((scene, _) => {

  module SceneLoader = Verv.MakeLoader({let scene = scene});
  module SceneFactory = Verv.MakeGameObjFactory({let scene = scene});

  let loader = SceneLoader.loadImage("abc", [|"./abcFile"|]);

  let image = SceneFactory.addImage(0, 0, "abc", ~frame="abc", ());
  
  let test =  Verv.Image.((!> 
    image) 
  ) |> Verv.Image.setX(30);

  Js.log(test);
  Js.log(loader);
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