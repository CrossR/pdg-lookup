type t = {
  pdg: int,
  name: string,
  mass: option(float),
  charge: option(float),
  anti: bool,
  latex: string,
  eventGenName: option(string),
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
let getEventGenName = particle => particle.eventGenName;

let getFullName = particle => {
  switch (getEventGenName(particle)) {
  | Some(e) => getName(particle) ++ " (" ++ e ++ ")"
  | None => getName(particle)
  };
};

let getUnknownQuantity = quantity =>
  switch (quantity) {
  | Some(m) => Belt.Float.toString(m)
  | None => "?"
  };

let getInfoPairs = p => {
  [|
    ("PDG Code", p |> getPdg |> Belt.Int.toString),
    ("Name", getFullName(p)),
    ("Mass", getUnknownQuantity(getMass(p)) ++ " MeV"),
    ("Charge", getUnknownQuantity(getCharge(p))),
  |];
};
