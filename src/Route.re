type t =
  | Home(option(int));

let fromUrl = (url: ReasonReactRouter.url) =>
  switch (url.path) {
  | [] => Some(Home(Some(11)))
  | [i] => Some(Home(Belt.Int.fromString(i)))
  | _ => None
  };

type t';

external make: string => t' = "%identity";
external toString: t' => string = "%identity";

let home = "/"->make;
