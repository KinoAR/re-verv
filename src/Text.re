open VBase;
open PhaserAPI;
type t = GameObjects.Text.t;
module PText = GameObjects.Text;


let make = (scene, ~x, ~y, ~text, ~style) => Container(PText.make(scene, ~x, ~y, ~text, ~style));
let dirty = PText.dirty -> flatMap;
let setColor = (color) =>  map(PText.setColor(_, color));
let initRTL = PText.initRTL -> flatMap;
let lineSpacing = flatMap(PText.lineSpacing);
let setLineSpacing = (lineSpacing, component) => component |> map(PText.setLineSpacing(_, lineSpacing));
let setStroke = (color, thickness, component) => component |> map(PText.setStroke(_, color, thickness));
let updateText = component => component |> map(PText.updateText);
let setShadowStroke = (enabled, component) => component |> map(PText.setShadowStroke(_, enabled));
let setShadowFill = (enabled, component) => component |> map(PText.setShadowFill(_, enabled));
let setFontFamily = (fontFamily, component) => component |> map(PText.setFontFamily(_, fontFamily));
let setFont = (font, component) => component |> map(PText.setFont(_, font));
let setFontSize = (size, component) => component |> map(PText.setFontSize(_, size));
let setBackgroundColor = (color, component) => component |> map(PText.setBackgroundColor(_, color));
let setShadowColor = (color, component) => component |> map(PText.setShadowColor(_, color));
let setShadowBlur = (blur, component) => component |> map(PText.setShadowBlur(_, blur));
let setFixedSize = (width, height, component) => component |> map(PText.setFixedSize(_, width, height));
let setFill = (color) =>  map(PText.setFill(_, color));

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