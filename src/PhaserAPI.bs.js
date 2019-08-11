// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Phaser = require("phaser");

function auto(phaser) {
  return phaser.AUTO;
}

function canvas(phaser) {
  return phaser.CANVAS;
}

function headless(phaser) {
  return phaser.HEADLESS;
}

function webgl(phaser) {
  return phaser.WEBGL;
}

var Game = /* module */[];

var test = Phaser;

var game = new Phaser.Game({
      type: Phaser.AUTO,
      parent: "test",
      width: 800,
      height: 600
    });

exports.auto = auto;
exports.canvas = canvas;
exports.headless = headless;
exports.webgl = webgl;
exports.Game = Game;
exports.test = test;
exports.game = game;
/* test Not a pure module */
