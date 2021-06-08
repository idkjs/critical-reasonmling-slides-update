let snippet = {js|
module School = {
  type profession = Teacher | Director;
  let getProfession = person =>
    switch person {
    | Teacher => "A teacher"
    | Director => "A director"
    };
};

let mrFoobar = School.Teacher;
School.getProfession(mrFoobar) |> print_endline;
/* "A teacher" */
|js};
[@react.component]
let make = () =>
  <Slide id="module-intro" maxWidth="800px">
    <style>
      {React.string(
         {js|
          li {
            font-size: inherit !important;
          }
          ul {
            line-height: 2 !important;
            margin: auto !important;
            max-width: 90%;
          }
          img {
            transform: translateY(15px) translateX(10px);
          }
        |js},
       )}
    </style>
    <Heading size=1> {React.string("Modules")} </Heading>
    <br />
    <List_ textSize="25px">
      <Appear>
        <ListItem> {React.string("Every file is a module.")} </ListItem>
      </Appear>
      <Appear>
        <ListItem>
          {React.string("Modules can contain other modules")}
        </ListItem>
      </Appear>
      <Appear>
        <ListItem>
          {React.string("Module interfaces can be defined separately")}
        </ListItem>
      </Appear>
      <Appear>
        <ListItem>
          {React.string("Functors (functions for modules)")}
        </ListItem>
      </Appear>
    </List_>
  </Slide>;
