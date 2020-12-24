module Styles = {
  open Css;

  let parentBlock =
    style([overflow(`hidden), display(`flex), alignItems(`center)]);

  let nameBlock =
    style([display(`initial), float(`left), paddingRight(`px(25))]);
};

type state = {
  search: string,
  result: option(PdgLookup.ParticleInfo.t),
};

let lookupParticle = (_, search) => {
  switch (Belt.Int.fromString(search)) {
  | Some(pdg) => {
      search,
      result: Belt.Map.Int.get(ParticleData.particleMap, pdg),
    }
  | None => {search, result: None}
  };
};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (s, a) => lookupParticle(s, a),
      {search: "", result: None},
    );

  switch (state.result) {
  | Some(particle) =>
    <div>
      <div> <Search dispatch /> </div>
      <div className=Styles.parentBlock>
        <div className=Styles.nameBlock> <LatexName particle /> </div>
        <div> <InfoTable particle /> </div>
      </div>
    </div>
  | None => <div> <div> <Search dispatch /> </div> </div>
  };
};
