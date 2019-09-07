open VBase;
let createScene = (~key, ~init=?, ~preload=?, ~create=?, ~update=?, ()) => {
  let vervScene = PhaserAPI.Scene.make(PhaserAPI.sceneConfig(~key, ()));

  let sceneUpdateCallback = fn =>
    [@bs.this]
    {
      (scene, time, delta) => {
        fn(scene, time, delta);
      };
    };
  switch (init) {
  | Some(init) => vervScene->PhaserAPI.Scene.setInit(dataCallback(init))
  | None => ()
  };

  switch (create) {
  | Some(create) =>
    vervScene->PhaserAPI.Scene.setCreate(dataCallback(create))
  | None => ()
  };

  switch (preload) {
  | Some(preload) =>
    vervScene->PhaserAPI.Scene.setPreload(zeroCallback(preload))
  | None => ()
  };

  switch (update) {
  | Some(update) =>
    vervScene->PhaserAPI.Scene.setUpdate(sceneUpdateCallback(update))
  | None => ()
  };
  vervScene;
};
