// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");
var Verv$ReVerv = require("./Verv.bs.js");

var sceneCreate = Verv$ReVerv.dataCallback((function (scene, param) {
        var text = scene.add.text(64, 200, "Hello World");
        return text.setColor("white");
      }));

var titleScene = Verv$ReVerv.createScene("title", undefined, undefined, Caml_option.some(sceneCreate), undefined, /* () */0);

var game = Verv$ReVerv.createGame(Verv$ReVerv.auto, "phaser-example", 800, 600, titleScene);

exports.sceneCreate = sceneCreate;
exports.titleScene = titleScene;
exports.game = game;
/* sceneCreate Not a pure module */
