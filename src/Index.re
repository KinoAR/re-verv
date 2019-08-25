let sceneCreate = Verv.dataCallback((scene, _) => {

  module SceneLoader = Verv.MakeLoader({let scene = scene});
  module SceneFactory = Verv.MakeGameObjFactory({let scene = scene});

  SceneLoader.loadImage("abc", [|"./abcFile"|]);

  let image = SceneFactory.addImage(0, 0, "abc", ~frame="abc", ());
  
  let test = Verv.Image.(image |> setX(30) |> setY(30));

  Js.log(test |> Verv.Image.name);
  Js.log(test |> Verv.Image.state);

  let text = SceneFactory.addText(64, 64, "Hello from ReasonML", "white");
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