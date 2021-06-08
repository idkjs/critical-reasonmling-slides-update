[@react.component]
let make = () =>
  <SlideSet>
    <Slide id="the-end">
      <Heading size=1> {React.string("The End")} </Heading>
    </Slide>
    <Slide id="the-end-jk">
      <Heading size=1> {React.string("The End?")} </Heading>
    </Slide>
  </SlideSet>;
