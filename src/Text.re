open PhaserAPI;
type t = GameObjects.Text.t;

let addText = (scene, x, y, text, color) => {
    let text = scene -> Scene.add -> GameObjectFactory.text(x, y, text);
    text-> GameObjects.Text.setColor(color);
};

include GameObjects.BaseGameObject({type nonrec t = t;});
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