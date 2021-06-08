[@react.component]
let make =
    (
      ~textSize: string="",
      ~textColor: string="",
      ~padding: string="",
      ~fit: bool=false,
      ~children: React.element,
    ) => {
  <SpectacleText textSize textColor padding fit> children </SpectacleText>;
};
