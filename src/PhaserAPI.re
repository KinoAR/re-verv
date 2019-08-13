

type phaser;
type game;
type scene = {
  init: unit => unit,
  preload: unit => unit,
  create: unit => unit,
};
type map;
type mapAdd;


type rendererType = int;
type blendModes;

[@bs.get] external rendererAuto: phaser => rendererType = "AUTO";
[@bs.get] external rendererCanvas: phaser => rendererType = "CANVAS";
[@bs.get] external rendererHeadless: phaser => rendererType = "HEADLESS";
[@bs.get] external rendererWebGL: phaser => rendererType = "WEBGL";
[@bs.get] external blendModes: phaser => blendModes = "BLENDMODES";




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




[@bs.deriving abstract]
type packFileConfig;

[@bs.deriving abstract]
type physicsConfig;

[@bs.deriving abstract]
type loaderConfig;



[@bs.deriving abstract]
type sceneTransitionConfig = {
  target:string,
  duration:int,
  sleep:bool,
  allowInput:bool,
  moveAbove:bool,
  bmoveBelow:bool,
  onUpdate: unit => unit,
  onUpdateScope: Utils.any,
  data: Utils.any
};

[@bs.deriving abstract]
type sceneConfig = {
  [@bs.optional] key:string,
  [@bs.optional] active:bool,
  [@bs.optional] visible:bool,
  [@bs.optional] pack:bool,
  [@bs.optional] physics: physicsConfig,
  [@bs.optional] loader: loaderConfig,
  [@bs.optional] plugins: bool,
};

[@bs.deriving abstract]
type sceneSettings = {
  status: int,
  key:string,
  active:bool,
  visible:bool,
  isBooted:bool,
  isTransition:bool,
  [@bs.optional] transitionFrom:scene,
  transitionDuration: int,
  transitionAllowInput:bool,
  /*data:Js.t(<..>), */
  pack: packFileConfig,
  physics: physicsConfig,
  loader: loaderConfig,
  plugins: bool
};



[@bs.module] external phaser: phaser = "phaser"; 

module Game {
  type t = game;
  [@bs.module "phaser"][@bs.new] external make: (gameConfig) => t = "Game";
};

module Scene {
  type t = scene;
  [@bs.module "phaser"][@bs.new] external make: (sceneConfig) => t = "Scene";
}

module BlendModes {
  type t = blendModes;
  [@bs.get] external add: blendModes => int = "ADD";
  [@bs.get] external burn: blendModes => int = "BURN";
  [@bs.get] external color: blendModes => int = "COLOR";
  [@bs.get] external colorBurn: blendModes => int = "COLOR_BURN";
  [@bs.get] external colorDodge: blendModes => int = "COLOR_DODGE";
  [@bs.get] external copy: blendModes => int = "COPY";
  [@bs.get] external lighten: blendModes => int = "LIGHTEN";
  [@bs.get] external darken: blendModes => int = "DARKEN";
  [@bs.get] external lighter: blendModes => int = "LIGHTER";
  [@bs.get] external exclusion: blendModes => int = "EXCLUSION";
  [@bs.get] external multiply: blendModes => int = "MULTIPLY";
  [@bs.get] external erase: blendModes => int = "ERASE";
  [@bs.get] external difference: blendModes => int = "DIFFERENCE";
  [@bs.get] external destinationOnOver: blendModes => int = "DESTINATION_OVER";
  [@bs.get] external destinationAtop: blendModes => int = "DESTINATION_ATOP";
  [@bs.get] external destinationIn: blendModes => int = "DESTINATION_IN";
  [@bs.get] external destinationOut: blendModes => int = "DESTINATION_OUT";
  [@bs.get] external hue: blendModes => int = "HUE";
  [@bs.get] external screen: blendModes => int = "SCREEN";
  [@bs.get] external normal: blendModes => int = "NORMAL";
  [@bs.get] external overlay: blendModes => int = "OVERLAY";
  [@bs.get] external luminosity: blendModes => int = "LUMINOSITY";
  [@bs.get] external softLight: blendModes => int = "SOFT_LIGHT";
  [@bs.get] external skipCheck: blendModes => int = "SKIP_CHECK";
  [@bs.get] external saturation: blendModes => int = "SATURATION";
  [@bs.get] external hardLight: blendModes => int = "HARD_LIGHT";
  [@bs.get] external sourceOut: blendModes => int = "SOURCE_OUT";
  [@bs.get] external sourceIn: blendModes => int = "SOURCE_IN";
  [@bs.get] external sourceAtop: blendModes => int = "SOURCE_ATOP";
  [@bs.get] external xor: blendModes => int = "XOR";
};


let test = phaser;
let game = Game.make(gameConfig(~type_=(phaser -> auto), ~parent="test", ~width=800, ~height=600, ()));