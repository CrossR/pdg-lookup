type t = Particle

let fromUrl = (_: RescriptReactRouter.url) => Some(Particle)

type t'

external make: string => t' = "%identity"
external toString: t' => string = "%identity"

let home = "/"->make
