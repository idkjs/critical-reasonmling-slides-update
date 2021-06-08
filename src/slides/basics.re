let ranges: Js.Array.t(CodeSlide.range) = [|
  {loc: [|1, 15|]},
  {loc: [|2, 7|]},
  {loc: [|8, 11|]},
  {loc: [|12, 13|]},
|];
[@react.component]
let make = () =>
  <SlideSet>
    <Slide id="basics">
      <Heading size=1> {React.string("The Basics")} </Heading>
      <Heading size=4> {React.string("By Example")} </Heading>
    </Slide>
    <CodeSlide code=Snippets.basics ranges />
  </SlideSet>;
