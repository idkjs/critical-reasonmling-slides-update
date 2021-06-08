type cursor = {show: bool};

[@bs.module "react-typist"] [@react.component]
external make:
  (~cursor: cursor=?, ~avgTypingDelay: int=?, ~children: React.element) =>
  React.element =
  "default";
