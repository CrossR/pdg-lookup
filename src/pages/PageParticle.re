[@react.component]
let make = (~pdg) => {
  switch (Belt.Map.String.get(Particles.particleMap, pdg)) {
  | Some(p) => <Particle particle=p />
  | None =>
    <Particle
      particle={Belt.Map.String.getExn(Particles.particleMap, "11")}
    />
  };
};
