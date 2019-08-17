

type phaser;
type game;
type systems;
type clock;
type time = float;
type delta = float;
type phaserDom;
type eventEmitter;
type lightsManager;
type gameObjectFactory;
type gameObject;
type point;
type scaleManager;
type dataManager;
type textureManager;
type tweenManager;
type baseSoundManager;
type pluginManager;


type tweenBuilderConfig;

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


type arcadeBody;
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

type impactBody;
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


module Tilemaps = {

};

module GameObjects = {
  type t = gameObject;
  type text;
  type bitmapText;
  type dynamicBitmapText;
  type blitter;
  type arc;
  type displayList;
  type updateList;
  type container;
  type curve;
  type ellipse;
  type extern;
  type graphics;
  [@bs.deriving abstract]
  type fillStyle = {
    [@bs.optional] color: int,
    [@bs.optional] alpha: int,
    [@bs.as "color"][@bs.optional] colorF: float,
    [@bs.as "alpha"][@bs.optional] alphaF: float
  };
  [@bs.deriving abstract]
  type lineStyle = {
    [@bs.optional] width: int,
    [@bs.optional] color: int,
    [@bs.optional] alpha: int,
    [@bs.as "width"][@bs.optional] widthF: float,
    [@bs.as "color"][@bs.optional] colorF: float,
    [@bs.as "alpha"][@bs.optional] alphaF: float,
  };

  [@bs.deriving abstract]
  type styles = {
    [@bs.optional] lineStyle,
    [@bs.optional] fillStyle
  };
  [@bs.deriving abstract]
  type graphicsOptions = {
    [@bs.optional] x: int,
    [@bs.optional] y: int,
    [@bs.as "x"] [@bs.optional] xF: float,
    [@bs.as "y"] [@bs.optional] yF: float,
    [@bs.optional] lineStyle,
    [@bs.optional] fillStyle
  };
  type pathFollower;
  type grid;
  type group;
  type image;
  type isoBox;
  type isoTriangle;
  type line;
  type particleEmitterManager;
  type path;
  type polygon;
  type quad;
  type rectangle;
  type shader;
  type sprite;
  type sprite3d;
  type star;
  type tileSprite;
  type triangle;
  type zone;


  module Text = {
    [@bs.send] external setColor: (text, string) => text = "setColor";
  };

  module Polygon = {

  };

  module Image = {

  };

  module Zone = {

  };

  module Graphics = {
    type command;
    [@bs.get] external active: t => bool = "active"; 
    [@bs.set] external setActive: (t, bool) => unit = "active";
    [@bs.get] external alpha: t => int = "alpha";
    [@bs.get] external alphaF: t => float = "alpha";
    [@bs.set] external setAlpha: (t, int) =>  unit = "alpha";
    [@bs.set] external setAlphaF: (t, float) => unit = "alpha"; 
    [@bs.get] external alphaBottomLeft: t => int = "alphaBottomLeft";
    [@bs.get] external alphaBottomLeftF: t => float = "alphaBottomleft";
    [@bs.set] external setAlphaBottomleft: (t, int) => unit = "alphaBottomLeft";
    [@bs.set] external setAlphaBottomLeftf: (t, float) => unit = "alphaBottomRight";
    [@bs.set] external setAlphaBottomRight: (t, int) => unit = "alphaBottomRight";
    [@bs.get] external alphaTopLeft: t => int = "alphaTopLeft";
    [@bs.get] external alphaTopLeftf: t => float = "alphaTopLeft";
    [@bs.set] external setAlphaTopleft: (t, int) => unit = "alphaTopLeft";
    [@bs.set] external setAlphaTopLeftf: (t, float) => unit = "alphaTopLeft";
    [@bs.get] external alphaTopRight: t => int = "alphaTopRight";
    [@bs.get] external alphaTopRightf: t => float = "alphaTopRight";
    [@bs.set] external setAlphaTopRight: (t, int) => unit = "alphaTopRight";
    [@bs.set] external setAlphaTopRightf: (t, float) => unit = "alphaTopRight";
    [@bs.get] external angle: t => int = "angle";
    [@bs.get] external angleF: t => float = "angle";
    [@bs.set] external setAngle: (t, int) => unit = "angle";
    [@bs.set] external setAngleF: (t, float) => unit = "angle";
    [@bs.get] external blendMode: t => blendModes = "blendMode";
    [@bs.set] external setBlendMode: (t, blendModes) => unit = "blendMode"; 
    [@bs.get] external arcadeBody: t => Js.Nullable.t(arcadeBody) = "body";
    [@bs.get] external impactBody: t => Js.Nullable.t(impactBody) = "body";
    [@bs.get] external cameraFilter: t => int = "cameraFilter";
    [@bs.get] external commandBuffer: t => array(command) = "commandBuffer"; 
    [@bs.get] external defaultFillAlpha: t => int = "defaultFillAlpha";
    [@bs.get] external defaultFillAlphaF: t => float = "defaultFillAlpha";
    [@bs.get] external defaultFillColor: t => int = "defaultFillColor";
    [@bs.get] external defaultFillColorF: t => float = "defaultFillColor";
    [@bs.get] external defaultStrokeAlpha: t => int = "defaultStrokeAlpha";
    [@bs.get] external defaultStrokeAlphaF: t => float = "defaultStrokeAlpha";
    [@bs.get] external defaultStrokeColor: t => int = "defaultStrokeColor";
    [@bs.get] external defaultStrokecolorF: t => float = "defaultStrokeColor";
    [@bs.get] external defaultStrokeWidth: t => int = "defaultStrokeWidth";
    [@bs.get] external defaultStrokeWidthF: t => float = "defaultStrokeWidth";
    [@bs.get] external depth: t => int = "depth";
    [@bs.get] external depthF: t => float = "depth";
    [@bs.get] external rotation: t => int = "rotation";
    [@bs.get] external rotationF: t => float = "rotation";
    [@bs.set] external setRotation: (t, int) => unit = "rotation";
    [@bs.set] external setRotationF: (t, float) => unit = "rotation";
    [@bs.get] external scale: t => int = "scale";
    [@bs.get] external scaleF: t => float = "scale";
    [@bs.get] external scaleX: t => int = "scaleX";
    [@bs.get] external scaleXF: t => float = "scaleX";
    [@bs.get] external scaleY: t => int = "scaleY";
    [@bs.get] external scaleYF: t => float = "scaleY";
    [@bs.get] external scene: t => scene = "scene";
    [@bs.get] external scaleFactorX: t => int = "scaleFactorX";
    [@bs.get] external scaleFactorXF: t => float ="scaleFactorF"
    [@bs.set] external setScaleFactorXF: (t, float) => unit = "scaleFactorX";
    [@bs.get] external scaleFactorY: t => int = "scaleFactorY";
    [@bs.get] external scaleFactorYF: t => float = "scaleFactorY";
    [@bs.set] external setScaleFactorYF: (t, float) => unit = "scaleFactorY";
  };
};



module Scene {
  type t = scene;
  type scenePlugin;
  [@bs.module "phaser"] [@bs.new] external make: (sceneConfig) => t = "Scene";
  [@bs.get] external game: t => game = "game";
  [@bs.get] external add: t => gameObjectFactory = "add";
  [@bs.get] external impact: t => impactPhysics = "impact";
  [@bs.get] external matter: t => matterPhysics = "matter";
  [@bs.get] external physics: t => arcadePhysics = "physics";
  [@bs.get] external data: t => dataManager = "data";
  [@bs.get] external events: t => eventEmitter = "events";
  [@bs.get] external sys: t => systems = "sys";
  [@bs.get] external scene: t => scenePlugin = "scene";
  [@bs.get] external input: t => inputPlugin = "input";
  [@bs.get] external makeGameObject: t => gameObjectCreator = "make";
  [@bs.get] external registry: t => dataManager = "registry";
  [@bs.get] external scale: t => scaleManager =  "scale";
  [@bs.get] external lights: t => lightsManager = "lights";
  [@bs.get] external textures: t => textureManager = "textures";
  [@bs.get] external time: t => clock = "time";
  [@bs.get] external tweens: t => tweenManager = "tweens";
  [@bs.set] external setUpdate: (t, (time, delta) => unit) => unit = "update";
  [@bs.set] external setInit: (t, [@bs.this](t, Utils.any) => unit) => unit = "init";
  [@bs.set] external setCreate: (t, [@bs.this] (t, Utils.any) => unit) => unit = "create"; 
  [@bs.set] external setPreload: (t, t => unit) => unit = "preload";  
  [@bs.send] external update: (t, (time, delta) => unit) => unit = "update";
  external makeCreate: ([@bs.this] (t => unit) => unit) => unit => unit = "";
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


module TweenManager = {
  type t = tweenManager;
  type tween;
  type target;
  type easeEquations = 
  | Power0
  | Power1
  | Power2
  | Power3
  | Power4
  | Linear
  | Quad
  | Cubic
  | Quart
  | Quint
  | Sine
  | Expo
  | Circ
  | Elastic
  | Back
  | Bounce
  | Stepped
  | QuadEaseIn
  | CubicEaseIn
  | QuintEaseIn
  | QuartEaseIn
  | SineEaseIn
  | ExpoEaseIn
  | CircEaseIn
  | BackEaseIn
  | BounceEaseIn
  | QuadEaseOut
  | CubicEaseOut
  | QuartEaseOut
  | QuintEaseOut
  | SineEaseOut
  | ExpoEaseOut
  | CircEaseOut
  | BackEaseOut
  | BounceEaseOut
  | QuadEaseInOut
  | CubicEaseInOut
  | QuartEaseInOut
  | QuintEaseInOut
  | SineEaseInOut
  | ExpoEaseInOut
  | CircEaseInOut
  | BackEaseInOut
  | BounceEaseInOut;
  
  let tweenEquationStr = tweenEquation => switch(tweenEquation) {
    | Power0 => "Power0"
    | Power1 => "Power1"
    | Power2 => "Power2"
    | Power3 => "Power3"
    | Power4 => "Power4"
    | Linear => "Linear"
    | Quad => "Quad"
    | Cubic => "Cubic"
    | Quint => "Quint"
    | Quart => "Quart"
    | Sine => "Sine"
    | Expo => "Expo"
    | Circ => "Circ"
    | Elastic => "Elastic"
    | Back => "Back"
    | Bounce => "Bounce"
    | Stepped => "Stepped"
    | QuadEaseIn => "Quad.easeIn"
    | CubicEaseIn => "Cubic.easeIn"
    | QuartEaseIn => "Quart.easeIn"
    | QuintEaseIn => "Quint.easeIn"
    | SineEaseIn => "Sine.easeIn"
    | ExpoEaseIn => "Expo.easeIn"
    | CircEaseIn => "Circ.easeIn"
    | BackEaseIn => "Back.easeIn"
    | BounceEaseIn => "Bounce.easeIn"
    | QuadEaseOut => "Quad.easeOut"
    | CubicEaseOut => "Cubic.easeOut"
    | QuartEaseOut => "Quart.easeOut"
    | QuintEaseOut => "Quint.easeOut"
    | SineEaseOut => "Sine.easeOut"
    | ExpoEaseOut => "Expo.easeOut"
    | CircEaseOut => "Circ.easeOut"
    | BackEaseOut => "Back.easeOut"
    | BounceEaseOut => "Bounce.easeOut"
    | QuadEaseInOut => "Quad.easeInOut"
    | CubicEaseInOut => "Cubic.easeInOut"
    | QuartEaseInOut => "Quart.easeInOut"
    | QuintEaseInOut => "Quint.easeInOut"
    | SineEaseInOut => "Sine.easeInOut"
    | ExpoEaseInOut => "Expo.easeInOut"
    | CircEaseInOut => "Circ.easeInOut"
    | BackEaseInOut => "Back.easeInOut"
    | BounceEaseInOut => "Bounce.easeInOut"
  };

  /** Each one of these are functions in the documentation */
  [@bs.deriving abstract]
  type tweenDataGenConfig = {
    delay: Utils.any,
    duration: Utils.any,
    hold: Utils.any,
    repeat: Utils.any,
    repeatDelay: Utils.any 
  };


  [@bs.deriving abstract] 
  type numberTweenBuilderConfig = {
    [@bs.optional] from: int,
    [@bs.as "to"] [@bs.optional] to_: int,
    [@bs.optional] delay: int,
    [@bs.optional] duration: int,
    [@bs.optional] ease: string,
    [@bs.as "ease"] [@bs.optional] easeWithFunction: Utils.any => unit,
    [@bs.optional] easeParams: array(Utils.any),
    [@bs.optional] hold: int,
    [@bs.optional] repeat: int,
    [@bs.optional] repeatDelay: int,
    [@bs.optional] yoyo: bool,
    [@bs.optional] flipX: bool,
    [@bs.optional] flipY: bool,
    [@bs.optional] offset: int,
    [@bs.optional] completeDelay: int,
    [@bs.optional] loop: int,
    [@bs.optional] loopDelay: int,
    [@bs.optional] paused: bool,
    [@bs.optional] props: Utils.any,
    [@bs.optional] useFrames: bool,
    [@bs.optional] callbackScope: Utils.any,
    [@bs.optional] onComplete: (tween, array(Utils.any), Utils.any) => unit,
    [@bs.optional] onCompleteParams: (array(Utils.any)),
    [@bs.optional] onCompleteScope: Utils.any,
    [@bs.optional] onLoopParams: array(Utils.any),
    [@bs.optional] onRepeat: (tween, Utils.any, Utils.any) => unit,
    [@bs.optional] onRepeatParams: array(Utils.any),
    [@bs.optional] onRepeatScope: Utils.any,
    [@bs.optional] onStart: (tween, array(Utils.any), Utils.any) => unit,
    [@bs.optional] onStartParams: array(Utils.any),
    [@bs.optional] onStartScope: Utils.any,
    [@bs.optional] onUpdate: (tween, array(Utils.any), Utils.any) => unit,
    [@bs.optional] onUpdateParams: array(Utils.any),
    [@bs.optional] onUpdateScope: Utils.any,
    [@bs.optional] onYoyo: (tween, array(Utils.any), Utils.any) => unit,
    [@bs.optional] onYoyoParams: array(Utils.any),
    [@bs.optional] onYoYoScope: Utils.any,
    [@bs.optional] onActive: (tween, Utils.any, Utils.any) => unit,
    [@bs.optional] onActiveParams: array(Utils.any),
    [@bs.optional] onActiveScope: Utils.any
  };

  [@bs.deriving abstract]
  type tweenBuilderConfig = {
    targets: Utils.any,
    [@bs.optional] delay: int,
    [@bs.optional] duration: int,
    [@bs.optional] ease: string,
    [@bs.as "ease"] [@bs.optional] easeWithFunction: Utils.any => unit,
    [@bs.optional] easeParams: array(Utils.any),
    [@bs.optional] hold: int,
    [@bs.optional] repeat: int,
    [@bs.optional] repeatDelay: int,
    [@bs.optional] yoyo: bool,
    [@bs.optional] offset: int,
    [@bs.optional] completeDelay: int,
    [@bs.optional] loop: int,
    [@bs.optional] loopDelay: int,
    [@bs.optional] paused: bool,
    [@bs.optional] useFrames: bool,
    [@bs.optional] callbackScope: Utils.any,
    [@bs.optional] onComplete: (tween, array(Utils.any), Utils.any) => unit,
    [@bs.optional] onCompleteParams: (array(Utils.any)),
    [@bs.optional] onCompleteScope: Utils.any,
    [@bs.optional] onLoopParams: array(Utils.any),
    [@bs.optional] onRepeat: (tween, Utils.any, Utils.any) => unit,
    [@bs.optional] onRepeatParams: array(Utils.any),
    [@bs.optional] onRepeatScope: Utils.any,
    [@bs.optional] onStart: (tween, array(Utils.any), Utils.any) => unit,
    [@bs.optional] onStartParams: array(Utils.any),
    [@bs.optional] onStartScope: Utils.any,
    [@bs.optional] onUpdate: (tween, array(Utils.any), Utils.any) => unit,
    [@bs.optional] onUpdateParams: array(Utils.any),
    [@bs.optional] onUpdateScope: Utils.any,
    [@bs.optional] onYoyo: (tween, array(Utils.any), Utils.any) => unit,
    [@bs.optional] onYoyoParams: array(Utils.any),
    [@bs.optional] onYoYoScope: Utils.any,
  };


  [@bs.deriving abstract]
  type tweenDataConfig = {
    target: Utils.any,
    index: int,
    key: string,
    getActiveValue: (Utils.any, string, int, int, int, tween) => float,
    getEndValue: (Utils.any, string, int, int, int, tween) => float,
    getStartValue: (Utils.any, string, int, int, int, tween) => float,
    ease: Utils.any,
    [@bs.optional] duration: float,
    [@bs.optional] totalDuration: float,
    [@bs.optional] delay: float,
    [@bs.optional] yoyo: bool,
    [@bs.optional]  hold: float,
    [@bs.optional] repeat: int,
    [@bs.optional] repeatDelay: float,
    [@bs.optional] flipX: bool,
    [@bs.optional] flipY: bool,
    [@bs.optional] progress: float,
    [@bs.optional] elapsed: float,
    [@bs.optional] repeatCounter: int,
    [@bs.optional] start: float,
    [@bs.optional] current: float,
    [@bs.as "end"] [@bs.optional] end_: float,
    [@bs.optional] t1: float,
    [@bs.optional] t2: float,
    [@bs.optional] gen:tweenDataGenConfig,
    [@bs.optional] state: int
  };

  [@bs.deriving abstract] 
  type staggerConfig = {
    [@bs.optional] start: int,
    [@bs.optional] ease: string,
    [@bs.as "from"] [@bs.optional] easeWithFn : unit => unit,
    [@bs.as "from"] [@bs.optional] fromStr: string,
    [@bs.as "from"] [@bs.optional] fromInt: int,
    [@bs.optional] grid: array(int)
  };

  [@bs.send] external add: (t, tweenBuilderConfig) => tween = "add";
  [@bs.send] external addCounter: (t, numberTweenBuilderConfig) => tween = "addCounter";
  [@bs.send] external create: (t, tweenBuilderConfig) => tween = "create";
  [@bs.send] external destroy: t => unit = "destroy";
  [@bs.send] external existing: (t, tween) => t = "existing";
  [@bs.send] external getAllTweens: t => array(tween) = "getAllTweens";
  [@bs.send] external getGlobalTimeScale: t => int = "getGlobalTimeScale";
  [@bs.send] external getTweensOf: (t, target) => array(tween) = "getTweensOf";
  [@bs.send] external isTweening: (t, target) => bool = "isTweening";
  [@bs.send] external killAll: t => t = "killAll";
  [@bs.send] external killTweensOf: (t, target) => t = "killTweensOf";
  [@bs.send] external makeActive: (t, tween) => t = "makeActive";
  [@bs.send] external pauseAll: t => t = "pauseAll";
  [@bs.send] external remove: (t, tween) => t = "remove";
  [@bs.send] external resumeAll: t => t = "resumeAll";
  [@bs.send] external setGlobalTimeScale: (t, float) => t = "setGlobalTimeScale";

};

module DOM = {
  type t = phaserDom;
  [@bs.send] external addToDom:  (t,Dom.htmlElement, string) => Dom.htmlElement = "AddToDOM";
  [@bs.send] external domContentLoaded: (t, unit => unit) => unit = "DOMContentLoaded";
  [@bs.send] external getInnerHeight: (t, bool) => int = "GetInnerHeight";
  [@bs.send] external getScreenOrientation: (t, int, int) => string = "GetScreenOrientation";
  [@bs.send] external getTarget: (t, Dom.htmlElement) => Dom.htmlElement = "GetTarget";
  [@bs.send] external parseXML: (t, string) => Dom.xmlDocument = "ParseXML";
  [@b.send] external removeFromDom: (t, Dom.htmlElement) => Dom.htmlElement = "RemoveFromDOM";
};


module GameObjectFactory = {
  type t = gameObjectFactory;
  type font = string;
  type text = string;
  [@bs.get] external scene: t => scene = "scene";
  [@bs.get] external systems: t => systems = "systems";
  [@bs.get] external updateList: t =>  GameObjects.updateList = "UpdateList";
  [@bs.get] external displayList: t =>  GameObjects.displayList = "DisplayList";
  [@bs.send] external graphics: (t, GameObjects.graphicsOptions) => GameObjects.graphics = "graphics";
  [@bs.send] external bitmapText: (t, int, int, font, text, int, int) => GameObjects.bitmapText = "bitmapText";
  [@bs.send] external text:  (t, int, int, text) => GameObjects.text = "text";
  [@bs.send] external blitter: (t, int, int, string) => GameObjects.blitter = "blitter";
  [@bs.send] external blitterWithStrFrames: (t, int, int, string, string) => GameObjects.blitter = "blitter";
  [@bs.send] external blitterWithIntFrames: (t, int, int, string, int) => GameObjects.blitter = "blitter";
  [@bs.send] external circle: (t, int, int, int, int, int) => GameObjects.arc = "circle";
  [@bs.send] external container: (t, int, int, gameObject) => GameObjects.container = "container";
  [@bs.send] external containerWithArr: (t, int, int, array(gameObject)) => GameObjects.container = "container";
  [@bs.send] external polygonInt: (t, int, int, array(point), int, int) => GameObjects.polygon = "polygon";
  [@bs.send] external polygonFloat: (t, float, float, array(point), int, int) => GameObjects.polygon = "polygon";
  [@bs.send] external extern: t => GameObjects.extern = "extern";
  [@bs.send] external imageIntStr: (t, int, int, string,string) => GameObjects.image = "image";
  [@bs.send] external imageIntInt: (t, int, int, string, int) => GameObjects.image = "image";
  [@bs.send] external imageFloatStr: (t, float, float, string, string) => GameObjects.image ="image";
  [@bs.send] external imageFloatInt: (t, float, float, string, int) => GameObjects.image ="image";
  [@bs.send] external existing: (t, gameObject) => gameObject = "existing";
  [@bs.send] external quadStr: (t, int, int, string, string) => GameObjects.quad = "quad";
  [@bs.send] external quadInt: (t, int, int, string, int) => GameObjects.quad = "quad";
  [@bs.send] external pathInt: (t, int, int) => GameObjects.path = "path";
  [@bs.send] external pathFloat: (t, float, float) => GameObjects.path = "path";
  [@bs.send] external tween: (t, tweenBuilderConfig) => TweenManager.tween = "tween";
  [@bs.send] external zone: (t, int, int, int, int) => GameObjects.zone = "zone";
};