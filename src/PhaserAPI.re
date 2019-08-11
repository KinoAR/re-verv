type phaser;
type game;
type scene;
type rendererType = int;


[@bs.get] external rendererAuto: phaser => rendererType = "AUTO";
[@bs.get] external rendererCanvas: phaser => rendererType = "CANVAS";
[@bs.get] external rendererHeadless: phaser => rendererType = "HEADLESS";
[@bs.get] external rendererWebGL: phaser => rendererType = "WEBGL";

let auto = phaser => phaser -> rendererAuto;
let canvas = phaser => phaser -> rendererCanvas;
let headless = phaser => phaser -> rendererHeadless;
let webgl = phaser => phaser -> rendererWebGL;

[@bs.deriving abstract]
type gameConfig = {
  [@bs.as "type"] type_: rendererType,
  parent: string,
  width:int,
  height: int,
  [@bs.optional] scene: scene,
};

[@bs.module] external phaser: phaser = "phaser"; 

module Game {
  type t = game;
  [@bs.module "phaser"][@bs.new] external make: (gameConfig) => t = "Game";
};


let test = phaser;
let game = Game.make(gameConfig(~type_=(phaser -> auto), ~parent="test", ~width=800, ~height=600, ()));