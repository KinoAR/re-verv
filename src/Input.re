open VBase;
open PhaserAPI;


module Keys = {
  module PKey = Input.Keyboard.Key;
  let isUp = PKey.isUp -> flatMap;
  let isDown = PKey.isDown -> flatMap;
  let keyCode = PKey.keyCode -> flatMap;
  let location = PKey.location -> flatMap;
  let shiftKey = PKey.shiftKey -> flatMap;
  let timeUp = PKey.timeUp -> flatMap;
  let timeDown = PKey.timeDown -> flatMap;
  let metaKey = PKey.metaKey -> flatMap;
  let altKey = PKey.altKey -> flatMap;
  let ctrlKey = PKey.ctrlKey -> flatMap;
  let enabled = PKey.enabled -> flatMap;
  let repeats = PKey.repeats -> flatMap;

  include Events.EventEmitter({type nonrec t = PKey.t});
};

module Pointer = {
 module PPointer = Input.Pointer;

 let active = PPointer.active -> flatMap;
 let angle = PPointer.angle -> flatMap;
 let angleF = PPointer.angleF -> flatMap;
 let button = PPointer.button -> flatMap;
 let buttons = PPointer.buttons -> flatMap;
 let camera = PPointer.camera -> flatMap;
 let deltaX = PPointer.deltaX -> flatMap;
 let deltaXF = PPointer.deltaXF -> flatMap;
 let deltaY = PPointer.deltaY -> flatMap;
 let deltaYF = PPointer.deltaYF -> flatMap;
 let deltaZ = PPointer.deltaZ -> flatMap;
 let deltaZF = PPointer.deltaZF -> flatMap;
 let distance = PPointer.distance -> flatMap;
 let id = PPointer.id -> flatMap;
 let isDown = PPointer.isDown -> flatMap;
 let locked = PPointer.locked -> flatMap;
 let primaryDown = PPointer.primaryDown -> flatMap;
 let upElement = PPointer.upElement -> flatMap;
 let downElement = PPointer.downElement -> flatMap;
 let x = PPointer.x -> flatMap;
 let xF = PPointer.xF -> flatMap;
 let y = PPointer.y -> flatMap;
 let yF = PPointer.yF -> flatMap;
 let worldX = PPointer.worldX -> flatMap;
 let worldXF = PPointer.worldXF -> flatMap;
 let worldY = PPointer.worldY -> flatMap;
 let worldYF = PPointer.worldYF -> flatMap;
 let velocity = PPointer.velocity -> flatMap;
 let wasTouch = PPointer.wasTouch -> flatMap;
 let wasCancelled = PPointer.wasCancelled -> flatMap;
 let time = PPointer.time -> flatMap;
 let timeF = PPointer.timeF -> flatMap;
 let moveTime = PPointer.moveTime -> flatMap;
 let moveTimeF = PPointer.moveTimeF -> flatMap;
 let pointerId = PPointer.pointerId -> flatMap;
 

 let getDistance = PPointer.getDistance -> flatMap;
 let getDistanceF = PPointer.getDistanceF -> flatMap;
 let getDistanceX = PPointer.getDistanceX -> flatMap;
 let getDistanceXF = PPointer.getDistanceXF -> flatMap;
 let getDistanceY = PPointer.getDistanceY -> flatMap;
 let getDistanceYF = PPointer.getDistanceYF -> flatMap;
 let destroy = PPointer.destroy -> flatMap;
 let backButtonReleased = PPointer.backButtonReleased -> flatMap;
 let backButtonDown = PPointer.backButtonDown -> flatMap;
 let forwardButtonDown = PPointer.forwardButtonDown -> flatMap;
 let forwardButtonReleased = PPointer.forwardButtonReleased -> flatMap;
 let noButtonDown = PPointer.noButtonDown -> flatMap;
 let rightButtonDown = PPointer.rightButtonDown -> flatMap;
 let rightButtonReleased = PPointer.rightButtonReleased -> flatMap;
 let middleButtonDown = PPointer.middleButtonDown -> flatMap;
 let middleButtonReleased = PPointer.middleButtonReleased -> flatMap;
 let getDuration = PPointer.getDuration -> flatMap;
 let getDurationF = PPointer.getDurationF -> flatMap;
 let getAngle = PPointer.getAngle -> flatMap;
 let getAngleF = PPointer.getAngleF -> flatMap;


};


module Mouse = {

};
