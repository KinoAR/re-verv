open VBase;
open PhaserAPI;

module PImg = GameObjects.Image;
let (!>) = (image:PImg.t) => Container(image);
let lift = (image:PImg.t) => Container(image);


let (<<=) = (vervContainer, f) => switch(vervContainer) {
  | Container(image) => Container(f(image));
};


let setPipeline = (pipeline, vervImage) => vervImage |> map(PImg.setPipeline(_, pipeline));
let phaserImage = (vervImage:vervContainerT(PImg.t)) => vervImage |> flatMap(Tablecloth.identity);
include Components.Origin({
  type nonrec t = PImg.t;
})
include Components.Flip({
  type nonrec t = PImg.t;
})
include Components.ScrollFactor({
  type nonrec t = PImg.t;
}) 

include Components.Transform({
  type nonrec t = PImg.t;
})