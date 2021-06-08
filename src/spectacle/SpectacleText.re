[@bs.module "spectacle"] [@react.component]
external make:
  (
    ~textSize: string=?,
    ~textColor: string=?,
    ~padding: string=?,
    ~fit: bool=?,
    ~children: React.element
  ) =>
  React.element =
  "Text";
