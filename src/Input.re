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

module Mouse = {

};
