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
    initial := fn(wrappedValue^);
    initial^;
  };
  (initial, setValue(initial));
};
// let useReducer((state, action))

let useReducer = (fn:('state, 'action) => 'state, state:'state) => {
  (state, fn(state))
};
