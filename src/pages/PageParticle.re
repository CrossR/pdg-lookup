module Styles = {
  open Css;

  let topLevelBlock =
    style([
      display(`flex),
      justifyContent(`center),
      flexDirection(`column),
      paddingTop(`percent(20.)),
      marginLeft(`percent(15.)),
      marginRight(`percent(15.)),
    ]);

  let resultBlock =
    style([overflow(`hidden), display(`flex), flexWrap(`wrap),justifyContent(`center)]);

  let nameBlock =
    style([
      display(`flex),
      alignItems(`center),
      Css.float(`left),
      paddingRight(`px(15)),
      paddingTop(`px(5)),
    ]);
};

type state = {
  search: string,
  result: option(PdgLookup.ParticleInfo.t),
};

let lookupParticle = (_, search) => {
  switch (Belt.Int.fromString(search)) {
  | Some(pdg) => {search, result: ParticleData.getWithPDG(pdg)}
  | None => {search, result: ParticleData.getWithName(search)}
  };
};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (s, a) => lookupParticle(s, a),
      {search: "", result: None},
    );

  <>
    <Header />
    <div className=Styles.topLevelBlock>
      <div> <Search dispatch /> </div>
      {switch (state.result) {
       | Some(particle) =>
         <div className=Styles.resultBlock>
           <div className=Styles.nameBlock> <LatexName particle /> </div>
           <div> <InfoTable particle /> </div>
         </div>
       | None => React.null
       }}
    </div>
  </>;
};
