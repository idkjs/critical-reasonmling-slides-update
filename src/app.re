let colors: Theme.colors = {
  primary: "white",
  secondary: Theme.black,
  tertiary: Theme.red,
};

let fonts: Theme.fonts = {primary: "Montserrat", secondary: "Helvetica"};

let theme = Theme.create(colors, fonts);

[@react.component]
let make = () =>
  <div>
    <Typeface googleFont="Roboto Mono" />
    <Deck theme>
      {<Introduction />}
      {<Formidable />}
      {<SoHotRightNow />}
      {<Pitch />}
      <Compiler />
      {<ReasonLogo />}
      /* (BindingsAndScope.make ()) */
      /* (TypeSystem.make ()) */
      {<Basics />}
      {<PatternMatchingVariants />}
      {<Modules />}
      /* (FilesAsModules.make ()) */
      {<ModulesExample />}
      {<Tooling />}
      {<ReasonTools />}
      {<Refmt />}
      {<Repl />}
      /* (Ffi.make ()) */
      <GettingStarted />
      {<TheEnd />}
      {<ReasonReactIntro />}
      {<ReactIntro />}
      {<ComponentTemplate />}
      {<StatelessComponent />}
      {<ReducerComponents />}
      {<ReducerComponentExample />}
      <StartingReasonReactProject />
      {<Thanks />}
    </Deck>
  </div>;
