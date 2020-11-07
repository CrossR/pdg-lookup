type t = {
  pdg: int,
  name: string,
  mass: float,
  charge: int,
  anti: bool,
  latex: string,
  eventGenName: string,
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

let getInfoPairs = p => {
  [|
    ("PDG Code", p |> getPdg |> Belt.Int.toString),
    ("Name", getName(p) ++ " (" ++ getEventGenName(p) ++ ")"),
    ("Mass", p |> getMass |> Belt.Float.toString),
    ("Charge", p |> getCharge |> Belt.Int.toString),
  |];
};
