module Styles = {
  open Css;

  let parentBlock =
    style([overflow(`hidden), display(`flex), alignItems(`center)]);

  let nameBlock = style([display(`initial), float(`left)]);
};
[@react.component]
let make = (~pdg) => {
  let currentParticle =
    switch (pdg) {
    | Some(pdgCode) => Belt.Map.Int.get(ParticleData.particleMap, pdgCode)
    | None => None
    };

  switch (currentParticle) {
  | None => <div />
  | Some(particle) =>
    <div className=Styles.parentBlock>
      <div className=Styles.nameBlock> <LatexName particle /> </div>
      <div> <InfoTable particle /> </div>
    </div>
  };
};
