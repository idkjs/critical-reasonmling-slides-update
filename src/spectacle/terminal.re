[@bs.module "spectacle-terminal"] [@react.component]
external make:
  (
    ~output: Js.Array.t(React.element),
    ~title: string,
    ~children: React.element
  ) =>
  React.element =
  "SlideSet";
