open VBase;
open PhaserAPI;

  type t = GameObjects.BitmapText.t;
  
include Components.Origin({
  type nonrec t = t;
});

include Components.Tint({
  type nonrec t = t;
});

include Components.ScrollFactor({
  type nonrec t = t;
});

include Components.Transform({
  type nonrec t = t;
})