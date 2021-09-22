type t = Particle

let fromUrl = (_: ReasonReactRouter.url) => Some(Particle)

type t'

external make: string => t' = "%identity"
external toString: t' => string = "%identity"

let home = "/"->make
