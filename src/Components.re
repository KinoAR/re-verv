open PhaserAPI;
open VBase;

module BlendMode = (B:{type t;}) => {
    module B = GameObjects.Components.BlendMode({type nonrec t = B.t});
    
    let blendMode = container => container |> flatMap(B.blendMode);
    let blendModeStr = container => container |> flatMap(B.blendModeStr);
    let setBlendModeStr = container => container |> map(B.setBlendModeStr);
    let setBlendMode = container => container |> map(B.setBlendMode(_));
  }; 
  module ScrollFactor = (SF:{type t;}) => {
    module ScF = GameObjects.Components.ScrollFactor({type nonrec t = SF.t;});

    let setScrollFactor = (~x, ~y=?, container) => switch(y) {
      | Some(y) => container |> map(ScF.setScrollFactor(_, ~x, ~y, ()));
      | None =>  container |> map(ScF.setScrollFactor(_, ~x, ()));
    };

    let scrollFactorX = (container) => container |> flatMap(ScF.scrollFactorX);
    let scrollFactorXF = (container) => container |> flatMap(ScF.scrollFactorXF);
    let scrollFactorY = (container) => container |> flatMap(ScF.scrollFactorY); 
    let scrollFactorYF = (container) => container |> flatMap(ScF.scrollFactorYF);

  };

  module Transform = (T:{type t;}) => {
    module T = GameObjects.Components.Transform({type nonrec t = T.t});

    let angle = (container) => container |> flatMap(T.angle);
    let angleF = (container) => container |> flatMap(T.angleF)
    let rotation = container => container |> flatMap(T.rotation);
    let rotationF = container => container |> flatMap(T.rotationF);
    let scale = container => container |> flatMap(T.scale);
    let scaleF = container => container |> flatMap(T.scaleF);
    let scaleX = container => container |> flatMap(T.scaleX);
    let scaleXF = container => container |> flatMap(T.scaleXF);
    let scaleY = container => container |> flatMap(T.scaleY);
    let scaleYF = container => container |> flatMap(T.scaleYF);
  
    let w = container => container |> flatMap(T.w);
    let x = (container) => container |> flatMap(T.x);
    let y = container => container |> flatMap(T.y);
    let z = container => container |> flatMap(T.z);
    let setX = (x, container) => container |> map(T.setX(_, x));
    let setY = (y, container) => container |> map(T.setY(_, y));
    let setW = (w, container) => container |> map(T.setW(_, w));
    let setZ = (z, container) => container |> map(T.setZ(_, z));
    let setScale =  (~x, ~y=?, container) => switch(y) {
      | Some(y) => container |> map(T.setScale(_, ~x, ~y, ()));
      | None => container |> map(T.setScale(_, ~x, ()));
    };
    let setPosition = (~x=0, ~y=?, ~z=0, ~w=0, container) => switch(y) {
      | Some(y) => container |> map(T.setPosition(_, ~x, ~y, ~z, ~w, ()))
      | None => container |> map(T.setPosition(_, ~x, ~y=x, ~z, ~w, ()))
    };
    let setRotation = (~radians=0, container) => container |> map(T.setRotation(_, radians))
    let setRotationF = (~radians=0.0, container) => container |> map(T.setRotationF(_, radians))

    let getParentRotation = container => container |> flatMap(T.getParentRotation);
    let getParentRotationF = container => container |> flatMap(T.getParentRotationF);
  };

  module Visible = (V:{type t;}) => {
    module V = GameObjects.Components.Visible({type nonrec t = V.t});

    let visible = container => container |> flatMap(V.visible);
    let setVisible = container => container |> map(V.setVisible);
  };

  module Origin = (O:{type t;}) => {
    module O = GameObjects.Components.Origin({type nonrec t = O.t});

    let displayOriginX = container => container |> flatMap(O.displayOriginX);
    let displayOriginY = container => container |> flatMap(O.displayOriginY);

    let originX = container => container |> flatMap(O.originX);
    let originY = container => container |> flatMap(O.originY);
    let setDisplayOrigin = (~x=0.0, ~y=?, container) => switch(y) {
      | Some(y) => container |> map(O.setDisplayOrigin(_, ~x, ~y, ()));
      | None => container |> map(O.setDisplayOrigin(_, ~x, ~y=x, ()));
    };
    let setOrigin = (~x=0.5, ~y=?, container) => switch(y) {
      | Some(y) => container |> map(O.setOrigin(_, ~x, ~y, ()));
      | None => container |>map(O.setOrigin(_, ~x, ~y=x, ()));
    };

    let setOriginFromFrame = container => container |> map(O.setOriginFromFrame);
    let updateDisplayOrigin = container => container |> map(O.updateDisplayOrigin);
  };

  module Size = (S:{type t;}) => {
    module S = GameObjects.Components.Size({type nonrec t = S.t});

    let displayHeight = container => container |> flatMap(S.displayHeight);
    let displayHeightF = container => container |> flatMap(S.displayHeightF);
    let displayWidth = container => container |> flatMap(S.displayWidth);
    let displayWidthF = container => container |> flatMap(S.displayWidthF);
    let height = container => container |> flatMap(S.height);
    let heightF = container => container |> flatMap(S.heightF);
    let width = container => container |> flatMap(S.width);
    let widthF = container => container |> flatMap(S.widthF);


    let setSize = (~width, ~height, container) => container |> map(S.setSize(_, ~width, ~height));
    let setSizeF = (~width, ~height, container) => container |> map(S.setSizeF(_, ~width, ~height));
    let setDisplaySize = (~width, ~height, container) => container |> map(S.setDisplaySize(_, ~width, ~height));
    let setDisplaySizeF = (~width, ~height, container) => container |> map(S.setDisplaySizeF(_, ~width, ~height));
    let setSizeToFrame = (~frame, container) => container |> map(S.setSizeToFrame(_, ~frame));
  };

  module Tint = (T:{type t;}) => {
    module PTint = GameObjects.Components.Tint({type nonrec t = T.t});

    let isTinted = container => container |> flatMap(PTint.isTinted);
    let tint = container => container |> flatMap(PTint.tint);
    let tintBottomLeft = container => container |> flatMap(PTint.tintBottomLeft);
    let tintBottomRight = container => container |> flatMap(PTint.tintBottomRight);
    let tintFill = container => container |> flatMap(PTint.tintFill);
    let tintTopLeft = container => container |> flatMap(PTint.tintTopLeft);
    let tintTopRight = container => container |> flatMap(PTint.tintTopRight);

    let clearTint = container => container |> map(PTint.clearTint);
    let setTintFill = (~topLeft=?, ~topRight=?, ~bottomLeft=?, ~bottomRight=?, container) => {
      let fills = (topLeft, topRight, bottomLeft, bottomRight);

      switch(fills) {
        | (Some(topLeft), Some(topRight),Some(bottomLeft), Some(bottomRight)) => container |> map(PTint.setTintFill(_, ~topLeft, ~topRight, ~bottomLeft, ~bottomRight, ()));
        | (None, Some(topRight), Some(bottomLeft), Some(bottomRight)) => container |> map(PTint.setTintFill(_, ~topRight, ~bottomLeft,~bottomRight, ()));
        | (None, None, Some(bottomLeft), Some(bottomRight)) => container |> map(PTint.setTintFill(_, ~bottomLeft,~bottomRight, ()));
        | (None, None, None, Some(bottomRight)) => container |> map(PTint.setTintFill(_, ~bottomRight, ()));
        | (None, Some(topRight), None, Some(bottomRight)) => container |> map(PTint.setTintFill(_, ~topRight, ~bottomRight, ()));
        | (None, Some(topRight), None, None) => container |> map(PTint.setTintFill(_, ~topRight, ()));
        | (None, Some(topRight), Some(bottomLeft), None) => container |> map(PTint.setTintFill(_,~topRight, ~bottomLeft, ()));
        | (None, None, Some(bottomLeft), None) => container |> map(PTint.setTintFill(_, ~bottomLeft, ()));
        | (Some(topLeft), None, None, None) => container |> map(PTint.setTintFill(_, ~topLeft, ()));
        | (Some(topLeft), None, Some(bottomLeft), None) => container |> map(PTint.setTintFill(_,~topLeft, ~bottomLeft, ()));
        | (Some(topLeft), Some(topRight), None, None) => container |> map(PTint.setTintFill(_, ~topLeft, ~topRight, ()));
        | (Some(topLeft), Some(topRight), None, Some(bottomRight)) => container |> map(PTint.setTintFill(_, ~topLeft, ~topRight, ~bottomRight, ()));
        | (Some(topLeft), Some(topRight), Some(bottomLeft), None) => container |> map(PTint.setTintFill(_, ~topLeft, ~topRight, ~bottomLeft, ()));
        | (Some(topLeft), None, Some(bottomLeft), Some(bottomRight)) => container |> map(PTint.setTintFill(_, ~topLeft, ~bottomLeft, ~bottomRight, ()));
        | (Some(topLeft), None, None, Some(bottomRight)) => container |> map(PTint.setTintFill(_, ~topLeft, ~bottomRight, ()));
        | (None, None, None, None) => container |> map(PTint.setTintFill(_, ()));
      };
    }

    let setTint = (~topLeft=?, ~topRight=?, ~bottomLeft=?, ~bottomRight=?, container) => {
      let fills = (topLeft, topRight, bottomLeft, bottomRight);

      switch(fills) {
        | (Some(topLeft), Some(topRight),Some(bottomLeft), Some(bottomRight)) => container |> map(PTint.setTint(_, ~topLeft, ~topRight, ~bottomLeft, ~bottomRight, ()));
        | (None, Some(topRight), Some(bottomLeft), Some(bottomRight)) => container |> map(PTint.setTint(_, ~topRight, ~bottomLeft,~bottomRight, ()));
        | (None, None, Some(bottomLeft), Some(bottomRight)) => container |> map(PTint.setTint(_, ~bottomLeft,~bottomRight, ()));
        | (None, None, None, Some(bottomRight)) => container |> map(PTint.setTint(_, ~bottomRight, ()));
        | (None, Some(topRight), None, Some(bottomRight)) => container |> map(PTint.setTint(_, ~topRight, ~bottomRight, ()));
        | (None, Some(topRight), None, None) => container |> map(PTint.setTint(_, ~topRight, ()));
        | (None, Some(topRight), Some(bottomLeft), None) => container |> map(PTint.setTint(_,~topRight, ~bottomLeft, ()));
        | (None, None, Some(bottomLeft), None) => container |> map(PTint.setTint(_, ~bottomLeft, ()));
        | (Some(topLeft), None, None, None) => container |> map(PTint.setTint(_, ~topLeft, ()));
        | (Some(topLeft), None, Some(bottomLeft), None) => container |> map(PTint.setTint(_,~topLeft, ~bottomLeft, ()));
        | (Some(topLeft), Some(topRight), None, None) => container |> map(PTint.setTint(_, ~topLeft, ~topRight, ()));
        | (Some(topLeft), Some(topRight), None, Some(bottomRight)) => container |> map(PTint.setTint(_, ~topLeft, ~topRight, ~bottomRight, ()));
        | (Some(topLeft), Some(topRight), Some(bottomLeft), None) => container |> map(PTint.setTint(_, ~topLeft, ~topRight, ~bottomLeft, ()));
        | (Some(topLeft), None, Some(bottomLeft), Some(bottomRight)) => container |> map(PTint.setTint(_, ~topLeft, ~bottomLeft, ~bottomRight, ()));
        | (Some(topLeft), None, None, Some(bottomRight)) => container |> map(PTint.setTint(_, ~topLeft, ~bottomRight, ()));
        | (None, None, None, None) => container |> map(PTint.setTint(_, ()));
      };
    }
  };

  module Flip = (F:{type t;}) => {
    module F = GameObjects.Components.Flip({type nonrec t = F.t});

    let flipX = container => container |> flatMap(F.flipX);
    let flipY = container => container |> flatMap(F.flipY);
    
    let resetFlip = container => container |> flatMap(F.resetFlip);
    let setFlip = (x, y, container) => container |> map(F.setFlip(_, x, y));
    let setFlipX = (x, container) => container |> map(F.setFlipX(_, x));
    let setFlipY = (y, container) => container |> map(F.setFlipY(_, y));
    let toggleFlipX = container => container |> map(F.toggleFlipX);
    let toggleFlipY = container => container |> map(F.toggleFlipY);
  };

  module Pipeline = (P:{type t;}) => {
    module PPipeline = GameObjects.Components.Pipeline({type nonrec t = P.t});

    let defaultPipeline = container => container |> flatMap(PPipeline.defaultPipeline);
    let pipeline = container => container |> flatMap(PPipeline.pipeline);

    let getPipelineName = container => container |> flatMap(PPipeline.getPipelineName);
    let resetPipeline = container => container |> flatMap(PPipeline.resetPipeline);
    let initPipeline = (~pipelineName, container) => container |> map(PPipeline.initPipeline(_, ~pipelineName));
    let setPipeline = (~pipelineName=?, container) => switch(pipelineName) {
      | Some(name) => container |> map(PPipeline.setPipeline(_, ~pipelineName=name, ()));
      | None => container |> map(PPipeline.setPipeline(_, ()));
    }
  };