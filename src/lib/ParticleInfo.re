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
let geCharge = particle => particle.charge;
let isAnti = particle => particle.anti;
let getLatex = particle => particle.latex;
let getEventGenName = particle => particle.eventGenName;

let electron = {
  pdg: 11,
  name: "Electron",
  mass: 0.5109989461,
  charge: 1,
  anti: false,
  latex: "e^-",
  eventGenName: "e",
};
