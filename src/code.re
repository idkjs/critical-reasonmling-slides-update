[@bs.val] [@bs.scope "Prism"] external highlightAll: unit => unit;

[@react.component]
let make = (~highlight="", ~textSize="", ~source) => {
  React.useEffect0(() => {
    highlightAll();
    None;
  });
  ReasonReact.cloneElement(
    <pre className="language-reason" />,
    ~props={
      "data-line": highlight,
      "style": ReactDOMRe.Style.make(~fontSize=textSize, ()),
    },
    [|<code className="language-reason"> {React.string(source)} </code>|],
  );
};
