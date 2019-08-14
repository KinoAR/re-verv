

type phaser;
type game;
type systems;
type clock;
type time = float;
type delta = float;
type phaserDom;




type scaleManager;
type dataManager;
type textureManager;
type tweenManager;
type baseSoundManager;
type pluginManager;


type inputPlugin;
type loaderPlugin;
type gameObjectCreator;



[@bs.obj] external anyData: (
  ~name:string,
  ~data: Js.t({..}),
  unit
) =>  _ = "";

/* init, create need to have a data "object" */
[@bs.deriving abstract]
type scene = {
  [@bs.optional] init: unit => unit,
  [@bs.optional] preload: unit => unit,
  [@bs.optional] create: unit => unit,
  [@bs.optional] update: (time, delta) => unit,
  [@bs.optional] extend: Utils.any
};
type map;
type mapAdd;



type rendererType = int;
type audioContext;
type centerType;
type blendModes;
type scaleModes;


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
type fpsConfig = {
  [@bs.optional] min: int,
  [@bs.optional] target: int,
  [@bs.optional] forceSetTimeOut: bool,
  [@bs.optional] deltaHistory: int,
  [@bs.optional] panicMax: int,
};

type inputConfig;

[@bs.deriving abstract]
type imagesConfig = {
  [@bs.optional] default: string,
  [@bs.optional] missing: string
};

[@bs.deriving abstract]
type gamePadInputConfig = {
  [@bs.optional] target: Utils.any,
};

[@bs.deriving abstract]
type mouseInputConfig = {
  [@bs.optional] target: Utils.any,
  [@bs.optional] capture: bool
};

[@bs.deriving abstract] 
type keyboardInputConfig = {
  [@bs.optional] target: Utils.any,
  [@bs.optional] capture: bool
};
[@bs.deriving abstract]
type audioConfig = {
  [@bs.optional] disableWebAudio: bool,
  [@bs.optional] context: audioContext,
  [@bs.optional] noAudio: bool,
};

[@bs.deriving abstract]
type bannerConfig = {
  [@bs.optional] hidePhaser: bool,
  [@bs.optional] text: string,
  [@bs.optional] background: array(string)
};

[@bs.deriving abstract]
type domContainerConfig = {
  [@bs.optional] createContainer: bool,
  [@bs.optional] behindCanvas: bool
};

[@bs.deriving abstract]
type renderConfig = {
  [@bs.optional] antialias: bool,
  [@bs.optional] desynchronized: bool,
  [@bs.optional] pixelArt: bool,
  [@bs.optional] roundPixels: bool,
  [@bs.optional] transparent: bool,
  [@bs.optional] clearBeforeRender: bool,
  [@bs.optional] premultipliedAlpha: bool,
  [@bs.optional] failIfMajorPerformanceCaveat: bool,
  [@bs.optional] powerPreference: string,
  [@bs.optional] batchSize: int,
  [@bs.optional] maxLights: int,
};

[@bs.deriving abstract]
type scaleConfig = {
  [@bs.optional] width: int,
  [@bs.as "width"][@bs.optional] widthAsString: string,
  [@bs.optional] height: int, 
  [@bs.as "height"][@bs.optional] heightAsString: string,
  [@bs.optional] zoom : int,
  [@bs.optional] resolution: int,
  [@bs.optional] parent: string,
  [@bs.optional] expandParent: bool,
  [@bs.optional] mode: scaleModes,
  [@bs.optional] min: int,
  [@bs.optional] max: int,
  [@bs.optional] autoRound: bool,
  [@bs.optional] autoCenter: centerType,
  [@bs.optional] resizeInterval: int,
  [@bs.optional] fullscreenTarget: int,
};



[@bs.deriving abstract]
type packFileConfig;


[@bs.deriving abstract]
type vector2Like = {
  x: int,
  y:int
};

[@bs.deriving abstract]
type arcadeWorldConfig = {
  [@bs.optional] fps: int,
  [@bs.optional] timeScale: int,
  [@bs.optional] gravity: vector2Like,
  [@bs.optional] x: int,
  [@bs.optional] y: int,
  [@bs.optional] width: int,
  [@bs.optional] height: int,
  [@bs.optional] overlapBias: int,
  [@bs.optional] tileBias: int,
  [@bs.optional] forceX: bool,
  [@bs.optional] isPaused: bool,
  [@bs.optional] debug: bool,
  [@bs.optional] debugShowBody: bool,
  [@bs.optional] debugShowStaticBody: bool,
  [@bs.optional] debugShowVelocity: bool,
  [@bs.optional] debugBodyColor: int,
  [@bs.optional] debugStaticBodyColor: int,
  [@bs.optional] debugVelocityColor: int,
  [@bs.optional] maxEntries: int,
  [@bs.optional] useTree: bool
};

type arcadePhysics;

[@bs.deriving abstract]
type boundsConfig = {
  [@bs.optional] x: int,
  [@bs.optional] y: int,
  [@bs.optional] width: int,
  [@bs.optional] height: int,
  [@bs.optional] thickness: int,
  [@bs.optional] left: bool,
  [@bs.optional] right: bool,
  [@bs.optional] top: bool,
  [@bs.optional] bottom: bool,
};

[@bs.deriving abstract]
type impactWorldConfig = {
  [@bs.optional] gravity: int,
  [@bs.optional] cellSize: int,
  [@bs.optional] timeScale: int,
  [@bs.optional] maxStep: float,
  [@bs.optional] debug: bool,
  [@bs.optional] maxVelocity: int,
  [@bs.optional] debugShowBody: bool,
  [@bs.optional] debugShowVelocity: bool,
  [@bs.optional] debugVelocityColor: int,
  [@bs.optional] debugBodyColor: int,
  [@bs.optional] maxVelocityX: int,
  [@bs.optional] maxVelocityY: int,
  [@bs.optional] minBounceVelocity: int,
  [@bs.optional] gravityFactor: int,
  [@bs.optional] bouncies: int,
  [@bs.optional] setBounds: boundsConfig
}; 

type impactPhysics;


[@bs.deriving abstract]
type matterBodyTileOptions = {
  [@bs.optional] isStatic: bool,
  [@bs.optional] addToWorld: bool
};

type matterBody;
[@bs.deriving abstract]
type matterTileOptions = {
  [@bs.optional] body: matterBody,
  [@bs.optional] isStatic: bool,
  [@bs.optional] addToWorld: bool
};

[@bs.deriving abstract]
type matterWorldConfig = {
  [@bs.optional] gravity: vector2Like,
  [@bs.optional] setBounds: boundsConfig,
  [@bs.optional] positionIterations: int,
  [@bs.optional] velocityIterations: int,
  [@bs.optional] constraintIterations: int,
  [@bs.optional] enableSleeping: bool,
  [@bs.as "timing.timestamp"][@bs.optional] timingTimeStamp: int,
  [@bs.as "timing.timescale"][@bs.optional] timingTimeScale: int,
  [@bs.optional] enabled: bool,
  [@bs.optional] correction: int,
  [@bs.optional] getDelta: unit => unit,
  [@bs.optional] autoUpdate: bool,
  [@bs.optional] debug: bool,
  [@bs.optional] debugShowBody: bool,
  [@bs.optional] debugShowStaticBody: bool,
  [@bs.optional] debugShowVelocity: bool,
  [@bs.optional] debugBodyColor: int,
  [@bs.optional] debugBodyFillColor: int,
  [@bs.optional] debugStaticBodyColor: int,
  [@bs.optional] debugVelocityColor: int,
  [@bs.optional] debugShowJoint: bool,
  [@bs.optional] debugJointColor: int,
  [@bs.optional] debugWireframes: bool,
  [@bs.optional] debugShowInternalEdges: bool,
  [@bs.optional] debugShowConvexHulls: bool,
  [@bs.optional] debugShowSleeping: bool
};

type matterPhysics;


[@bs.deriving abstract]
type physicsConfig = {
  [@bs.optional] default:string,
  [@bs.optional] arcade: arcadeWorldConfig,
  [@bs.optional] impact: impactWorldConfig,
  [@bs.optional] matter: matterWorldConfig
};

[@bs.deriving abstract]
type loaderConfig = {
  [@bs.optional] baseURL: string,
  [@bs.optional] path: string,
  [@bs.optional] maxParallelDownloads: int,
  [@bs.optional] crossOriigin: string,
  [@bs.optional] responseType: string,
  [@bs.optional] async: bool,
  [@bs.optional] user: string,
  [@bs.optional] password: string,
  [@bs.optional] timeout: int
};



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



[@bs.deriving abstract]
type gameConfig = {
  [@bs.as "type"] type_: rendererType,
  parent: string,
  width:int,
  height: int,
  [@bs.optional] zoom: int,
  [@bs.optional] resolution: int,
  [@bs.optional] scene: scene,
  [@bs.optional] canvasStyle: string,
  [@bs.optional] seed: array(string),
  [@bs.optional] url:string,
  [@bs.optional] version:string,
  [@bs.optional] autoFocus: bool,
  [@bs.optional] input: inputConfig,
  [@bs.optional] disableContextMenu: bool,
  [@bs.optional] transparent: bool,
  [@bs.optional] fps: fpsConfig,
  [@bs.optional] render: renderConfig,
  [@bs.optional] backgroundColor: string,
  [@bs.optional] loader: loaderConfig,
  [@bs.optional] images: imagesConfig,
  [@bs.optional] physics: physicsConfig,
  [@bs.optional] scale: scaleConfig,
  [@bs.optional] audio: audioConfig,
};


[@bs.module] external phaser: phaser = "phaser"; 

module Game {
  type t = game;
  [@bs.module "phaser"][@bs.new] external make: (gameConfig) => t = "Game";
};

module Scene {
  type t = scene;
  [@bs.module "phaser"][@bs.new] external make: (sceneConfig) => t = "Scene";
  [@bs.get] external game: t => game = "game";
  [@bs.get] external impact: t => impactPhysics = "impact";
  [@bs.get] external matter: t => matterPhysics = "matter";
  [@bs.get] external physics: t => arcadePhysics = "physics";
  [@bs.get] external sys: t => systems = "sys";
  [@bs.get] external textures: t => textureManager = "textures";
  [@bs.get] external time: t => clock = "time";
  [@bs.get] external tweens: t => tweenManager = "tweens";
  [@bs.set] external update: (t, (time, delta)) => unit = "update";
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

module DOM = {
  type t = phaserDom;
  [@bs.send] external addToDom:  (t,Dom.htmlElement, string) => Dom.htmlElement = "AddToDOM";
  [@bs.send] external domContentLoaded: (t, unit => unit) => unit = "DOMContentLoaded";
  [@bs.send] external getInnerHeight: (t, bool) => int = "GetInnerHeight";
  [@bs.send] external getScreenOrientation: (t, int, int) => string = "GetScreenOrientation";
  [@bs.send] external getTarget: (t, Dom.htmlElement) => Dom.htmlElement = "GetTarget";
  [@bs.send] external parseXML: (t, string) => Dom.xmlDocument = "ParseXML";
  [@Bs.send] external removeFromDom: (t, Dom.htmlElement) => Dom.htmlElement = "RemoveFromDOM";
};


let test = phaser;
let game = Game.make(gameConfig(~type_=(phaser -> auto), ~parent="test", ~width=800, ~height=600, ()));