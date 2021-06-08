[@bs.module "spectacle"] [@react.component]
external make:
  (
    ~lang: string,
    ~source: string,
    ~textSize: string,
    ~children: React.element
  ) =>
  React.element =
  "CodePane";
