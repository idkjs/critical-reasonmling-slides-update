let ranges: Js.Array.t(CodeSlide.range) = [|
  {loc: [|0, 1000|]},
  {loc: [|1, 9|]},
  {loc: [|2, 3|]},
  {loc: [|3, 8|]},
  {loc: [|10, 11|]},
  {loc: [|11, 12|]},
|];

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
  /* A teacher */
|js};
[@react.component]
let make = () => <CodeSlide code=snippet ranges />;
