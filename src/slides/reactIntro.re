let ranges: Js.Array.t(CodeSlide.range) = [|
  {loc: [|0, 1000|]},
  {loc: [|0, 1|]},
  {loc: [|2, 11|]},
  {loc: [|4, 10|]},
|];
[@react.component]
let make = () =>
  <Slide id="defining-reason-react-components">
    <Heading size=4> {React.string("Building Components with ")} </Heading>
    <Heading size=3> {CodeFormat.color(Theme.red, "ReasonReact")} </Heading>
    <br />
    <List_ textSize="35px">
      <Appear>
        <ListItem>
          {React.string("Create the component template.")}
        </ListItem>
      </Appear>
      <Appear>
        <ListItem>
          {React.string("Define a ")}
          <code> {React.string("make")} </code>
          {React.string(" function.")}
        </ListItem>
      </Appear>
      <Appear>
        <ListItem>
          {React.string("Define ")}
          <code> {React.string("render")} </code>
          {React.string(" and other lifecycle methods.")}
        </ListItem>
      </Appear>
    </List_>
  </Slide>;
