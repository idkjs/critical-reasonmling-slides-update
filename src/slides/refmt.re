[@react.component]
let make = () =>
  <Slide id="refmt">
    <Heading size=1> {React.string("refmt")} </Heading>
    <br />
    <Link href="https://reasonml.github.io/guide/editor-tools/extra-goodies">
      {React.string(
         "https://reasonml.github.io/guide/editor-tools/extra-goodies",
       )}
    </Link>
    <br />
    <br />
    <Image src=Assets.refmt width="80%" />
  </Slide>;
