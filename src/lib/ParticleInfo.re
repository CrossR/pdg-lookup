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
let getI = particle => particle.iValue;
let getG = particle => particle.gValue;
let getC = particle => particle.cValue;
let getP = particle => particle.pValue;
let isAnti = particle => particle.anti;
let getLatex = particle => "\\(" ++ particle.latex ++ "\\)";
let getRawLatex = particle => particle.latex;

let getPdgName = particle => {
  "PDG " ++ Belt.Int.toString(getPdg(particle)) ++ ": " ++ getName(particle);
};

let getUnknownQuantity = quantity =>
  switch (quantity) {
  | Some(m) => Belt.Float.toString(m)
  | None => " ?"
  };

let getNameValuePair = p => {
  [|
    ("Mass", getUnknownQuantity(getMass(p))),
    ("Charge", getUnknownQuantity(getCharge(p))),
    ("I", getUnknownQuantity(getI(p))),
    ("G", getG(p) |> Belt.Int.toString),
    ("C", getC(p) |> Belt.Int.toString),
    ("P", getP(p) |> Belt.Int.toString),
  |];
};
