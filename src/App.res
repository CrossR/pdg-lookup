@get external style: Dom.element => Dom.cssStyleDeclaration = "style"
@set
external setColour: (Dom.cssStyleDeclaration, string) => unit = "background-color"

let backgroundColours = ["#FFCE9D", "#FFE8BC", "#AEE2D3", "#80CCD0", "#72A7C7", "#E9D2E0"]

let getRandomColour = () =>
  Array.getUnsafe(backgroundColours, Random.int(Array.length(backgroundColours)))

@react.component
let make = () => {
  let route = Router.useRouter()

  Random.self_init()

  switch ReactDOM.querySelector("body") {
  | Some(element) => setColour(style(element), getRandomColour())
  | None => ()
  }

  switch route {
  | Some(Particle) => <PageParticle />
  | None => <PageNotFound />
  }
}
