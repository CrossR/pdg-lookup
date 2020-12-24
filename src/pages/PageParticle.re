module Styles = {
  open Css;

  let parentBlock =
    style([overflow(`hidden), display(`flex), alignItems(`center)]);

  let nameBlock = style([display(`initial), float(`left)]);
};

type state = {
  search: string,
  result: option(PdgLookup.ParticleInfo.t)
};

let lookupParticle = (state, action) => {
  switch (Belt.Int.fromString(action)) {
    | Some(pdg) => {...state, result: Belt.Map.Int.get(ParticleData.particleMap, pdg)}
    | None => {...state, result: None}
  }
};

[@react.component]
let make = () => {

  let (state, dispatch) = React.useReducer((s, a) => lookupParticle(s, a), {search: "", result: None});

  switch (state.result) {
  | Some(particle) => 
    <div>
      <div> <Search dispatch/> </div>
      <div className=Styles.parentBlock>
        <div className=Styles.nameBlock> <LatexName particle/> </div>
        <div> <InfoTable particle/> </div>
      </div>
    </div>
  | None =>
    <div>
      <div> <Search dispatch/> </div>
    </div>
  }
};
