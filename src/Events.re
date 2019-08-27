open VBase;
open PhaserAPI;

module EventEmitter = (E:{type t;}) => {
  module PEEmitter = Events.EventEmitter({type nonrec t = E.t});

  let emit0 = eventName => flatMap(PEEmitter.emit0(_, eventName));
  let emit1 = (eventName, arg1) => flatMap(PEEmitter.emit1(_, eventName, arg1));
  let emit2 = (eventName, arg1, arg2 ) => flatMap(PEEmitter.emit2(_, eventName, arg1, arg2));
  let destroy = PEEmitter.destroy -> flatMap;
  let shutdown = PEEmitter.shutdown -> flatMap;
  let eventNames = PEEmitter.eventNames -> flatMap;
  let offStr  = eventName => map(PEEmitter.offStr(_, eventName));
  let addEventListener = (eventName, fn) => map(PEEmitter.addEventListener(_, eventName, fn));
  let on = (eventName, fn) => map(PEEmitter.on(_, eventName, fn));
  let off = (eventName, fn) => map(PEEmitter.off(_, eventName, fn));
  let listeners = (eventName) => map(PEEmitter.listeners(_, eventName));
  let removeAllListeners = PEEmitter.removeAllListeners -> map;
  let removeAllListenersStr = eventName => map(PEEmitter.removeAllListenersStr(_, eventName));
  let removeListenerStr = eventName => map(PEEmitter.removeListenerStr(_, eventName));
};