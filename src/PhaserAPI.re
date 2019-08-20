

type phaserT;
type gameT;
type systems;
type clockT;
type time = float;
type delta = float;
type phaserDom;
type eventEmitter;
type lightsManager;
type gameObjectFactory;
type gameObjectT;
type point;
type scaleManagerT;
type dataManagerT;
type textureManager;
type tweenManager;
type baseSoundManager;
type pluginManager;
type htmlCanvasElementT;
type configT;
type camera2DT;
type tweenBuilderConfig;

type inputPluginT;
type loaderPluginT;
type gameObjectCreatorT;



[@bs.obj] external anyData: (
  ~name:string,
  ~data: Js.t({..}),
  unit
) =>  _ = "";

/* init, create need to have a data "object" */
[@bs.deriving abstract]
type sceneT = {
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


[@bs.get] external rendererAuto: phaserT => rendererType = "AUTO";
[@bs.get] external rendererCanvas: phaserT => rendererType = "CANVAS";
[@bs.get] external rendererHeadless: phaserT => rendererType = "HEADLESS";
[@bs.get] external rendererWebGL: phaserT => rendererType = "WEBGL";
[@bs.get] external blendModes: phaserT => blendModes = "BLENDMODES";


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


type arcadeBodyT;
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

type impactBodyT;
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

type matterBodyT;
[@bs.deriving abstract]
type matterTileOptions = {
  [@bs.optional] body: matterBodyT,
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
  [@bs.optional] transitionFrom:sceneT,
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
  [@bs.optional] scene: sceneT,
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


[@bs.module] external phaser: phaserT = "phaser"; 


module Events = {
  type eventEmitterT;

  module EventEmitter = (E: {type t;}) => {
    type eventEmitterT;
    // type t = eventEmitterT;
    [@bs.send] external addEventListener: (E.t, string, [@bs.this] ('a => unit), 'a) => E.t = "addEventListener";
    [@bs.send] external once: (E.t, string, [@bs.this] ('a => unit), 'a) => E.t = "on";
    [@bs.send] external on: (E.t, string, [@bs.this]('a) => unit, 'a) => E.t  = "on";
    [@bs.send] external off: (E.t, string, [@bs.this] ('a => unit), 'a, bool) => E.t = "on";
    [@bs.send] external offStr: (E.t, string) => E.t = "off";
    [@bs.send] external listeners: (E.t, string) => array('a) = "listeners";
    [@bs.send] external eventNames: E.t => array(string) = "eventNames";
    [@bs.send] external emit0: (E.t, string) => bool = "emit";
    [@bs.send] external emit1: (E.t, string, 'a) => bool = "emit";
    [@bs.send] external emit2: (E.t, string, 'a, 'b) => bool = "emit";
    [@bs.send] external destroy: E.t => unit = "destroy";
    [@bs.send] external shutdown: E.t => unit = "shutdown";
    [@bs.send] external removeAllListenersStr: (E.t, string) => E.t = "removeAllListeners";
    [@bs.send] external removeAllListeners: E.t => E.t = "removeAllListeners"; 
    [@bs.send] external removeListenerStr: (E.t, string) => E.t = "removeLIstener";
  };
};


module Math = {
  type vector2T;
  module Vector2 = {
    type t = vector2T;
    [@bs.module "phaser"][@bs.scope "Math"][@bs.new] external make: (int, int) => t = "Vector2";
    [@bs.module "phaser"][@bs.scope "Math"][@bs.new] external makeF: (float, float) => t = "Vector2";
    [@bs.get] external x: t => int = "x";
    [@bs.get] external y: t => int = "y";
    /** Methods Add */
    [@bs.send] external add: (t, t) => t = "add";
    [@bs.send] external angle: t => int = "angle";
    [@bs.send] external angleF: t => float = "angle";
    [@bs.send] external clone: t => t  = "clone";
    [@bs.send] external copy: (t, t) => t = "copy";
    [@bs.send] external cross: (t, t) => int = "cross";
    [@bs.send] external distance: (t, t) => int  ="distance";
    [@bs.send] external divide: (t, t) => int = "divide";
    [@bs.send] external distanceSq: (t, t) => int = "distanceSq";
    [@bs.send] external dot: (t, t) => t = "dot";
    [@bs.send] external equals: (t, t) => t = "equals";
    [@bs.send] external length: t => int = "length";
    [@bs.send] external lengthF: t => float = "length";
    [@bs.send] external lengthSq: t => int = "lengthSq";
    [@bs.send] external lengthSqF: t => float = "lengthSq";
    [@bs.send] external negate:  t => t = "negate";
    [@bs.send] external normalize: t => t = "normalize";
  };
};


module Time = {
  type timerEventT;
  [@bs.deriving abstract] 
  type timerEventConfigT = {
    [@bs.optional] delay: int,
    [@bs.optional] repeat: int,
    [@bs.optional] loop: bool,
    [@bs.optional] callback: unit => unit,
    [@bs.optional] callbackScope: Utils.any,
    [@bs.optional] args: array(Utils.any),
    [@bs.optional] timeScale: int,
    [@bs.as "timeScale"][@bs.optional] timeScaleF: float,
    [@bs.optional] startAt: int,
    [@bs.optional] paused: bool
  };
  module Clock = {
    type t = clockT;
    [@bs.module "phaser"][@bs.scope "Time"] [@bs.new] external make: (sceneT) => t = "Clock";
    [@bs.get] external paused: t => bool = "paused";
    [@bs.get] external timeScale: t => int = "timeScale";
    [@bs.get] external timeScaleF: t => float = "timeScale";
    [@bs.get] external scene: t => sceneT = "scene";
    [@bs.get] external now: t => int = "now";
    [@bs.get] external nowF: t => float = "now";
    [@bs.send] external addEvent: (t, timerEventConfigT) => t = "addEvent";  
    [@bs.send] external clearPendingEvents: t => t = "clearPendingEvents";
    [@bs.send] external preUpdate: (int, float) => unit = "preUpdate";
    [@bs.send] external removeAllEvents: t => t = "removeAllEvents";
    [@bs.send] external update: (int, float) => unit = "update";
  }

  module TimerEvent = {
    type t = timerEventT;
    [@bs.module "phaser"][@bs.scope "Time"] [@bs.new] external make: (timerEventConfigT) => t = "TimerEvent";
    [@bs.get] external paused: t => bool = "paused";
    [@bs.get] external repeatCount: t => int = "repeatCount";
    [@bs.get] external repeat: t => int = "repeat";
    [@bs.get] external startAt: t => int = "startAt";
    [@bs.get] external timeScale: t => float = "timeScale";
    [@bs.get] external hasDispatched: t => bool = "hasDispatched";
    [@bs.get] external elapsed: t => int = "elapsed";
    [@bs.get] external delay: t => int = "delay";
    [@bs.send] external destroy: t => unit = "destroy";
    [@bs.send] external getElapsed: t => int = "getElapsed";
    [@bs.send] external getElapsedSeconds: t => int = "getElapsedSeconds";
    [@bs.send] external getOverallProgress: t => float = "getOverallProgress";
    [@bs.send] external getRepeatCount: t => int = "getRepeatCount";
    [@bs.send] external remove: (t, bool) => unit = "remove";
    [@bs.send] external reset: (t, timerEventConfigT) => t = "reset";
  }
};

module Sound = {
  type baseSoundT;
  type baseSoundManagerT;
  type spriteMapT;

  [@bs.deriving abstract]
  type audioSpriteSoundT = {
    spritemap: spriteMapT
  };

  [@bs.deriving abstract]
  type soundConfigT = {
    [@bs.optional] mute: bool,
    [@bs.optional] volume: float,
    [@bs.optional] rate: float,
    [@bs.optional] detune: int,
    [@bs.optional] seek: int,
    [@bs.optional] loop: bool,
    [@bs.optional] delay: int
  };

  [@bs.deriving abstract]
  type decodeAudioConfigT = {
    key:string,
    data:string
  };

  [@bs.deriving abstract]
  type soundMarkerT = {
    [@bs.optional] name:string,
    [@bs.optional] start: int,
    [@bs.optional]duration: int,
    [@bs.optional] config: soundConfigT
  };

  module BaseSound = {
    type t = baseSoundT;
    [@bs.send] external addMarker: (t, soundMarkerT) => bool = "addMarker";
    [@bs.send] external pause: t => bool = "pause";
    [@bs.send] external play: (t, string) => bool = "play";
    [@Bs.send] external playWithConfig: (t, string, soundConfigT) => bool = "play";
    [@bs.send] external removeMarker: (t, string) => Js.Nullable.t(soundMarkerT) = "removeMarker";
    include(Events.EventEmitter({
      type nonrec t = t;
    }))
  };

  module BaseSoundManager = {
    type t = baseSoundManagerT;
    [@bs.get] external detune: t => int = "detune";
    [@bs.get] external game: t => gameT = "game";
    [@bs.get] external mute: t => bool = "mute";
    [@bs.get] external rate: t =>  float = "rate";
    [@bs.get] external volume: t => float = "volume";
    [@bs.send] external addAudioSprite: (t, string, soundConfigT) => audioSpriteSoundT = "addAudioSprite";
    [@bs.send] external pauseAll: t => unit = "pauseAll";
    [@bs.send] external play: (t, string) => bool = "play";
    [@bs.send] external playWithConfig: (t, string, soundConfigT) => bool = "play";
    [@bs.send] external removeByKey: (t, string) => int = "removeByKey";
    [@bs.send] external resumeAll: t => unit = "resumeAll";
    [@bs.send] external stopAll: t => unit = "stopAll";
    [@bs.send] external setDetune: (t, int) => t = "setDetune";
    [@bs.send] external setRate: (t, float) => t = "setRate";
    
    include(Events.EventEmitter({
      type nonrec t = t;
    }))
  };
};


module Input = {
  type inputT;
  type pointerT;
  type inputManagerT;
  type mouseManagerT;
  type touchManagerT;
  type keyboardManagerT;
  type interactiveObjectT;

  type t = inputT;
  module InputManager = {
    type t = inputManagerT;
    [@bs.get] external activePointer: t => pointerT = "activePointer"; 
    [@bs.get] external canvas: t => htmlCanvasElementT = "canvas";
    [@bs.get] external defaultCursor: t => string = "defaultCursor";
    [@bs.get] external config: t => configT = "config";
    [@bs.get] external enabled: t => bool = "enabled";
    [@bs.get] external globalTopOnly: t => bool = "globalTopOnly";
    [@bs.get] external events: t => Events.eventEmitterT = "events";
    [@bs.get] external game: t => gameT = "game";
    [@bs.get] external touch: t => touchManagerT = "touch";
    [@bs.get] external isOver: t => bool = "isOver";
    [@bs.get] external keyboard: t => Js.Nullable.t(keyboardManagerT) = "keyboard";
    [@bs.get] external mouse: t => Js.Nullable.t(mouseManagerT) = "mouse";
    [@bs.get] external scaleManager: t => scaleManagerT = "scaleManager";
    [@bs.get] external mousePointer: t => Js.Nullable.t(pointerT) = "mousePointer";
    [@bs.get] external pointersTotal: t => int = "pointersTotal";
    [@bs.get] external pointers: t => array(pointerT) = "pointers";
    [@bs.get] external time: t => float = "time";

    [@bs.send] external destroy: t => unit = "destroy";
    [@bs.send] external addPointer: (t, int) => array(pointerT) = "addPointer";
    [@bs.send] external boot: t => unit = "boot";
    [@bs.send] external pointWithinHitArea: (t, gameObjectT, int, int) => bool = "pointWithinHitArea";
    [@bs.send] external setDefaultCursor: (t, string) => unit = "setDefaultCursor";
    [@bs.send] external transformPointer: (t, pointerT, int, int, bool) => unit = "transformPointer";
    [@bs.send] external updateInputPlugins: (t, int, array(pointerT)) => unit = "updateInputPlugins";
  };


  module Gamepad = {

  };


  module Keyboard = {
    type keyboardPluginT;
    
    module Key =  {
      type keyT;
      type t = keyT;
      [@bs.module "phaser"] [@bs.scope ("Input", "Keyboard")] [@bs.new] external make: (keyboardPluginT, int) => t = "Key";
      [@bs.get] external altKey: t => bool = "altKey";
      [@bs.get] external ctrlKey: t => bool = "ctrlKey";
      [@bs.get] external duration: t => int = "duration";
      [@bs.get] external enabled: t => bool ="enabled";
      [@bs.get] external isUp: t => bool = "isUp";
      [@bs.get] external isDown: t => bool = "isDown";
      [@bs.get] external keyCode: t => int = "keyCode";
      [@bs.get] external location: t => int = "location"; 
      [@bs.get] external shiftKey: t => bool = "shiftKey";
      [@bs.get] external metaKey: t => bool = "metaKey";
      [@bs.get] external repeats: t => int = "repeats";
      [@bs.get] external timeUp: t => int = "timeUp";
      [@bs.get] external timeDown: t => int = "timeDown"
      include Events.EventEmitter({
        type nonrec t = t;
      });  
    }

    type inputKeyboardT;
    type t = inputKeyboardT;
    [@bs.send] external downDuration: (t, Key.t, int) => bool = "DownDuration";
    [@bs.send] external justDown: (t, Key.t) => bool = "JustDown";
    [@bs.send] external justUp: (t, Key.t) => bool = "JustUp";
    [@bs.send] external upDuration: (t, Key.t, int) => bool = "UpDuration";
  };

  module Mouse = {

  };

  module Touch = {

  };
};




module Game =  {
  type t = gameT;
  [@bs.module "phaser"][@bs.new] external make: (gameConfig) => t = "Game";
};


module Tilemaps = {

};




module GameObjects = {
  type t = gameObjectT;
  type textT;
  type bitmapTextT;
  type bitmapMask;
  type geometryMask;
  type dynamicBitmapText;
  type blitter;
  type arc;
  type displayList;
  type updateList;
  type containerT;
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
  type jsonGameObjectT;
  type pathFollower;
  type grid;
  type group;
  type imageT;
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
  
 module BaseGameObject = (G: {type t;}) => {
   [@bs.module "phaser"][@bs.scope "GameObjects"][@bs.new] external makeBase: (sceneT, string) => gameObjectT = "GameObject";
   [@bs.get] external active: G.t => bool = "active";
   [@bs.get] external cameraFilter: G.t => int = "cameraFilter";
   [@bs.get] external type_: G.t => string = "type";
   [@bs.get] external tabIndex: G.t => int = "tabIndex";
   [@bs.get] external state: G.t => string = "state";
   [@bs.get] external stateInt: G.t => int = "state";
   [@bs.get] external ignoreDestroy: G.t => bool = "ignoreDestroy";
   [@bs.get] external name: G.t => string = "name";
   [@bs.get] external parentContainer: G.t => containerT = "parentContainer";
   [@bs.get] external renderFlags: G.t => int = "renderFlags";
   [@bs.get] external scene: G.t => sceneT = "scene";
   [@bs.get] external input: G.t => Js.Nullable.t(Input.interactiveObjectT) = "input";
   [@bs.get] external data: G.t => dataManagerT = "data";
   [@bs.get] external arcadeBody: G.t => Js.Nullable.t(arcadeBodyT) = "body";
   [@bs.get] external impactBody: G.t => Js.Nullable.t(impactBodyT) = "body";
   [@bs.get] external matterBody: G.t => Js.Nullable.t(matterBodyT) = "body"; 
   [@bs.get] external renderMask: G.t => int = "RENDER_MASK";

   [@bs.set] external setActive: (t, bool) => unit = "active";
   [@bs.send] external disableInteractive: G.t => G.t = "disableInteractive"; 
   [@bs.send] external getData: (G.t, string) => 'a = "getData";
   [@bs.send] external getIndexList: G.t => array(int) = "getIndexList";
   [@bs.send] external removeInteractive: G.t => G.t = "removeInteractive";
   [@bs.send] external setName: (G.t, string) => G.t = "setName";
   [@bs.send] external setState: (G.t, string) => G.t = "setState";
   [@bs.send] external setDataEnabled: G.t => G.t = "setDataEnabled";
   [@bs.send] external setData: (G.t, string, 'a) => G.t = "setData";
   [@bs.send] external willRender: (G.t, camera2DT) => bool = "willRender";
   include(Events.EventEmitter({
     type nonrec t = t;
   }))
 };

  module Components = {
    module Alpha = (A:{type t;}) => {
      [@bs.send] external setAllAlpha: (A.t, ~topLeft:int, ~topRight:int, ~bottomLeft:int, ~bottomRight:int) => A.t = "setAlpha";
      [@bs.send] external clearAlpha: A.t => A.t = "clearAlpha";
      [@bs.get] external alpha: A.t => int = "alpha";
      [@bs.get] external alphaF: A.t => float = "alpha";
      [@bs.set] external setAlpha: (A.t, int) =>  unit = "alpha";
      [@bs.set] external setAlphaF: (A.t, float) => unit = "alpha"; 
      [@bs.get] external alphaBottomLeft: A.t => int = "alphaBottomLeft";
      [@bs.get] external alphaBottomLeftF: A.t => float = "alphaBottomleft";
      [@bs.set] external setAlphaBottomleft: (A.t, int) => unit = "alphaBottomLeft";
      [@bs.set] external setAlphaBottomLeftf: (A.t, float) => unit = "alphaBottomRight";
      [@bs.set] external setAlphaBottomRight: (A.t, int) => unit = "alphaBottomRight";
      [@bs.get] external alphaTopLeft: A.t => int = "alphaTopLeft";
      [@bs.get] external alphaTopLeftf: A.t => float = "alphaTopLeft";
      [@bs.set] external setAlphaTopleft: (A.t, int) => unit = "alphaTopLeft";
      [@bs.set] external setAlphaTopLeftf: (A.t, float) => unit = "alphaTopLeft";
      [@bs.get] external alphaTopRight: A.t => int = "alphaTopRight";
      [@bs.get] external alphaTopRightf: A.t => float = "alphaTopRight";
      [@bs.set] external setAlphaTopRight: (A.t, int) => unit = "alphaTopRight";
      [@bs.set] external setAlphaTopRightf: (A.t, float) => unit = "alphaTopRight";
    };

    module Transform = (T:{type t;}) => {
        [@bs.get] external angle: T.t => int = "angle";
        [@bs.get] external angleF: T.t => float = "angle";
        [@bs.set] external setAngle: (T.t, int) => T.t = "setAngle";
        [@bs.set] external setAngleF: (T.t, float) => T.t = "setAngle";
        [@bs.get] external rotation: T.t => int = "rotation";
        [@bs.get] external rotationF: T.t => float = "rotation";
        [@bs.set] external setRotation: (T.t, int) => T.t = "setRotation";
        [@bs.set] external setRotationF: (T.t, float) => T.t = "Rotation";
        [@bs.get] external scale: T.t => int = "scale";
        [@bs.get] external scaleF: T.t => float = "scale";
        [@bs.get] external scaleX: T.t => int = "scaleX";
        [@bs.get] external scaleXF: T.t => float = "scaleX";
        [@bs.get] external scaleY: T.t => int = "scaleY";
        [@bs.get] external scaleYF: T.t => float = "scaleY";
        [@bs.get] external w: T.t => int = "w";
        [@bs.get] external x: T.t => int = "x";
        [@bs.get] external y: T.t => int = "y";
        [@bs.get] external z: T.t => int = "z";
        [@bs.send] external setScale: (T.t, ~x: int, ~y: int) => T.t = "setScale";
        [@bs.send] external setPosition: (T.t, ~x:int, ~y:int, ~z:int, ~w:int) => T.t = "setPosition";
        [@bs.send] external setPositionF: (T.t, ~x:float, ~y:float, ~z:float, ~w:float) => T.t = "setPosition";
        [@bs.send] external getParentRotation: T.t => int = "getParentRotation";
        [@bs.send] external getParentRotationF: T.t => float = "getParentRotation";
        [@bs.send] external setW: (T.t, int) => T.t = "setW";
        [@bs.send] external setX: (T.t, int) => T.t = "setX";
        [@bs.send] external setY: (T.t, int) => T.t = "setY";
        [@bs.send] external setZ: (T.t, int) => T.t = "setZ";
    };

    module Visible = (V:{type t;}) => {
      [@bs.get] external visible: V.t => bool = "visible";
      [@bs.send] external setVisible: (V.t, bool) => V.t = "setVisible";
    };

    module Depth = (D:{type t;}) => {
      [@bs.get] external depth: D.t => int = "depth";
      [@bs.get] external depthF: D.t => float = "depth";
      [@bs.send] external setDepth: (D.t, int) => D.t = "setDepth";
    };

    module ScrollFactor = (SF:{type t;}) => {
      [@bs.get] external scrollFactorX: SF.t => int = "scrollFactorX";
      [@bs.get] external scrollFactorXF: SF.t => float = "scrollFactorF";
      [@bs.set] external setScrollFactorXF: (SF.t, float) => unit = "scrollFactorX";
      [@bs.get] external scrollFactorY: SF.t => int = "scrollFactorY";
      [@bs.get] external scrollFactorYF: SF.t => float = "scrollFactorY";
      [@bs.set] external setScrollFactorYF: (SF.t, float) => unit = "scrollFactorY";
      [@bs.send] external setScrollFactor:  (SF.t, ~x:int, ~y:int) => SF.t = "setScrollFactor";
      [@bs.send] external setScrollFactorF:  (SF.t, ~x:float, ~y:float) => SF.t = "setScrollFactor";
    };
  }

  module Text = {
    type t = textT;
    [@bs.send] external setColor: (textT, string) => textT = "setColor";
    include(BaseGameObject({
      type nonrec t = t;
    }))
  };

  module BitmapText = {
    type t = bitmapTextT;
    include BaseGameObject({
      type nonrec t = t;
    });
  };

  module Container = {
    type t = containerT;

    include BaseGameObject({
      type nonrec t = t;
    });

    include Components.Alpha({
      type nonrec t = t;
    });
    include Components.Transform({
      type nonrec t = t;
    });
    include Components.Visible({
      type nonrec t = t;
    });
    include Components.Depth({
      type nonrec t = t;
    });
  };

  module Polygon = {

  };

  module Image = {
    type t = imageT;
    include BaseGameObject({
      type nonrec t = t;
    });

    include Components.Alpha({
      type nonrec t = t;
    });
    include Components.Transform({
      type nonrec t = t;
    });
    include Components.Visible({
      type nonrec t = t;
    });
    include Components.Depth({
      type nonrec t = t;
    });
  };

  module Zone = {

  };

  module Graphics = {
    type command;
    type t = graphics;
    
    [@bs.get] external blendMode: t => blendModes = "blendMode";
    [@bs.set] external setBlendMode: (t, blendModes) => unit = "blendMode"; 
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
    [@bs.send] external beginPath: t => t = "beginPath";
    [@bs.send] external clear: t => t = "clear";
    [@bs.send] external clearMask: (t, bool) => t = "clearMask";
    [@bs.send] external closePath: t => t = "closePath";
    [@bs.send] external createBitmapMask: (t, gameObjectT) => bitmapMask = "createBitmapMask";
    [@bs.send] external createGeometryMask: (t, t) => geometryMask = "createGeometryMask";
    [@bs.send] external emit: (string, Utils.any) => bool = "emit";
    [@bs.send] external fill: t => t = "fill";
    [@bs.send] external fillCircle: (t, int, int, int) => t = "fillCircle";
    [@bs.send] external fillCircleF: (t, float, float, float) => t = "fillCircle";
    [@bs.send] external fillEllipse: (t, int, int, int, int, int) => t = "fillEllipse";
    [@bs.send] external fillEllipseF: (t, float, float, float, float, int) => t = "fillElipse";
    [@bs.send] external fillGradientStyle: (t, int, int, int, int, int) => t = "fillGradientStyle";
    [@bs.send] external fillGradientStyleF: (t, int, int, int, int, float) => t = "fillGradientStyleF";
    [@bs.send] external fillPath: t => t = "fillPath";
    [@bs.send] external fillPoint: (t, int, int, int) => t = "fillPoint";
    [@bs.send] external fillPointF: (t, float, float, float) => t = "fillPoint";

    include BaseGameObject({
      type nonrec t = t;
    });

    include(Components.Alpha({
      type nonrec t = t;
    }))
    include(Components.Transform({
      type nonrec t = t;
    }))
    include(Components.Visible({
      type nonrec t = t;
    }))
    include(Components.Depth({
      type nonrec t = t;
    }))
  };

  module Sprite = {

    include BaseGameObject({
      type nonrec t = t;
    });

    include Components.Alpha({
      type nonrec t = t;
    });
    include Components.Transform({
      type nonrec t = t;
    });
    include Components.Visible({
      type nonrec t = t;
    });
    include Components.Depth({
      type nonrec t = t;
    });
  };
};

module Physics = {
  type t;
  module Arcade = {
    [@bs.deriving abstract]
    type arcadeBodyBoundsT = {
      x: float,
      y: float,
      right: float,
      bottom: float
    };
    type arcadeWorldT;
    [@bs.deriving abstract]
    type arcadeWorldTreeMinMaxT = {
      minX: float,
      minY: float,
      maxX: float,
      maxY: float
    };
    [@bs.deriving abstract]
    type arcadeBodyCollisionT = {
      none: bool,
      top: bool,
      down: bool,
      left: bool,
      right: bool
    };
    module Body = {
      type t = arcadeBodyT;
      /** Members */
      [@bs.get] external allowDrag: t => bool = "allowDrag";
      [@bs.get] external allowGravity: t => bool = "allowGravity";
      [@bs.get] external allowRotation: t => bool = "allowRotation";
      [@bs.get] external angle: t => int = "angle";
      [@bs.get] external angleF: t => float = "angle";
      [@bs.get] external angularAcceleration: t => int = "angularAcceleration";
      [@bs.get] external angularAccelerationF: t => float = "angularAcceleration";
      [@bs.get] external angularDrag: t => int = "angularDrag";
      [@bs.get] external angularDragF: t => float = "angularDrag";
      [@bs.get] external angularVelocity: t => int  = "angularVelocity";
      [@bs.get] external angularVelocityF: t => float = "angularVelocity";
      [@bs.get] external bottom: t => int = "bottom";
      [@bs.get] external collideWorldBounds: t => bool = "collideWorldBounds";
      [@bs.get] external customSeperateX: t => bool = "customSeparateX";
      [@bs.get] external customSeparateY: t => bool = "customSeparateY";
      [@bs.get] external debugBodyColor: t => int = "debugBodyColor";
      [@bs.get] external debugShowBody: t => bool = "debugShowBody";
      [@bs.get] external debugShowVelocity: t => bool = "debugShowVelocity";
      [@bs.get] external embedded: t => bool = "embedded";
      [@bs.get] external enable: t => bool = "enable";
      [@bs.get] external facing: t => int = "facing";
      [@bs.get] external gameObject: t => GameObjects.t = "gameObject";
      [@bs.get] external halfHeight: t => int = "halfHeight";
      [@bs.get] external halfHeightF: t => float = "halfHeight";
      [@bs.get] external halfWidth: t => int = "halfWidth";
      [@bs.get] external halfWidthF: t => float = "halfWidth";
      [@bs.get] external height: t => int = "height";
      [@bs.get] external heightF: t => float = "height";
      [@bs.get] external immovable: t => bool = "immovable";
      [@bs.get] external mass: t => int = "mass";
      [@bs.get] external massF: t => float = "mass";
      [@bs.get] external moves: t => bool = "moves";
      [@bs.get] external touching: t => arcadeBodyCollisionT = "touching";
      [@bs.get] external onCollide: t => bool = "onCollide";
      [@bs.get] external onOverlap: t => bool = "onOverlap";
      [@bs.get] external onWorldBounds: t => bool = "onWorldBounds";
      [@bs.get] external overlapR: t => int = "overlapR";
      [@bs.get] external overlapRF: t => float = "overlapR";
      [@bs.get] external overlapX: t => int = "overlapX";
      [@bs.get] external overlapXF: t => float = "overlapX";
      [@bs.get] external overlapY: t => int = "overlapY";
      [@bs.get] external overlapYF: t => float = "overlapY";
      [@bs.get] external preRotation:t => int = "preRotation";
      [@bs.get] external preRotationF: t => float = "preRotationF";
      [@bs.get] external physicsType: t => int = "physicsType";
      [@bs.get] external radius: t => int = "radius";
      [@bs.get] external radiusF: t => float = "radius";
      [@bs.get] external right: t => int = "right";
      [@bs.get] external rightF: t => float = "right";
      [@bs.get] external rotation: t => int = "rotation";
      [@bs.get] external rotationF: t => float = "rotation";
      [@bs.get] external sourceHeight: t => int = "sourceHeight";
      [@bs.get] external sourceHeightF: t => float = "sourceHeight";
      [@bs.get] external sourceWidth: t => int = "sourceWidth";
      [@bs.get] external sourceWidthF: t => float = "sourceWidth";
      [@bs.get] external speed: t => int = "speed";
      [@bs.get] external speedF: t => float = "speed";
      [@bs.get] external syncBounds: t => bool = "syncBounds";
      [@bs.get] external useDamping: t => bool = "useDamping";
      [@bs.get] external width:  t => int = "width";
      [@bs.get] external widthF: t => float = "width";
      [@bs.get] external x: t => int = "x";
      [@bs.get] external xF: t => float = "x";
      [@bs.get] external y: t => int = "y";
      [@bs.get] external yF: t => float = "y";


      /** Methods */
      [@bs.send] external checkWorldBounds: t => bool = "checkWorldBounds";
      [@bs.send] external deltaAbsX: t => float = "deltaAbsX";
      [@bs.send] external deltaAbsY: t => float = "deltaAbsY";
      [@bs.send] external deltaX: t => float = "deltaX";
      [@bs.send] external deltaY: t => float = "deltaY";
      [@bs.send] external deltaZ: t => float = "deltaZ";
      [@bs.send] external destroy: t => unit = "destroy";
      [@bs.send] external drawDebug: (t,  GameObjects.graphics) => unit = "drawDebug";
      [@bs.send] external getBounds: (t, arcadeBodyBoundsT) => arcadeBodyBoundsT = "getBounds";
      [@bs.send] external hitTest: (t, int, int) => bool = "hitTest";
      [@bs.send] external hitTestF: (t, float, float) => bool = "hitTest";
      [@bs.send] external onCeiling: t => bool = "onCeiling";
      [@bs.send] external onFloor: t => bool = "onFloor";
      [@bs.send] external onWall: t => bool = "onWall";
      [@bs.send] external postUpdate: t => unit = "postUpdate";
      [@bs.send] external preUpdate: (t, bool, float) => unit = "preUpdate";
      [@bs.send] external reset: (t, int, int) => unit = "reset";
      [@bs.send] external resetF: (t, float, float) => unit = "reset";
      [@bs.send] external resetFlags: t => unit = "resetFlags";
      [@bs.send] external setAcceleration: (t, int, int) => t = "setAcceleration";
      [@bs.send] external setAccelerationF: (t, float, float) => t = "setAcceleration";
      [@bs.send] external setAccelerationX: (t, int) => t = "setAccelerationX";
      [@bs.send] external setAccelerationXF: (t, float) => t = "setAccelerationX";
      [@bs.send] external setAccelerationY: (t, int) => t = "setAccelerationY";
      [@bs.send] external setAccelerationYF: (t, float) => t = "setAccelerationY";
      [@bs.send] external setAllowDrag: (t, bool) => t = "setAllowDrag";
      [@bs.send] external setAllowGravity: (t, bool) => t = "setAllowGravity";
      [@bs.send] external setAllowRotation: (t, bool) => t = "setAllowRotation";
      [@bs.send] external setAngularAcceleration: (t, int) => t = "setAngularAcceleration";
      [@bs.send] external setAngularAccelerationF: (t, float) => t = "setAngularAccleration";
      [@bs.send] external setAngularDrag: (t, int) => t = "setAngularDrag";
      [@bs.send] external setAngularDragF: (t, float) => t = "setAngularDrag";
      [@bs.send] external setAngularVelocity: (t, int) => t = "setAngularVelocity";
      [@bs.send] external setAngularVelcotiyF: (t, float) => t = "setAngularVelocity";
      [@bs.send] external setBounce: (t, int, int) => t = "setBounce";
      [@bs.send] external setBounceF: (t, float, float) => t = "setBounce";
      [@bs.send] external setBounceX: (t, int) => t = "setBounceX";
      [@bs.send] external setBounceXF: (t, float) => t = "setBounceX";
      [@bs.send] external setBounceY: (t, int) => t = "setBounceY";
      [@bs.send] external setBounceYF: (t, float) => t = "setBounceYF";
      [@bs.send] external setCircle: (t, int, int, int) => t = "setCircle";
      [@bs.send] external setCircleF: (t, float, int, int) => t = "setCircle";
      [@bs.send] external setCollideWorldBounds: (t, bool, float, float) => t = "setCollideWorldBounds";
      [@bs.send] external setDrag: (t, int, int) => t = "setDrag";
      [@bs.send] external setDragF: (t, float, float) => t = "setDrag";
      [@bs.send] external setDragX: (t, int) => t = "setDragX";
      [@bs.send] external setDragXF: (t, float) => t = "setDragX";
      [@bs.send] external setDragY: (t, int) => t = "setDragY";
      [@bs.send] external setDragYF: (t, float) => t = "setDragY";
      [@bs.send] external setFriction: (t, int, int) => t = "setFriction";
      [@bs.send] external setFrictionF: (t, float, float) => t = "setFriction";
      [@bs.send] external setFrictionX: (t, int) => t = "setFrictionX";
      [@bs.send] external setFrictionXF: (t, float) => t = "setFrictionX";
      [@bs.send] external setFricitionY: (t, int) => t = "setFrictionY";
      [@bs.send] external setFrictionYF: (t, float) => t = "setFrictionY";
      [@bs.send] external setGravity: (t, int, int) => t = "setGravity";
      [@bs.send] external setGravityF: (t, float ,float) => t = "setGravity";
      [@bs.send] external setGravityX: (t, int) => t = "setGravityX";
      [@bs.send] external setGravityXF: (t, float) => t = "setGravityX";
      [@bs.send] external setGravityY: (t, int) => t = "setGravityY";
      [@bs.send] external setGravityYF: (t, float) => t = "setGravityY";
      [@bs.send] external setImmovable: (t, bool) => t = "setImmovable";
      [@bs.send] external setMass: (t, int) => t = "setMass";
      [@bs.send] external setMassF: (t, float) => t = "setMass";
      [@bs.send] external setMaxSpeed: (t, int) => t = "setMaxSpeed";
      [@bs.send] external setMaxSpeedF: (t, float) => t = "setMaxSpeed";
      [@bs.send] external setMaxVelocity: (t, int, int) => t  = "setMaxVelocity";
      [@bs.send] external setMaxVelocityF:(t, float, float) => t = "setMaxVelocity";
      [@bs.send] external setOffset: (t, int, int) => t = "setOffset";
      [@bs.send] external setOffsetF: (t, float, float) => t = "setOffset";
      [@bs.send] external setSize: (t, int, int, bool) => t = "setSize";
      [@bs.send] external setSizeF: (t, float, float, bool) => t = "setSize";
      [@bs.send] external setVelocity: (t, int, int) => t = "setVelocity";
      [@bs.send] external setVelocityF: (t, float, float) => t = "setVelocity";
      [@bs.send] external setVelocityX: (t, int) => t = "setVelocityX";
      [@bs.send] external setVelocityXF: (t, float) => t = "setVelocityX";
      [@bs.send] external setVleocityY: (t, int) => t = "setVelocityY";
      [@bs.send] external setVelocityYF: (t, float) => t ="setVelocityY";
      [@bs.send] external stop: t => t = "stop";
      [@bs.send] external update: (t, float) => unit = "update";
      [@bs.send] external updateBounds: t => unit = "updateBounds";
      [@bs.send] external updateCenter: t => unit = "updateCenter";
      [@bs.send] external willDrawDebug: t => unit = "willDrawDebug";
     };
  };

  module Impact = {
    module Body = {
      type t = impactBodyT;
    };
  };

  module Matter = {
    module Body = {
      type t = matterBodyT;
    };
  };
};



module Scene = {
  type t = sceneT;
  type scenePlugin;
  [@bs.module "phaser"] [@bs.new] external make: (sceneConfig) => t = "Scene";
  [@bs.get] external game: t => gameT = "game";
  [@bs.get] external add: t => gameObjectFactory = "add";
  [@bs.get] external load: t => loaderPluginT = "load";
  [@bs.get] external impact: t => impactPhysics = "impact";
  [@bs.get] external matter: t => matterPhysics = "matter";
  [@bs.get] external physics: t => arcadePhysics = "physics";
  [@bs.get] external data: t => dataManagerT = "data";
  [@bs.get] external events: t => eventEmitter = "events";
  [@bs.get] external sys: t => systems = "sys";
  [@bs.get] external scene: t => scenePlugin = "scene";
  [@bs.get] external input: t => inputPluginT = "input";
  [@bs.get] external makeGameObject: t => gameObjectCreatorT = "make";
  [@bs.get] external registry: t => dataManagerT = "registry";
  [@bs.get] external scale: t => scaleManagerT =  "scale";
  [@bs.get] external lights: t => lightsManager = "lights";
  [@bs.get] external textures: t => textureManager = "textures";
  [@bs.get] external time: t => clockT = "time";
  [@bs.get] external tweens: t => tweenManager = "tweens";
  [@bs.set] external setUpdate: (t, (time, delta) => unit) => unit = "update";
  [@bs.set] external setInit: (t, [@bs.this](t, Utils.any) => unit) => unit = "init";
  [@bs.set] external setCreate: (t, [@bs.this] (t, Utils.any) => unit) => unit = "create"; 
  [@bs.set] external setPreload: (t, t => unit) => unit = "preload";  
  [@bs.send] external update: (t, (time, delta) => unit) => unit = "update";
  external makeCreate: ([@bs.this] (t => unit) => unit) => unit => unit = "";
}




module BlendModes = {
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
  module Tween = {
    type t = tween;
    include Events.EventEmitter({
      type nonrec t = t;
    })
  }
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
  [@bs.get] external scene: t => sceneT = "scene";
  [@bs.get] external systems: t => systems = "systems";
  [@bs.get] external updateList: t =>  GameObjects.updateList = "UpdateList";
  [@bs.get] external displayList: t =>  GameObjects.displayList = "DisplayList";
  [@bs.send] external graphics: (t, GameObjects.graphicsOptions) => GameObjects.graphics = "graphics";
  [@bs.send] external bitmapText: (t, int, int, font, text, int, int) => GameObjects.bitmapTextT = "bitmapText";
  [@bs.send] external text:  (t, int, int, text) => GameObjects.textT = "text";
  [@bs.send] external blitter: (t, int, int, string) => GameObjects.blitter = "blitter";
  [@bs.send] external blitterWithStrFrames: (t, int, int, string, string) => GameObjects.blitter = "blitter";
  [@bs.send] external blitterWithIntFrames: (t, int, int, string, int) => GameObjects.blitter = "blitter";
  [@bs.send] external circle: (t, int, int, int, int, int) => GameObjects.arc = "circle";
  [@bs.send] external container: (t, int, int, gameObjectT) => GameObjects.containerT = "container";
  [@bs.send] external containerWithArr: (t, int, int, array(gameObjectT)) => GameObjects.containerT = "container";
  [@bs.send] external polygonInt: (t, int, int, array(point), int, int) => GameObjects.polygon = "polygon";
  [@bs.send] external polygonFloat: (t, float, float, array(point), int, int) => GameObjects.polygon = "polygon";
  [@bs.send] external extern: t => GameObjects.extern = "extern";
  [@bs.send] external imageIntStr: (t, int, int, string,string) => GameObjects.imageT = "image";
  [@bs.send] external imageIntInt: (t, int, int, string, int) => GameObjects.imageT = "image";
  [@bs.send] external imageFloatStr: (t, float, float, string, string) => GameObjects.imageT ="image";
  [@bs.send] external imageFloatInt: (t, float, float, string, int) => GameObjects.imageT ="image";
  [@bs.send] external existing: (t, gameObjectT) => gameObjectT = "existing";
  [@bs.send] external quadStr: (t, int, int, string, string) => GameObjects.quad = "quad";
  [@bs.send] external quadInt: (t, int, int, string, int) => GameObjects.quad = "quad";
  [@bs.send] external pathInt: (t, int, int) => GameObjects.path = "path";
  [@bs.send] external pathFloat: (t, float, float) => GameObjects.path = "path";
  [@bs.send] external tween: (t, tweenBuilderConfig) => TweenManager.tween = "tween";
  [@bs.send] external zone: (t, int, int, int, int) => GameObjects.zone = "zone";
};


module LoaderPlugin = {
  type t = loaderPluginT;
  type file;
  type xhrSettingsObject;
  [@bs.deriving abstract]
  type animationConfig = {
    key: string,
    [@bs.optional] url: string,
    [@bs.optional] dataKey: string,
    [@bs.optional] xhrSettings: xhrSettingsObject
  };

  [@bs.deriving abstract]
  type atlasConfig = {
    key: string,
    [@bs.optional] textureURL:string,
    [@bs.optional] atlasURL: string,
    [@bs.optional] textureXhrSettings: xhrSettingsObject,
    [@bs.optional] atlasXhrSettings: xhrSettingsObject
  };

  [@bs.deriving abstract]
  type audioConfig =  {
    key:string,
    [@bs.optional] urls: array(string),
    [@bs.optional] config: Utils.any,
    [@bs.optional] xhrSettings: xhrSettingsObject,
  };

  [@bs.deriving abstract]
  type audioSpriteConfig = {
    key:string,
    jsonURL: string,
    [@bs.optional] audioURL: array(string),
    [@bs.optional] audioConfig: Utils.any,
    [@bs.optional] audioXhrSettings: xhrSettingsObject,
    [@bs.optional] jsonXhrSettings: xhrSettingsObject
  };

  [@bs.deriving abstract]
  type image = {
    key:string,
    [@bs.optional] url: array(string),
    [@bs.optional] xhrSettings: xhrSettingsObject
  };

  [@bs.deriving abstract]
  type xmlConfig = {
    key:string,
    [@bs.optional] url: string,
    [@bs.optional] xhrSettings: xhrSettingsObject
  };

  [@bs.get] external baseURL: t => string = "baseURL";
  [@bs.set] external setBaseURL: (t, string) => t  = "setBaseURL";
  [@bs.get] external crossOrigin: t => string = "crossOrigin";
  [@bs.set] external setCrossOrigin: (t, string) => unit = "crossOrigin";
  [@bs.get] external path: t => string = "path";
  [@bs.set] external setPath: (t, string) => t = "setPath";
  [@bs.get] external prefix: t => string = "prefix";
  [@bs.set] external setPrefix: (t, string) => unit = "setPrefix";
  [@bs.get] external progress: t => float = "progress";
  [@bs.get] external scene: t => sceneT = "scene";
  [@bs.get] external state: t => int = "state";
  [@bs.get] external systems: t => systems = "systems";
  [@bs.get] external totalComplete: t => int = "totalComplete";
  [@bs.get] external totalFailed: t => int = "totalFailed";
  [@bs.get] external totalToLoad: t => int = "totalToLoad";
  [@bs.get] external xhr: t => xhrSettingsObject = "xhr";
  [@bs.send] external start: t => unit = "start";
  [@bs.send] external addFile: (t, file) => unit = "addFile";
  [@bs.send] external addListener: (string, 'a => unit) => t = "addListener";
  [@bs.send] external addPack: (t, 'a, string) => bool = "addPack";
  [@bs.send] external animation: (t, animationConfig) => t = "animation"; 
  [@bs.send] external atlas: (t, atlasConfig) => t = "atlas";
  [@bs.send] external update:   t => unit = "update";
  [@bs.send] external updateProgress: t => unit = "updateProgress";
  [@bs.send] external isLoading: t => bool = "isLoading";
  [@bs.send] external isReady: t => bool = "isReady";
  [@bs.send] external keyExists: (t, file) => bool = "keyExists";
  [@bs.send] external listenerCount: (t, string) => int = "listenerCount";
  [@bs.send] external listeners: (t, string) => array('a) = "listeners";
  [@bs.send] external reset: t => unit = "reset";
}