[@bs.val] external document: Dom.document = "document";
[@bs.get] external style: Dom.element => Dom.cssStyleDeclaration = "style";
[@bs.set]
external setColour: (Dom.cssStyleDeclaration, string) => unit =
  "background-color";

let backgroundColours = [
  "#FFCE9D", "#FFE8BC", "#AEE2D3", "#80CCD0", "#72A7C7", "#E9D2E0"
];
let getRandomColour = () =>
  switch (
    List.get(
      backgroundColours,
      Random.int(List.length(backgroundColours)),
    )
  ) {
  | Some(c) => c
  | None => "#779ECC"
  };

[@react.component]
let make = () => {
  let route = Router.useRouter();

  Random.self_init();
  switch (Webapi.Dom.Document.querySelector("body", document)) {
  | Some(element) => setColour(style(element), getRandomColour())
  | None => ()
  };

  switch (route) {
  | Some(Particle) => <PageParticle />
  | None => <PageNotFound />
  };
};
