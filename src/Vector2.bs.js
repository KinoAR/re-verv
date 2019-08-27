// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Phaser = require("phaser");
var Tablecloth = require("tablecloth-bucklescript/src/tablecloth.bs.js");

function toPhaserVec2(param) {
  return new (Phaser.Math.Vector2)(param[0], param[1]);
}

function toPhaserVec2F(param) {
  return new (Phaser.Math.Vector2)(param[0], param[1]);
}

function $plus$bang(param, param$1) {
  return /* tuple */[
          param[0] + param$1[0],
          param[1] + param$1[1]
        ];
}

function toIntVector(vector2F) {
  return Tablecloth.Tuple2[/* mapAll */9]((function (prim) {
                return prim | 0;
              }), vector2F);
}

function toFloatVector(vector2F) {
  return Tablecloth.Tuple2[/* mapAll */9]((function (prim) {
                return prim;
              }), vector2F);
}

exports.toPhaserVec2 = toPhaserVec2;
exports.toPhaserVec2F = toPhaserVec2F;
exports.$plus$bang = $plus$bang;
exports.toIntVector = toIntVector;
exports.toFloatVector = toFloatVector;
/* phaser Not a pure module */
