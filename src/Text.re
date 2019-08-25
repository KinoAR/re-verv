open VBase;
open PhaserAPI;
type t = GameObjects.Text.t;
module PText = GameObjects.Text;

let setColor = (color, container) => container |> map(PText.setColor(_, color));

include Components.BaseGameObject({type nonrec t = t;});
include Components.BlendMode({type nonrec t = t;});
include Components.Origin({
  type nonrec t = t;
});

include Components.Tint({
  type nonrec t = t;
});

include Components.Flip({type nonrec t  = t;});

include Components.ScrollFactor({
  type nonrec t = t;
});

include Components.Transform({
  type nonrec t = t;
});

include Components.Visible({
  type nonrec t = t;
});