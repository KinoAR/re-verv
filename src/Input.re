open VBase;

module Keys = {
  module PKey = PhaserAPI.Input.Keyboard.Key;
  let isUp = PKey.isUp->flatMap;
  let isDown = PKey.isDown->flatMap;
  let keyCode = PKey.keyCode->flatMap;
  let location = PKey.location->flatMap;
  let shiftKey = PKey.shiftKey->flatMap;
  let timeUp = PKey.timeUp->flatMap;
  let timeDown = PKey.timeDown->flatMap;
  let metaKey = PKey.metaKey->flatMap;
  let altKey = PKey.altKey->flatMap;
  let ctrlKey = PKey.ctrlKey->flatMap;
  let enabled = PKey.enabled->flatMap;
  let repeats = PKey.repeats->flatMap;

  include Events.EventEmitter({
    type nonrec t = PKey.t;
  });
};

module Pointer = {
  module PPointer = PhaserAPI.Input.Pointer;

  let active = PPointer.active->flatMap;
  let angle = PPointer.angle->flatMap;
  let angleF = PPointer.angleF->flatMap;
  let button = PPointer.button->flatMap;
  let buttons = PPointer.buttons->flatMap;
  let camera = PPointer.camera->flatMap;
  let deltaX = PPointer.deltaX->flatMap;
  let deltaXF = PPointer.deltaXF->flatMap;
  let deltaY = PPointer.deltaY->flatMap;
  let deltaYF = PPointer.deltaYF->flatMap;
  let deltaZ = PPointer.deltaZ->flatMap;
  let deltaZF = PPointer.deltaZF->flatMap;
  let distance = PPointer.distance->flatMap;
  let id = PPointer.id->flatMap;
  let isDown = PPointer.isDown->flatMap;
  let locked = PPointer.locked->flatMap;
  let primaryDown = PPointer.primaryDown->flatMap;
  let upElement = PPointer.upElement->flatMap;
  let downElement = PPointer.downElement->flatMap;
  let x = PPointer.x->flatMap;
  let xF = PPointer.xF->flatMap;
  let y = PPointer.y->flatMap;
  let yF = PPointer.yF->flatMap;
  let worldX = PPointer.worldX->flatMap;
  let worldXF = PPointer.worldXF->flatMap;
  let worldY = PPointer.worldY->flatMap;
  let worldYF = PPointer.worldYF->flatMap;
  let velocity = PPointer.velocity->flatMap;
  let wasTouch = PPointer.wasTouch->flatMap;
  let wasCancelled = PPointer.wasCancelled->flatMap;
  let time = PPointer.time->flatMap;
  let timeF = PPointer.timeF->flatMap;
  let moveTime = PPointer.moveTime->flatMap;
  let moveTimeF = PPointer.moveTimeF->flatMap;
  let pointerId = PPointer.pointerId->flatMap;
  let mouseEvent = PPointer.mouseEvent->flatMap;
  let touchEvent = PPointer.touchEvent->flatMap;

  let getDistance = PPointer.getDistance->flatMap;
  let getDistanceF = PPointer.getDistanceF->flatMap;
  let getDistanceX = PPointer.getDistanceX->flatMap;
  let getDistanceXF = PPointer.getDistanceXF->flatMap;
  let getDistanceY = PPointer.getDistanceY->flatMap;
  let getDistanceYF = PPointer.getDistanceYF->flatMap;
  let destroy = PPointer.destroy->flatMap;
  let backButtonReleased = PPointer.backButtonReleased->flatMap;
  let backButtonDown = PPointer.backButtonDown->flatMap;
  let forwardButtonDown = PPointer.forwardButtonDown->flatMap;
  let forwardButtonReleased = PPointer.forwardButtonReleased->flatMap;
  let noButtonDown = PPointer.noButtonDown->flatMap;
  let rightButtonDown = PPointer.rightButtonDown->flatMap;
  let rightButtonReleased = PPointer.rightButtonReleased->flatMap;
  let middleButtonDown = PPointer.middleButtonDown->flatMap;
  let middleButtonReleased = PPointer.middleButtonReleased->flatMap;
  let getDuration = PPointer.getDuration->flatMap;
  let getDurationF = PPointer.getDurationF->flatMap;
  let getAngle = PPointer.getAngle->flatMap;
  let getAngleF = PPointer.getAngleF->flatMap;
  let updateWorldPoint = camera => map(PPointer.updateWorldPoint(_, camera));
};

module Mouse = {};

module KeyCodes = {
  module PKeyCodes = PhaserAPI.Input.Keyboard.KeyCodes;
  type keycodes =
    | A
    | B
    | C
    | D
    | E
    | BackSlash
    | Alt
    | Backspace
    | Backtick
    | LeftBracket
    | RightBracket
    | LeftBracketFireFox
    | RightBracketFireFox
    | ClosedBracket
    | Colon
    | Comma
    | Ctrl
    | Delete
    | Down
    | Eight
    | End
    | Enter
    | Esc
    | F
    | F1
    | F2
    | F3
    | F4
    | F5
    | F6
    | F7
    | F8
    | F9
    | F10
    | F11
    | F12
    | Five
    | ForwardSlash
    | Four
    | G
    | H
    | Home
    | I
    | Insert
    | J
    | K
    | L
    | Left
    | M
    | Minus
    | N
    | Nine
    | NumpadEight
    | NumpadFive
    | NumpadFour
    | NumpadNine
    | NumpadOne
    | NumpadSeven
    | NumpadSix
    | NumpadThree
    | NumpadTwo
    | NumpadZero
    | O
    | One
    | OpenBracket
    | P
    | PageDown
    | PageUp
    | Pause
    | Period
    | Plus
    | PrintScreen
    | Q
    | Quotes
    | R
    | Right
    | S
    | Semicolon
    | SemicolonFireFox
    | Seven
    | Shift
    | Six
    | Space
    | T
    | Tab
    | Three
    | Two
    | U
    | Up
    | V
    | W
    | X
    | Y
    | Z
    | Zero;

  let a = PKeyCodes.a->flatMap;
  let b = PKeyCodes.b->flatMap;
  let c = PKeyCodes.c->flatMap;
  let backSlash = PKeyCodes.backSlash->flatMap;
  let alt = PKeyCodes.alt->flatMap;
  let backSpace = PKeyCodes.backSpace->flatMap;
  let colon = PKeyCodes.colon->flatMap;
  let backTick = PKeyCodes.backTick->flatMap;
  let comma = PKeyCodes.comma->flatMap;
  let commaFireFox = PKeyCodes.commaFFox->flatMap;
  let commaFireFoxWindows = PKeyCodes.commaFFoxWindows->flatMap;
  let ctrl = PKeyCodes.ctrl->flatMap;
  let d = PKeyCodes.d->flatMap;
  let delete = PKeyCodes.delete->flatMap;
  let down = PKeyCodes.down->flatMap;
  let e = PKeyCodes.e->flatMap;
  let eight = PKeyCodes.eight;
  let end_ = PKeyCodes.end_->flatMap;
  let enter = PKeyCodes.enter->flatMap;
  let esc = PKeyCodes.esc->flatMap;
  let f = PKeyCodes.f->flatMap;
  let f1 = PKeyCodes.f1->flatMap;
  let f2 = PKeyCodes.f2->flatMap;
  let f3 = PKeyCodes.f3->flatMap;
  let f4 = PKeyCodes.f4->flatMap;
  let f5 = PKeyCodes.f5->flatMap;
  let f6 = PKeyCodes.f6->flatMap;
  let f7 = PKeyCodes.f7->flatMap;
  let f8 = PKeyCodes.f8->flatMap;
  let f9 = PKeyCodes.f9->flatMap;
  let f10 = PKeyCodes.f10->flatMap;
  let f11 = PKeyCodes.f11->flatMap;
  let f12 = PKeyCodes.f12->flatMap;
  let five = PKeyCodes.five->flatMap;
  let forwardSlash = PKeyCodes.forwardSlash->flatMap;
  let four = PKeyCodes.four->flatMap;
  let g = PKeyCodes.g->flatMap;
  let h = PKeyCodes.h->flatMap;
  let home = PKeyCodes.home->flatMap;
  let i = PKeyCodes.i->flatMap;
  let insert = PKeyCodes.insert->flatMap;
  let j = PKeyCodes.j->flatMap;
  let k = PKeyCodes.k->flatMap;
  let l = PKeyCodes.l->flatMap;
  let left = PKeyCodes.left->flatMap;
  let m = PKeyCodes.m->flatMap;
  let minus = PKeyCodes.minus->flatMap;
  let n = PKeyCodes.n->flatMap;
  let nine = PKeyCodes.nine->flatMap;
  let numPadEight = PKeyCodes.numpadEight->flatMap;
  let numpadFive = PKeyCodes.numpadFive->flatMap;
  let numpadFour = PKeyCodes.numpadFour->flatMap;
  let numpadNine = PKeyCodes.numpadNine->flatMap;
  let numpadOne = PKeyCodes.numpadOne->flatMap;
  let numpadSeven = PKeyCodes.numpadSeven->flatMap;
  let numpadSix = PKeyCodes.numpadSix->flatMap;
  let numpadThree = PKeyCodes.numpadThree->flatMap;
  let numpadTwo = PKeyCodes.numpadTwo->flatMap;
  let numpadZero = PKeyCodes.numpadZero->flatMap;
  let p = PKeyCodes.p->flatMap;
  let pageDown = PKeyCodes.pageDown->flatMap;
  let pageUp = PKeyCodes.pageUp->flatMap;
  let pause = PKeyCodes.pause->flatMap;
  let period = PKeyCodes.period->flatMap;
  let plus = PKeyCodes.plus->flatMap;
  let printScreen = PKeyCodes.printScreen->flatMap;
  let q = PKeyCodes.q->flatMap;
  let quotes = PKeyCodes.quotes->flatMap;
  let r = PKeyCodes.r->flatMap;
  let right = PKeyCodes.right->flatMap;
  let s = PKeyCodes.s->flatMap;
  let semicolon = PKeyCodes.semicolon->flatMap;
  let semicolonFFox = PKeyCodes.semicolonFFox->flatMap;
  let seven = PKeyCodes.seven->flatMap;
  let shift = PKeyCodes.shift->flatMap;
  let six = PKeyCodes.six->flatMap;
  let space = PKeyCodes.space->flatMap;
  let t = PKeyCodes.t->flatMap;
  let tab = PKeyCodes.tab->flatMap;
  let three = PKeyCodes.three->flatMap;
  let two = PKeyCodes.two->flatMap;
  let u = PKeyCodes.u->flatMap;
  let up = PKeyCodes.up->flatMap;
  let v = PKeyCodes.v->flatMap;
  let w = PKeyCodes.w->flatMap;
  let x = PKeyCodes.x->flatMap;
  let y = PKeyCodes.y->flatMap;
  let zero = PKeyCodes.zero->flatMap;
};

module KeyCombo = {
  module PKeyCombo = PhaserAPI.Input.Keyboard.KeyCombo;
  let current = PKeyCombo.current->flatMap;
  let deleteOnMatch = PKeyCombo.deleteOnMatch->flatMap;
  let enabled = PKeyCombo.enabled->flatMap;
  let index = PKeyCombo.index->flatMap;
  let keyCodes = PKeyCombo.keyCodes->flatMap;
  let matched = PKeyCombo.matched->flatMap;
  let maxKeyDelay = PKeyCombo.maxKeyDelay->flatMap;
  let resetOnMatch = PKeyCombo.resetOnMatch->flatMap;
  let resetOnWrongKey = PKeyCombo.resetOnWrongKey->flatMap;
  let size = PKeyCombo.size->flatMap;
  let sizeF = PKeyCombo.sizeF->flatMap;
  let timeLastMatched = PKeyCombo.timeLastMatched->flatMap;
  let timeLastMatchedF = PKeyCombo.timeLastMatchedF->flatMap;
  let timeMatched = PKeyCombo.timeMatched->flatMap;
  let timeMatchedF = PKeyCombo.timeMatchedF->flatMap;
  let progress = PKeyCombo.progress->flatMap;
  let destroy = PKeyCombo.destroy->flatMap;
};
