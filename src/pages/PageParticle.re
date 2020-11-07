[@react.component]
let make = (~pdg) => {
  switch (pdg) {
  | Some(pdgCode) => switch (Belt.Map.Int.get(ParticleData.particleMap, pdgCode)) {
    | Some(p) => <Particle particle=p />
    | None =>
      <Particle
        particle={Belt.Map.Int.getExn(ParticleData.particleMap, 11)}
      />
  };
  | None =>
    <Particle
      particle={Belt.Map.Int.getExn(ParticleData.particleMap, 11)}
    />
  };
};
