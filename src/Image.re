open VBase;
open PhaserAPI;

module PImg = GameObjects.Image;

include Components.BaseGameObject({
  type nonrec t = PImg.t;
});
include Components.Alpha({
  type nonrec t = PImg.t;
});
include Components.Depth({
  type nonrec t = PImg.t;
});
let setPipeline = (pipeline, vervImage) =>
  vervImage |> map(PImg.setPipeline(_, pipeline));

let phaserImage = vervImage => vervImage |> flatMap(Tablecloth.identity);

include Components.Origin({
  type nonrec t = PImg.t;
});
include Components.Flip({
  type nonrec t = PImg.t;
});
include Components.ScrollFactor({
  type nonrec t = PImg.t;
});

include Components.Transform({
  type nonrec t = PImg.t;
});
