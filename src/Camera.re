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
  let useBounds = PCamera2D.useBounds->flatMap;
  let width = PCamera2D.width->flatMap;
  let widthF = PCamera2D.widthF->flatMap;
  let height = PCamera2D.height->flatMap;
  let heightF = PCamera2D.heightF->flatMap;
  let zoom = PCamera2D.zoom->flatMap;
  let scrollX = PCamera2D.scrollX->flatMap;
  let scrollXF = PCamera2D.scrollXF->flatMap;
  let scrollY = PCamera2D.scrollYF->flatMap;
  let scrollYF = PCamera2D.scrollYF->flatMap;
  let name = PCamera2D.name->flatMap;
  let roundPixels = PCamera2D.roundPixels->flatMap;
  let centerX = PCamera2D.centerX->flatMap;
  let transparent = PCamera2D.transparent->flatMap;
  let mask = PCamera2D.mask->flatMap;
  let geometryMask = PCamera2D.geometryMask->flatMap;
  let midPoint = PCamera2D.midPoint->flatMap;

  let centerOn = (x, y) => map(PCamera2D.centerOn(_, x, y));
  let centerOnF = (x, y) => map(PCamera2D.centerOnF(_, x, y));
  let centeronX = x => map(PCamera2D.centerOnX(_, x));
  let centerOnXF = x => map(PCamera2D.centerOnXF(_, x));
  let centerOnY = y => map(PCamera2D.centerOnY(_, y));
  let centerOnYF = y => map(PCamera2D.centerOnYF(_, y));

  let centerToBounds = map(PCamera2D.centerToBounds);
  let centerToSize = map(PCamera2D.centerToSize);
  let removeBounds = map(PCamera2D.removeBounds);
  let setBackgroundColor = color =>
    switch (color) {
    | Some(color) => map(PCamera2D.setBackgroundColor(_, ~color, ()))
    | None => map(PCamera2D.setBackgroundColor(_, ()))
    };
  let cull = renderables =>
    map(PCamera2D.cull(_, ~renderableObjects=renderables));
  let ignore = renderables =>
    map(PCamera2D.ignore(_, ~renderableObjects=renderables));
};
