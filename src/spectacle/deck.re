[@bs.module "spectacle"] [@react.component]
external make:
  (~theme: Theme.t, ~controls: bool=?, ~children: React.element) =>
  React.element =
  "Deck";
