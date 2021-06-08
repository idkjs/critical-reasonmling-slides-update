[@react.component]
let make = () =>
  <Slide id="reducer-components">
    <Heading size=3> {CodeFormat.color(Theme.red, "ReasonReact")} </Heading>
    <Heading size=4> {React.string("Managing State with Reducers")} </Heading>
    <List_ textSize="35px">
      <Appear>
        <ListItem>
          {React.string("Define a variant with all possible actions")}
        </ListItem>
      </Appear>
      <Appear>
        <ListItem>
          {React.string("Define a ")}
          <code> {React.string("reduce")} </code>
          {React.string(" method for state updates")}
        </ListItem>
      </Appear>
      <Appear>
        <ListItem>
          {React.string("Use ")}
          <code> {React.string("self.reduce")} </code>
          {React.string(" to bind updater functions")}
        </ListItem>
      </Appear>
    </List_>
  </Slide>;
