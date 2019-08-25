open VBase;
open PhaserAPI;

module Static = {

};

module Dynamic = {
  module PABody = Physics.Arcade.Body;
  
  let allowDrag = PABody.allowDrag -> flatMap;
  let allowGravity = PABody.allowGravity -> flatMap;
  let angle = PABody.angle -> flatMap;
  let angleF = PABody.angleF -> flatMap;
  let angularAcceleration = PABody.angularAcceleration -> flatMap;
  let angularAccelerationF = PABody.angularAccelerationF -> flatMap;
  let angularDrag = PABody.angularDrag -> flatMap;
  let angularDragF = PABody.angularDragF -> flatMap;
  let angularVelocity = PABody.angularVelocity -> flatMap;
  let angularVelocityF = PABody.angularVelocityF -> flatMap;
  let bottom = PABody.bottom -> flatMap;
  let collideWorldBounds = PABody.collideWorldBounds -> flatMap;
  let customSeparateX = PABody.customSeperateX -> flatMap;
  let customSeparateY = PABody.customSeparateY -> flatMap;
  let debugBodyColor = PABody.debugBodyColor -> flatMap;
  let debugShowBody = PABody.debugShowBody -> flatMap;
  let embedded = PABody.embedded -> flatMap;
  let enabled = PABody.enable -> flatMap;
  let facing = PABody.facing -> flatMap;
  let gameObject = PABody.gameObject -> flatMap;
  let halfHeight = PABody.halfHeight -> flatMap;
  let halfHeightF = PABody.halfHeightF -> flatMap;
  let halfWidth = PABody.halfWidth -> flatMap;
  let halfWidthF = PABody.halfWidthF -> flatMap;
  let height = PABody.height -> flatMap;
  let heightF = PABody.heightF -> flatMap;
  let immovable = PABody.immovable -> flatMap;
  let mass = PABody.mass -> flatMap;
  let massF = PABody.massF -> flatMap;
  let moves = PABody.moves -> flatMap;
  let touching = PABody.touching -> flatMap;
  let onCollide = PABody.onCollide -> flatMap;
  let onOverlap = PABody.onOverlap -> flatMap;
  let onWorldBounds = PABody.onWorldBounds -> flatMap;
  let overlapR = PABody.overlapR -> flatMap;
  let overlapRF = PABody.overlapRF -> flatMap;
  let overlapX = PABody.overlapX -> flatMap;
  let overlapXF = PABody.overlapXF -> flatMap;
  let overlapY = PABody.overlapY -> flatMap;
  let overlapYF = PABody.overlapYF -> flatMap;
  let preRotation = PABody.preRotation -> flatMap;
  let preRotationF = PABody.preRotationF -> flatMap;
  let physicsType = PABody.physicsType -> flatMap;
  let radius = PABody.radius -> flatMap;
  let radiusF = PABody.radiusF -> flatMap;
  let right = PABody.right -> flatMap;
  let rightF = PABody.rightF -> flatMap;
  let rotation = PABody.rotation -> flatMap;
  let rotationF = PABody.rotationF -> flatMap;
  let sourceHeight = PABody.sourceHeight -> flatMap;
  let sourceHeightF = PABody.sourceHeightF -> flatMap;
  let sourceWidth = PABody.sourceWidth -> flatMap;
  let sourceWidthF = PABody.sourceWidthF -> flatMap;
  let width = PABody.width -> flatMap;
  let widthF = PABody.widthF -> flatMap;

  let deltaAbsX = PABody.deltaAbsX -> flatMap;
  let deltaAbsY = PABody.deltaAbsY -> flatMap;
  let deltaX = PABody.deltaX -> flatMap;
  let deltaY = PABody.deltaY -> flatMap;
  let deltaZ = PABody.deltaZ -> flatMap;
  let onCeiling = PABody.onCeiling -> flatMap;
  let onFloor = PABody.onFloor -> flatMap;
  let onWall = PABody.onWall -> flatMap;
  let reset = (x, y) => map(PABody.reset(_, x, y));
  let resetF = (x, y) => map(PABody.resetF(_, x, y));
  let setAllowDrag = (allow) => map(PABody.setAllowDrag(_, allow));
  let setAllowGravity = (allow) => map(PABody.setAllowGravity(_,allow));
  let setAllowRotation = allow => map(PABody.setAllowRotation(_, allow));
  let setAngularAcceleration = (acceleration) => map(PABody.setAngularAcceleration(_, acceleration));
  let setAngularAccelerationF = (acceleration) => map(PABody.setAngularAccelerationF(_, acceleration));
  let setAngularDrag = (drag) => map(PABody.setAngularDrag(_, drag));
  let setAngularDragF = (drag) => map(PABody.setAngularDragF(_, drag));
  let setBounce = (x, y) => map(PABody.setBounce(_, x, y));
  let setBounceF = (x, y) => map(PABody.setBounceF(_, x, y));
  let setBounceX = (x) => map(PABody.setBounceX(_, x));
  let setBounceXF = (x) => map(PABody.setBounceXF(_, x));
  let setBounceY = (y) => map(PABody.setBounceY(_, y));
  let setBounceYF = (y) => map(PABody.setBounceYF(_, y));
  let setOffset = (x, y) => map(PABody.setOffset(_, x, y));
  let setOffsetF = (x, y) => map(PABody.setOffsetF(_, x, y));
  let setDrag = (x, y) => map(PABody.setDrag(_, x, y));
  let setDragF = (x, y) => map(PABody.setDragF(_, x, y));
  let setDragX = (x) => map(PABody.setDragX(_, x));
  let setDragXF = (x) => map(PABody.setDragXF(_, x));
  let stop = map(PABody.stop);
};


module World = {

};