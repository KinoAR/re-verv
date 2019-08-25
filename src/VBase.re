type vervContainerT('a) = Container('a);

let map = (f, vervComponent) => switch(vervComponent) {
  | Container(component) => Container(f(component))
};

let flatMap = (f, vervComponent) => switch(vervComponent) {
  | Container(component) => f(component);
};

let useState = (fn) => {
  let initial = ref(fn());
  let setValue = (wrappedValue, fn) => {
    wrappedValue := fn(wrappedValue^);
    wrappedValue^;
  };
  (initial, setValue(initial));
};

let useReducer = (fn:('state, 'action) => 'state, state:'state) => {
  (state, fn(state))
};
