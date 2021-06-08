[@react.component]
let make = () =>
  <Slide id="component-templates">
    <Heading size=3> {CodeFormat.color(Theme.red, "ReasonReact")} </Heading>
    <Heading size=4> {React.string("Component Templates")} </Heading>
    <br />
    <Appear>
      <TextSpectacle>
        {React.string("Define stateless components with ")}
        <code> {React.string("react.component")} </code>
      </TextSpectacle>
    </Appear>
    <br />
    <Appear>
      <TextSpectacle>
        {React.string("Define stateful components with ")}
        <code> {React.string("ReasonReact.reducerComponent")} </code>
      </TextSpectacle>
    </Appear>
  </Slide>;
