[@react.component]
let make = (~pdg) => {
  let pdg =
    switch (pdg) {
    | Some(pdg) => pdg
    | None => 11
    };
  switch (Belt.Map.Int.get(Particles.particleMap, pdg)) {
  | Some(p) => <Particle particle=p />
  | None =>
    <Particle particle={Belt.Map.Int.getExn(Particles.particleMap, 11)} />
  };
};
