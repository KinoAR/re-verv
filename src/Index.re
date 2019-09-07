open VBase;
let sceneCreate = (scene, _) => {
  module SceneLoader =
    Verv.MakeLoader({
      let scene = scene;
    });
  module SceneFactory =
    Verv.MakeGameObjFactory({
      let scene = scene;
    });

  SceneLoader.loadImage("abc", [|"./abcFile"|]);

  let image = SceneFactory.addImage(0, 0, "abc", ~frame="abc", ());
  let sprite = SceneFactory.addSprite(30, 30, "abc", ~frame="abc", ());
  let test = Verv.Image.(image |> setX(30) |> setY(30));

  Js.log(test |> Verv.Image.name);
  Js.log(test |> Verv.Image.state);
  Js.log(sprite);
  let text = SceneFactory.addText(64, 64, "Hello from ReasonML", "white");
  ();
};

let titleScene =
  Verv.Scene.createScene(~key="title", ~create=sceneCreate, ());

let game =
  Verv.createGame(
    ~renderer=Verv.auto,
    ~parent="phaser-example",
    ~width=800,
    ~height=600,
    ~scene=titleScene,
  );

type gameStateT = {
  title: string,
  currentScene: PhaserAPI.sceneT,
  game: PhaserAPI.gameT,
};

type gameActionT =
  | ChangeTitle(string)
  | ChangeScene(string)
  | LogAction(string);

let (game, gameDispatcher) =
  useReducer(
    (state, action) =>
      switch (action) {
      | ChangeTitle(value) => {...state, title: value}
      | LogAction("Game Start") => state
      | ChangeScene("Title") => {...state, currentScene: titleScene}
      | _ => state
      },
    {title: "ReasonML Game", currentScene: titleScene, game},
  );

Js.log(game);
Js.log(gameDispatcher(ChangeTitle("Freljord")));
