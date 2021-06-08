[@react.component]
let make = () =>
  <Slide id="reason-tools">
    <Heading size=1> {React.string("Thanks!")} </Heading>
    <br />
    <Heading size=5> {React.string("Slides (written in Reason!)")} </Heading>
    <Link href="https://github.com/aweary/critical-reasonmling-slides">
      {React.string("https://github.com/aweary/critical-reasonmling-slides")}
    </Link>
    <br />
    <br />
    <Image src=Assets.reasonTools width="80%" />
  </Slide>;
