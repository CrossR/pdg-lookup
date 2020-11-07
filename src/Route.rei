type t =
  | Home(option(int));

let fromUrl: ReasonReactRouter.url => option(t);

type t';

external toString: t' => string = "%identity";

let home: t';
