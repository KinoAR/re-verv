type reducerT('state, 'action) = ('state, 'action) => 'state;
type combineReducers('composedReducers, 'composedState) =
  'composedReducers => 'composedState;
type vervEffectT('a) =
  | VervEffect('a);

let map = (f, vervComponent) =>
  switch (vervComponent) {
  | VervEffect(component) => VervEffect(f(component))
  };

let flatMap = (f, vervComponent) =>
  switch (vervComponent) {
  | VervEffect(component) => f(component)
  };

let (!>) = value => VervEffect(value);
let lift = value => VervEffect(value);

let (<<=) = (vervContainer, f) =>
  switch (vervContainer) {
  | VervEffect(image) => VervEffect(f(image))
  };

let useState = fn => {
  let initial = ref(fn());
  let setValue = (wrappedValue, fn) => {
    wrappedValue := fn(wrappedValue^);
    wrappedValue^;
  };
  (initial, setValue(initial));
};

let useReducer = (fn: reducerT('state, 'action'), state: 'state) => {
  (state, fn(state));
};

let combineReducers =
    (
      fn: combineReducers('composedReducers, 'state),
      reducers: 'composedReducers,
    ) => {
  fn(reducers);
};

let useEffect = (fn: unit => unit) => {
  fn();
};

let useEffectWithCleanup = (fn, cleanupFn) => {
  useEffect(fn);
  cleanupFn();
};

let useSideEffect = (fn: unit => unit) => {
  fn();
};

let useSideEffectWithCleanup = (fn, cleanupFn) => {
  useSideEffect(fn);
  cleanupFn();
};

let zeroCallback = fn =>
  [@bs.this]
  {
    this => {
      fn(this: 'any) |> ignore;
    };
  };

let dataCallback = fn =>
  [@bs.this]
  {
    (this, data) => {
      fn(this: 'any, data) |> ignore;
    };
  };
