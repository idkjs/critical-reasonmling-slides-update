type range = {loc: Js.Array.t(int)};

[@bs.module "spectacle-code-slide"] [@react.component]
external make: (~code: string, ~ranges: Js.Array.t(range)) => React.element =
  "default";
