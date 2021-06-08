type action =
  | Add
  | Subtract;

type state = {count: int};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Add => {count: state.count + 1}
        | Subtract => {count: state.count - 1}
        },
      {count: 1},
    );

  let count = string_of_int(state.count);
  let increment = _e => dispatch(Add);
  let decrement = _e => dispatch(Subtract);
  <div>
    {React.string("Count: #" ++ count)}
    <button onClick=increment> {React.string("+")} </button>
    <button onClick=decrement> {React.string("-")} </button>
  </div>;
};
