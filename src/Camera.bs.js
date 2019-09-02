// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var VBase$ReVerv = require("./VBase.bs.js");
var Components$ReVerv = require("./Components.bs.js");

var include = Components$ReVerv.Flip(/* module */[]);

var include$1 = Components$ReVerv.Tint(/* module */[]);

function backgroundColor(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.backgroundColor;
              }), param);
}

function cameraManager(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.cameraManager;
              }), param);
}

function id(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.id;
              }), param);
}

function originX(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.originX;
              }), param);
}

function originY(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.originY;
              }), param);
}

function useBounds(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.useBounds;
              }), param);
}

function width(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.width;
              }), param);
}

function widthF(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.width;
              }), param);
}

function height(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.height;
              }), param);
}

function heightF(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.height;
              }), param);
}

function zoom(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.zoom;
              }), param);
}

function scrollX(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.scrollX;
              }), param);
}

function scrollXF(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.scrollX;
              }), param);
}

function scrollY(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.scrollY;
              }), param);
}

function scrollYF(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.scrollY;
              }), param);
}

function name(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.name;
              }), param);
}

function roundPixels(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.roundPixels;
              }), param);
}

function centerX(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.centerX;
              }), param);
}

function transparent(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.transparent;
              }), param);
}

function mask(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.mask;
              }), param);
}

function geometryMask(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.mask;
              }), param);
}

function midPoint(param) {
  return VBase$ReVerv.flatMap((function (prim) {
                return prim.midPoint;
              }), param);
}

function centerOn(x, y) {
  return (function (param) {
      return VBase$ReVerv.map((function (__x) {
                    return __x.centerOn(x, y);
                  }), param);
    });
}

function centerOnF(x, y) {
  return (function (param) {
      return VBase$ReVerv.map((function (__x) {
                    return __x.centerOn(x, y);
                  }), param);
    });
}

function centeronX(x) {
  return (function (param) {
      return VBase$ReVerv.map((function (__x) {
                    return __x.centerOnX(x);
                  }), param);
    });
}

function centerOnXF(x) {
  return (function (param) {
      return VBase$ReVerv.map((function (__x) {
                    return __x.centerOnX(x);
                  }), param);
    });
}

function centerOnY(y) {
  return (function (param) {
      return VBase$ReVerv.map((function (__x) {
                    return __x.centerOnY(y);
                  }), param);
    });
}

function centerOnYF(y) {
  return (function (param) {
      return VBase$ReVerv.map((function (__x) {
                    return __x.centerOnY(y);
                  }), param);
    });
}

function centerToBounds(param) {
  return VBase$ReVerv.map((function (prim) {
                return prim.centerToBounds();
              }), param);
}

function centerToSize(param) {
  return VBase$ReVerv.map((function (prim) {
                return prim.centerToSize();
              }), param);
}

var Camera2D_001 = /* F */include[0];

var Camera2D_002 = /* flipX */include[1];

var Camera2D_003 = /* flipY */include[2];

var Camera2D_004 = /* resetFlip */include[3];

var Camera2D_005 = /* setFlip */include[4];

var Camera2D_006 = /* setFlipX */include[5];

var Camera2D_007 = /* setFlipY */include[6];

var Camera2D_008 = /* toggleFlipX */include[7];

var Camera2D_009 = /* toggleFlipY */include[8];

var Camera2D_010 = /* PTint */include$1[0];

var Camera2D_011 = /* isTinted */include$1[1];

var Camera2D_012 = /* tint */include$1[2];

var Camera2D_013 = /* tintBottomLeft */include$1[3];

var Camera2D_014 = /* tintBottomRight */include$1[4];

var Camera2D_015 = /* tintFill */include$1[5];

var Camera2D_016 = /* tintTopLeft */include$1[6];

var Camera2D_017 = /* tintTopRight */include$1[7];

var Camera2D_018 = /* clearTint */include$1[8];

var Camera2D_019 = /* setTintFill */include$1[9];

var Camera2D_020 = /* setTint */include$1[10];

var Camera2D = /* module */[
  /* PCamera2D */0,
  Camera2D_001,
  Camera2D_002,
  Camera2D_003,
  Camera2D_004,
  Camera2D_005,
  Camera2D_006,
  Camera2D_007,
  Camera2D_008,
  Camera2D_009,
  Camera2D_010,
  Camera2D_011,
  Camera2D_012,
  Camera2D_013,
  Camera2D_014,
  Camera2D_015,
  Camera2D_016,
  Camera2D_017,
  Camera2D_018,
  Camera2D_019,
  Camera2D_020,
  /* backgroundColor */backgroundColor,
  /* cameraManager */cameraManager,
  /* id */id,
  /* originX */originX,
  /* originY */originY,
  /* useBounds */useBounds,
  /* width */width,
  /* widthF */widthF,
  /* height */height,
  /* heightF */heightF,
  /* zoom */zoom,
  /* scrollX */scrollX,
  /* scrollXF */scrollXF,
  /* scrollY */scrollY,
  /* scrollYF */scrollYF,
  /* name */name,
  /* roundPixels */roundPixels,
  /* centerX */centerX,
  /* transparent */transparent,
  /* mask */mask,
  /* geometryMask */geometryMask,
  /* midPoint */midPoint,
  /* centerOn */centerOn,
  /* centerOnF */centerOnF,
  /* centeronX */centeronX,
  /* centerOnXF */centerOnXF,
  /* centerOnY */centerOnY,
  /* centerOnYF */centerOnYF,
  /* centerToBounds */centerToBounds,
  /* centerToSize */centerToSize
];

exports.Camera2D = Camera2D;
/* include Not a pure module */
