type vervEffect('a) =
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

let useReducer = (fn: ('state, 'action) => 'state, state: 'state) => {
  (state, fn(state));
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
