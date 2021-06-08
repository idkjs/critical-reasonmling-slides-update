external eventToKeyboardEvent: Dom.event => Webapi.Dom.KeyboardEvent.t =
  "%identity";

let bind = (reduce, action) => reduce(_ => action);

type phase =
  | Overview
  | SourceCode
  | UntypedAST
  | TypedAST
  | LambdaIR
  | Bytecode
  | ReasonML
  | BuckleScript;

let sequence = [|
  Overview,
  SourceCode,
  UntypedAST,
  TypedAST,
  LambdaIR,
  Bytecode,
  ReasonML,
  BuckleScript,
|];

type state = {step: int};

type action =
  | StepForward
  | StepBackward;

let str = React.string;

let stepBlockStyle =
  ReactDOMRe.Style.make(
    ~backgroundColor="grey",
    ~color="white",
    ~padding="20px",
    ~margin="10px",
    ~borderRadius="10px",
    (),
  );

let activeStepBlockStyle =
  ReactDOMRe.Style.combine(
    stepBlockStyle,
    ReactDOMRe.Style.make(~backgroundColor="#03a9f4", ()),
  );

let makeActiveStepBlockStyle = backgroundColor =>
  ReactDOMRe.Style.combine(
    stepBlockStyle,
    ReactDOMRe.Style.make(~backgroundColor, ()),
  );

let reasonLogo =
  <img
    style={ReactDOMRe.Style.make(
      ~position="absolute",
      ~top="143px",
      ~left="-120px",
      ~width="150px",
      (),
    )}
    src=Assets.reasonLogo
  />;

let buckleScriptLogo =
  <img
    style={ReactDOMRe.Style.make(
      ~position="absolute",
      ~top="406px",
      ~left="-120px",
      ~width="150px",
      (),
    )}
    src=Assets.buckleScriptLogo
  />;

let renderOverview = () => {
  let steps =
    React.array(
      Js.Array.map(
        title =>
          <Layout key=title>
            <Fill>
              <div style=activeStepBlockStyle> {React.string(title)} </div>
            </Fill>
          </Layout>,
        [|
          "Source Code",
          "Untyped AST",
          "Typed AST",
          "Lambda IR",
          "Bytecode",
        |],
      ),
    );
  <div>
    <Heading size=4> {React.string("The OCaml Compiler")} </Heading>
    <br />
    steps
  </div>;
};

let renderStandardSequence = active => {
  let sequence = [|SourceCode, UntypedAST, TypedAST, LambdaIR, Bytecode|];
  let titles = [|
    "Source Code",
    "Untyped AST",
    "Typed AST",
    "Lambda IR",
    "Bytecode",
  |];
  let descriptions = [|
    "Take some OCaml source Code",
    "Do some parsing, lexing and preprocessing\nto get an untyped AST of the source Code",
    "Perform type inference and validation to get\na type-annotated version of the AST",
    "Transform that typed AST into an untyped\nIR in the form of s-expressions",
    "Do a lot of hand waving and compile the Lambda\nIR to bytecode or native",
  |];
  React.array(
    Js.Array.mapi(
      (phase, i) => {
        let title = React.string(titles[i]);
        let style =
          phase === active
            ? makeActiveStepBlockStyle("#03a9f4") : stepBlockStyle;
        let descriptionColor = phase === active ? "#333333" : "#CCCCCC";
        <Layout key={Array.get(titles, i)}>
          <Fill> <div style> title </div> </Fill>
          <Fill>
            <TextSpectacle
              textSize="30px" padding="6px" textColor=descriptionColor>
              {React.string(descriptions[i])}
            </TextSpectacle>
          </Fill>
        </Layout>;
      },
      sequence,
    ),
  );
};

let renderReasonMLStep = () => {
  let sequence = [|SourceCode, ReasonML, TypedAST, LambdaIR, Bytecode|];
  let titles = [|
    "Source Code",
    "Untyped AST",
    "Typed AST",
    "Lambda IR",
    "Bytecode",
  |];
  let descriptions = [|
    "Take some OCaml source Code",
    "ReasonML provides a forked parser and lexer, with some preprocessing utilities, implementing a new syntax",
    "Perform type inference and validation to get\na type-annotated version of the AST",
    "Transform that typed AST into an untyped\nIR in the form of s-expressions",
    "Do a lot of hand waving and compile the Lambda\nIR to bytecode or native",
  |];
  let steps =
    React.array(
      Js.Array.mapi(
        (phase, i) => {
          let title = React.string(titles[i]);
          let style =
            phase === ReasonML
              ? makeActiveStepBlockStyle(Theme.red) : stepBlockStyle;
          let descriptionColor = phase === ReasonML ? "#333333" : "#CCCCCC";
          <Layout key={Array.get(titles, i)}>
            <Fill> <div style> title </div> </Fill>
            <Fill>
              <TextSpectacle
                textSize="30px" padding="6px" textColor=descriptionColor>
                {React.string(descriptions[i])}
              </TextSpectacle>
            </Fill>
          </Layout>;
        },
        sequence,
      ),
    );
  <div> reasonLogo steps </div>;
};

let renderBuckleScriptStep = () => {
  let sequence = [|
    SourceCode,
    ReasonML,
    TypedAST,
    BuckleScript,
    BuckleScript,
  |];
  let titles = [|
    "Source Code",
    "Untyped AST",
    "Typed AST",
    "Lambda IR",
    "JavaScript",
  |];
  let descriptions = [|
    "Take some OCaml source Code",
    "ReasonML provides a forked parser and lexer, with some preprocessing utilities, implementing a new syntax",
    "Perform type inference and validation to get\na type-annotated version of the AST",
    "BuckleScript consumes the untyped Lambda IR using a multi-pass compiler...",
    "...and outputs fast, idiomatic JavaScript instead of native or bytecode!",
  |];
  let steps =
    React.array(
      Js.Array.mapi(
        (phase, i) => {
          let title = React.string(titles[i]);
          let style =
            if (phase === BuckleScript) {
              makeActiveStepBlockStyle(Theme.green);
            } else if (phase === ReasonML) {
              makeActiveStepBlockStyle(Theme.red);
            } else {
              stepBlockStyle;
            };
          let descriptionColor =
            phase === ReasonML || phase == BuckleScript
              ? "#333333" : "#CCCCCC";
          <Layout key={Array.get(titles, i)}>
            <Fill> <div style> title </div> </Fill>
            <Fill>
              <TextSpectacle
                textSize="30px" padding="6px" textColor=descriptionColor>
                {React.string(descriptions[i])}
              </TextSpectacle>
            </Fill>
          </Layout>;
        },
        sequence,
      ),
    );
  <div> reasonLogo buckleScriptLogo steps </div>;
};

let renderSequence = step => {
  let step = sequence[step];
  switch (step) {
  | Overview => renderOverview()
  | SourceCode
  | UntypedAST
  | TypedAST
  | LambdaIR
  | Bytecode => renderStandardSequence(step)
  | ReasonML => renderReasonMLStep()
  | BuckleScript => renderBuckleScriptStep()
  };
};

let keydownListener = ref(None);

let handleKeyDown = (~onArrowDown, ~onArrowUp, event) => {
  let event = eventToKeyboardEvent(event);
  switch (Webapi.Dom.KeyboardEvent.code(event)) {
  /* Down Arrow */
  | "ArrowDown" => onArrowDown()
  /* Up Arrow */
  | "ArrowUp" => onArrowUp()
  /* All other keys */
  | _ => ()
  };
};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | StepForward =>
          Js.log(state);
          Js.log(Js.Array.length(sequence));
          Js.log(sequence);
          if (state.step < Js.Array.length(sequence) - 1) {
            {step: state.step + 1};
          } else {
            state;
          };
        | StepBackward =>
          if (state.step > 0) {
            {step: state.step - 1};
          } else {
            state;
          }
        },
      {step: 0},
    );
  React.useEffect0(() => {
    let listener =
      handleKeyDown(
        ~onArrowDown=_e => dispatch(StepForward),
        ~onArrowUp=_e => dispatch(StepBackward),
      );
    Webapi.Dom.(Document.addEventListener("keydown", listener, document));
    // keydownListener := Some(listener);
    Some(
      () => {
        switch (keydownListener^) {
        | Some(listener) =>
          Webapi.Dom.(
            Document.removeEventListener("keydown", listener, document)
          )
        | None => /* Who cares */ ()
        }
      },
    );
  });

  let sequence = renderSequence(state.step);
  <div>
    <style>
      {React.string(
         {js|
              .spectacle-slide {
                overflow: visible !important;
              }
            |js},
       )}
    </style>
    <Slide maxWidth="900px" id="ocaml-compiler-phases"> sequence </Slide>
  </div>;
};
