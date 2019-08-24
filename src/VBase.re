type vervContainerT('a) = Container('a);

let map = (f, vervComponent) => switch(vervComponent) {
  | Container(component) => Container(f(component))
};

let flatMap = (f, vervComponent) => switch(vervComponent) {
  | Container(component) => f(component);
};