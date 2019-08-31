open VBase;
open PhaserAPI;

module Camera2D = {
  module PCamera2D = Cameras.CameraScene2D;
  include Components.Flip({
    type nonrec t = PCamera2D.t;
  });
  include Components.Tint({
    type nonrec t = PCamera2D.t;
  });

  let backgroundColor = PCamera2D.backgroundColor->flatMap;
  let cameraManager = PCamera2D.cameraManager->flatMap;
  let id = PCamera2D.id->flatMap;
  let originX = PCamera2D.originX->flatMap;
  let originY = PCamera2D.originY->flatMap;
};
