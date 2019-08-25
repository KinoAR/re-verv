// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Phaser = require("phaser");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var Text$ReVerv = require("./Text.bs.js");

var phaser = Phaser;

var auto = phaser.AUTO;

var canvas = phaser.CANVAS;

var headless = phaser.HEADLESS;

var webgl = phaser.WEBGL;

function createGame(renderer, parent, width, height, scene) {
  return new Phaser.Game({
              type: renderer,
              parent: parent,
              width: width,
              height: height,
              scene: scene
            });
}

function zeroCallback(fn) {
  return (function () {
      var $$this = this ;
      Curry._1(fn, $$this);
      return /* () */0;
    });
}

function dataCallback(fn) {
  return (function (data) {
      var scene = this ;
      Curry._2(fn, scene, data);
      return /* () */0;
    });
}

function createScene(key, init, preload, create, update, param) {
  var scene = new Phaser.Scene({
        key: key
      });
  if (init !== undefined) {
    scene.init = Caml_option.valFromOption(init);
  }
  if (create !== undefined) {
    scene.create = Caml_option.valFromOption(create);
  }
  if (preload !== undefined) {
    scene.preload = preload;
  }
  if (update !== undefined) {
    scene.update(Curry._1(update, scene));
  }
  return scene;
}

function MakeLoader(S) {
  var scene = S[/* scene */0];
  var loader = scene.load;
  var keyExists = function (keyName) {
    return scene.load.keyExists(keyName);
  };
  var loadImage = function (imageName, url) {
    scene.load.image({
          key: imageName,
          url: url
        });
    return /* () */0;
  };
  var loadAudio = function (audioName, urls) {
    scene.load.audio({
          key: audioName,
          url: urls
        });
    return /* () */0;
  };
  var loadCSS = function (cssName, url) {
    scene.load.css({
          key: cssName,
          url: url
        });
    return /* () */0;
  };
  return /* module */[
          /* scene */scene,
          /* loader */loader,
          /* keyExists */keyExists,
          /* loadImage */loadImage,
          /* loadAudio */loadAudio,
          /* loadCSS */loadCSS
        ];
}

function MakeGameObjFactory(A) {
  var scene = A[/* scene */0];
  var factory = scene.add;
  var addImage = function (x, y, texture, frame, param) {
    var image = frame !== undefined ? factory.image(x, y, texture, frame) : factory.image(x, y, texture, undefined);
    return /* Container */[image];
  };
  var addSprite = function (x, y, texture, frame, param) {
    var sprite = frame !== undefined ? factory.sprite(x, y, texture, frame) : factory.sprite(x, y, texture, undefined);
    return /* Container */[sprite];
  };
  var addBlitter = function (x, y, key, frame, param) {
    var blitter = frame !== undefined ? factory.blitter(x, y, key, frame) : factory.blitter(x, y, key, undefined);
    return /* Container */[blitter];
  };
  var addPathInt = function (x, y) {
    return /* Container */[factory.path(x, y)];
  };
  var addPathF = function (x, y) {
    return /* Container */[factory.path(x, y)];
  };
  var addText = function (x, y, text, color) {
    var text$1 = factory.text(x, y, text);
    return Text$ReVerv.setColor(color, /* Container */[text$1]);
  };
  var addBitmapText = function (x, y, font, text) {
    var bitmapText = factory.bitmapText(x, y, font, text, undefined, undefined);
    return /* Container */[bitmapText];
  };
  var addZone = function (x, y, width, height) {
    var zone = factory.zone(x, y, width, height);
    return /* Container */[zone];
  };
  return /* module */[
          /* scene */scene,
          /* factory */factory,
          /* addImage */addImage,
          /* addSprite */addSprite,
          /* addBlitter */addBlitter,
          /* addPathInt */addPathInt,
          /* addPathF */addPathF,
          /* addText */addText,
          /* addBitmapText */addBitmapText,
          /* addZone */addZone
        ];
}

var Vector2 = 0;

var $$Image = 0;

var Input = 0;

var Tween = 0;

var $$Text = 0;

var BitMapText = 0;

var Shape = 0;

exports.phaser = phaser;
exports.auto = auto;
exports.canvas = canvas;
exports.headless = headless;
exports.webgl = webgl;
exports.createGame = createGame;
exports.zeroCallback = zeroCallback;
exports.dataCallback = dataCallback;
exports.createScene = createScene;
exports.Vector2 = Vector2;
exports.$$Image = $$Image;
exports.Input = Input;
exports.Tween = Tween;
exports.$$Text = $$Text;
exports.BitMapText = BitMapText;
exports.Shape = Shape;
exports.MakeLoader = MakeLoader;
exports.MakeGameObjFactory = MakeGameObjFactory;
/* phaser Not a pure module */
