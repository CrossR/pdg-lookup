type t =
  | ParticleFound(option(int));

let fromUrl = (url: ReasonReactRouter.url) =>
  switch (url.path) {
  | [] => Some(ParticleFound(Some(11)))
  | [i] => Some(ParticleFound(Belt.Int.fromString(i)))
  | _ => None
  };

type t';

external make: string => t' = "%identity";
external toString: t' => string = "%identity";

let home = "/"->make;
