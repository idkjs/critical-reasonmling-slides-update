[@react.component]
let make = () =>
  <Slide id="rtop">
    <Heading size=1> {React.string("rtop")} </Heading>
    <br />
    <Link href="https://github.com/reasonml/reason-tools">
      {React.string("https://github.com/reasonml/reason-tools")}
    </Link>
    <br />
    <br />
    <Image src=Assets.repl width="80%" />
  </Slide>;
