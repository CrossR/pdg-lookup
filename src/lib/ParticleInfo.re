type t = {
  pdg: int,
  name: string,
  latex: string,
  mass: option(float),
  width: option(float),
  charge: option(float),
  iValue: option(float),
  gValue: int,
  cValue: int,
  pValue: int,
  anti: bool,
};

let makeMap = particles => {
  let pdgCodes = Belt.Array.map(particles, p => p.pdg);
  Belt.Map.Int.fromArray(Belt.Array.zip(pdgCodes, particles));
};

let getPdg = particle => particle.pdg;
let getName = particle => particle.name;
let getMass = particle => particle.mass;
let getCharge = particle => particle.charge;
let isAnti = particle => particle.anti;
let getLatex = particle => "\\(" ++ particle.latex ++ "\\)";
let getRawLatex = particle => particle.latex;

let getPdgName = particle => {
  "PDG " ++ Belt.Int.toString(getPdg(particle)) ++ ": " ++ getName(particle)
};

let getUnknownQuantity = quantity =>
  switch (quantity) {
  | Some(m) => Belt.Float.toString(m)
  | None => "?"
  };

let getInfoPairsForGrid = p => {
  MaterialUi_Grid.Xs.(
  [|
    (("Mass", getUnknownQuantity(getMass(p)) ++ " MeV"), (_1, _3)),
    (("Charge", getUnknownQuantity(getCharge(p))), (_1, _1)),
  |]
  )
};
