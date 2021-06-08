module Slide = {
  [@bs.module "spectacle"] [@react.component]
  external make:
    (
      ~id: string,
      ~align: string=?,
      ~maxWidth: string=?,
      ~style: ReactDOMRe.Style.t,
      ~children: React.element
    ) =>
    React.element =
    "Slide";
};
[@react.component]
let make =
    (
      ~id: string,
      ~align: string="center center",
      ~maxWidth: string="1000px",
      ~children,
    ) => {
  let style =
    ReactDOMRe.Style.make(
      ~maxWidth,
      ~left="0px",
      ~right="0px",
      ~margin="auto",
      (),
    );
  <Slide style id align> children </Slide>;
};
