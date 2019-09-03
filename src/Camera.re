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
  let scaleManager = PCamera2D.scaleManager->flatMap;
  let sceneManager = PCamera2D.sceneManager->flatMap;
  let scene = PCamera2D.scene->flatMap;
  let displayHeight = PCamera2D.displayHeight->flatMap;
  let displayHeightF = PCamera2D.displayHeightF->flatMap;
  let displayWidth = PCamera2D.displayWidth->flatMap;
  let displayWidthF = PCamera2D.displayWidthF->flatMap;
  let resolution = PCamera2D.resolution->flatMap;
  let resolutionF = PCamera2D.resolutionF->flatMap;
  let centerY = PCamera2D.centerY->flatMap;
  let centerYF = PCamera2D.centerYF->flatMap;
  let centerXY = PCamera2D.centerXF->flatMap;

  let centerOn = (x, y) => map(PCamera2D.centerOn(_, x, y));
  let centerOnF = (x, y) => map(PCamera2D.centerOnF(_, x, y));
  let centeronX = x => map(PCamera2D.centerOnX(_, x));
  let centerOnXF = x => map(PCamera2D.centerOnXF(_, x));
  let centerOnY = y => map(PCamera2D.centerOnY(_, y));
  let centerOnYF = y => map(PCamera2D.centerOnYF(_, y));
  let clampX = x => map(PCamera2D.clampX(_, x));
  let clampY = y => map(PCamera2D.clampY(_, y));
  let clampXF = x => map(PCamera2D.clampXF(_, x));
  let clampYF = y => map(PCamera2D.clampYF(_, y));

  let centerToBounds = map(PCamera2D.centerToBounds);
  let centerToSize = map(PCamera2D.centerToSize);
  let removeBounds = map(PCamera2D.removeBounds);
  let setBackgroundColor = color =>
    switch (color) {
    | Some(color) => map(PCamera2D.setBackgroundColor(_, ~color, ()))
    | None => map(PCamera2D.setBackgroundColor(_, ()))
    };
  let clearMask = (~destroyMask=?, ()) =>
    switch (destroyMask) {
    | Some(destroy) => map(PCamera2D.clearMask(_, ~destroyMask=destroy, ()))
    | None => map(PCamera2D.clearMask(_, ()))
    };
  let cull = renderables =>
    map(PCamera2D.cull(_, ~renderableObjects=renderables));
  let ignore = renderables =>
    map(PCamera2D.ignore(_, ~renderableObjects=renderables));

  let setAngle = angle => map(PCamera2D.setAngle(_, angle));
  let setAngleF = angle => map(PCamera2D.setAngleF(_, angle));
  let setBounds = (x, y, width, height, ~centerOn=?, ()) =>
    switch (centerOn) {
    | Some(centerOn) =>
      map(PCamera2D.setBounds(_, ~x, ~y, ~width, ~height, ~centerOn, ()))
    | None => map(PCamera2D.setBounds(_, ~x, ~y, ~width, ~height, ()))
    };
  let setName = name => map(PCamera2D.setName(_, name));
  let setPosition = (x, ~y=?, ()) =>
    switch (y) {
    | Some(y) => map(PCamera2D.setPosition(_, ~x, ~y, ()))
    | None => map(PCamera2D.setPosition(_, ~x, ()))
    };

  let setPositionF = (x, ~y=?, ()) =>
    switch (y) {
    | Some(y) => map(PCamera2D.setPositionF(_, ~x, ~y, ()))
    | None => map(PCamera2D.setPositionF(_, ~x, ()))
    };
  let setRotation = rotation => map(PCamera2D.setRotation(_, rotation));
  let setRotationF = rotation => map(PCamera2D.setRotationF(_, rotation));
  let setRoundsPixels = round => map(PCamera2D.setRoundsPixels(_, round));
  let setScene = scene => map(PCamera2D.setScene(_, ~scene));
  let setVisible = visible => map(PCamera2D.setVisible(_, visible));
  let setViewport = (~x, ~y, ~width, ~height=?, ()) =>
    switch (height) {
    | Some(height) =>
      map(PCamera2D.setViewport(_, ~x, ~y, ~width, ~height, ()))
    | None => map(PCamera2D.setViewport(_, ~x, ~y, ~width, ()))
    };

  let setViewportF = (~x, ~y, ~width, ~height=?, ()) =>
    switch (height) {
    | Some(height) =>
      map(PCamera2D.setViewportF(_, ~x, ~y, ~width, ~height, ()))
    | None => map(PCamera2D.setViewportF(_, ~x, ~y, ~width, ()))
    };
  let setZoom = (~value=?, ()) =>
    switch (value) {
    | Some(value) => map(PCamera2D.setZoom(_, ~value, ()))
    | None => map(PCamera2D.setZoom(_, ()))
    };
  let setScroll = (~x, ~y=?, ()) =>
    switch (y) {
    | Some(y) => map(PCamera2D.setScroll(_, ~x, ~y, ()))
    | None => map(PCamera2D.setScroll(_, ~x, ()))
    };
};
