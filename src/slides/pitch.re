[@react.component]
let make = () =>
  <Slide align="flex-end center" id="pitch">
    /* <Heading size=1> (React.string "The Stack") </Heading> */

      <style>
        {React.string(
           {js|
        img {
          margin-right: 20px !important;
          transform: translateY(10px);
        }
      |js},
         )}
      </style>
      <Layout>
        <Fill>
          <Heading size=5>
            <Image src=Assets.ocamlLogo width="20%" />
            {React.string("The Semantics")}
          </Heading>
          <br />
          <TextSpectacle textSize="20px">
            {React.string("OCaml provides an expressive and dynamic language")}
          </TextSpectacle>
          <br />
        </Fill>
      </Layout>
      <Layout>
        <Fill>
          <Heading size=5>
            <Image src=Assets.reasonLogo width="20%" />
            {React.string("The Syntax")}
          </Heading>
          <br />
          <TextSpectacle textSize="20px">
            {React.string("ReasonML provides a familiar, usable interface")}
          </TextSpectacle>
          <br />
        </Fill>
      </Layout>
      <Layout>
        <Fill>
          <Heading size=5>
            <Image src=Assets.buckleScriptLogo width="10%" />
            {React.string("The Compiler")}
          </Heading>
          <br />
          <TextSpectacle textSize="20px">
            {React.string(
               "BuckleScript compiles OCaml/Reason to clean, accurate JavaScript",
             )}
          </TextSpectacle>
        </Fill>
      </Layout>
    </Slide>;
