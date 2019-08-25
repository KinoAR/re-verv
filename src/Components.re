open PhaserAPI;
open VBase;


module BaseGameObject = (G:{type t}) => {
  module PBaseGO = GameObjects.BaseGameObject({type nonrec t = G.t});
  let makeBase =  (scene, name) => Container(PBaseGO.makeBase(scene, name));
  let active = container => container |> flatMap(PBaseGO.active);
  let cameraFilter = container => container |> flatMap(PBaseGO.cameraFilter);
  let type_ = container => container |> flatMap(PBaseGO.type_);
  let tabIndex = container => container |> flatMap(PBaseGO.tabIndex);
  let state = container => container |> flatMap(PBaseGO.state);
  let stateInt = container => container |> flatMap(PBaseGO.stateInt);
  let name = container => container |> flatMap(PBaseGO.name);
  let scene = container => container |> flatMap(PBaseGO.scene);
  let data = container => container |> flatMap(PBaseGO.data);
  let arcadeBody = container => container |> flatMap(PBaseGO.arcadeBody);
  let impactBody = container => container |> flatMap(PBaseGO.impactBody);
  let matterBody = container => container |> flatMap(PBaseGO.matterBody);
  let renderMask = container => container |> flatMap(PBaseGO.renderMask);
  let renderFlags = container => container |> flatMap(PBaseGO.renderFlags);
  let parentContainer = container => container |> flatMap(PBaseGO.parentContainer);
  let ignoreDestroy = container => container |> flatMap(PBaseGO.ignoreDestroy);

  let getIndexList = container => container |> flatMap(PBaseGO.getIndexList);
  let getData = container => container |> flatMap(PBaseGO.getData);
  let removeInteractive = container => container |> map(PBaseGO.removeInteractive);
  let setName = (name, container) => container |> map(PBaseGO.setName(_, name));
  let setData = (data, container) => container |> map(PBaseGO.setData(_, data));
  let willRender = (camera2D, container) => container |> flatMap(PBaseGO.willRender(_, camera2D));
  let setState = (state, container) => container |> map(PBaseGO.setState(_, state));
  let setActive = (active, container) => container |> map(PBaseGO.setActive(_, active));
  let setDataEnabled = container => container |> map(PBaseGO.setDataEnabled);
};

module Alpha = (A:{type t;}) => {
  module PAlpha = GameObjects.Components.Alpha({type nonrec t = A.t});

  let alpha = container => container |> flatMap(PAlpha.alpha);
  let alphaF = container => container |> flatMap(PAlpha.alphaF);
  let alphaTopLeft = container => container |> flatMap(PAlpha.alphaTopLeft);
  let alphaTopLeftF = container => container |> flatMap(PAlpha.alphaTopLeftF);
  let alphaTopRight = container => container |> flatMap(PAlpha.alphaTopRight);
  let alphaTopRightF = container => container |> flatMap(PAlpha.alphaTopRightF);
  let alphaBottomLeft = container => container |> flatMap(PAlpha.alphaBottomLeft);
  let alphaBottomLeftF = container => container |> flatMap(PAlpha.alphaBottomLeftF);
  let alphaBottomRight = container => container |> flatMap(PAlpha.alphaBottomRight);
  let alphaBottomRightF = container => container |> flatMap(PAlpha.alphaBottomRightF)
  let clearAlpha = container => container |> map(PAlpha.clearAlpha);

  let setAlpha = (~topLeft=?, ~topRight=?, ~bottomLeft=?, ~bottomRight=?, container) => {
    let alphas = (topLeft, topRight, bottomLeft, bottomRight);
    let fn = PAlpha.setAllAlpha;
    switch(alphas) {
        | (Some(topLeft), Some(topRight),Some(bottomLeft), Some(bottomRight)) => container |> map(fn(_, ~topLeft, ~topRight, ~bottomLeft, ~bottomRight, ()));
        | (None, Some(topRight), Some(bottomLeft), Some(bottomRight)) => container |> map(fn(_, ~topRight, ~bottomLeft,~bottomRight, ()));
        | (None, None, Some(bottomLeft), Some(bottomRight)) => container |> map(fn(_, ~bottomLeft,~bottomRight, ()));
        | (None, None, None, Some(bottomRight)) => container |> map(fn(_, ~bottomRight, ()));
        | (None, Some(topRight), None, Some(bottomRight)) => container |> map(fn(_, ~topRight, ~bottomRight, ()));
        | (None, Some(topRight), None, None) => container |> map(fn(_, ~topRight, ()));
        | (None, Some(topRight), Some(bottomLeft), None) => container |> map(fn(_,~topRight, ~bottomLeft, ()));
        | (None, None, Some(bottomLeft), None) => container |> map(fn(_, ~bottomLeft, ()));
        | (Some(topLeft), None, None, None) => container |> map(fn(_, ~topLeft, ()));
        | (Some(topLeft), None, Some(bottomLeft), None) => container |> map(fn(_,~topLeft, ~bottomLeft, ()));
        | (Some(topLeft), Some(topRight), None, None) => container |> map(fn(_, ~topLeft, ~topRight, ()));
        | (Some(topLeft), Some(topRight), None, Some(bottomRight)) => container |> map(fn(_, ~topLeft, ~topRight, ~bottomRight, ()));
        | (Some(topLeft), Some(topRight), Some(bottomLeft), None) => container |> map(fn(_, ~topLeft, ~topRight, ~bottomLeft, ()));
        | (Some(topLeft), None, Some(bottomLeft), Some(bottomRight)) => container |> map(fn(_, ~topLeft, ~bottomLeft, ~bottomRight, ()));
        | (Some(topLeft), None, None, Some(bottomRight)) => container |> map(fn(_, ~topLeft, ~bottomRight, ()));
        | (None, None, None, None) => container |> map(fn(_, ()));
      };
  };
}

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

  module Depth = (D:{type t;}) => {
     module PDepth = GameObjects.Components.Depth({type nonrec t = D.t});

     let depth = container => container |> flatMap(PDepth.depth);
     let depthF = container => container |> flatMap(PDepth.depthF);

     let setDepth = (depth, container) => container |> map(PDepth.setDepth(_, depth));
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
  module ComputedSize = (CS:{type t;}) => {
    module CS = GameObjects.Components.ComputedSize({type nonrec t = CS.t});
    let displayHeight = container => container |> flatMap(CS.displayHeight);
    let displayHeightF = container => container |> flatMap(CS.displayHeightF);
    let displayWidth = container => container |> flatMap(CS.displayWidth);
    let displayWidthF = container => container |> flatMap(CS.displayWidthF);
    let height = container => container |> flatMap(CS.height);
    let heightF = container => container |> flatMap(CS.heightF);
    let width = container => container |> flatMap(CS.width);
    let widthF = container => container |> flatMap(CS.widthF);


    let setSize = (~width, ~height, container) => container |> map(CS.setSize(_, ~width, ~height));
    let setSizeF = (~width, ~height, container) => container |> map(CS.setSizeF(_, ~width, ~height));
    let setDisplaySize = (~width, ~height, container) => container |> map(CS.setDisplaySize(_, ~width, ~height));
    let setDisplaySizeF = (~width, ~height, container) => container |> map(CS.setDisplaySizeF(_, ~width, ~height));    
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

  module GetBounds = (G:{type t;}) => {
    module PGB = GameObjects.Components.GetBounds({type nonrec t = G.t});

  }