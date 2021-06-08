let errorStyle =
  ReactDOMRe.Style.make(
    ~width="100%",
    ~backgroundColor="#db4d3f",
    ~color="white",
    ~padding="10px",
    ~position="absolute",
    ~left="0",
    ~right="0",
    ~margin="auto",
    (),
  );

[@react.component]
let make = (~message) =>
  <div style=errorStyle> {React.string(message)} </div>;
