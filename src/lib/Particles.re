

let electron = ParticleInfo.{
  pdg: 11,
  name: "Electron",
  mass: 0.5109989461,
  charge: 1,
  anti: false,
  latex: "e^-",
  eventGenName: "e-",
};

let muon = ParticleInfo.{
  pdg: 13,
  name: "Muon",
  mass: 105.6583745,
  charge: -3,
  anti: false,
  latex: "\\mu^-",
  eventGenName: "mu-",
};

let photon = ParticleInfo.{
  pdg: 22,
  name: "Photon",
  mass: 0.0,
  charge: 0,
  anti: false,
  latex: "\\gamma",
  eventGenName: "gamma",
};

let pion = ParticleInfo.{
  pdg: 211,
  name: "Pion",
  mass: 139.57039,
  charge: 3,
  anti: false,
  latex: "\\pi^+",
  eventGenName: "pi+",
};

let particles = [|electron, muon, photon, pion|];
let particleMap = ParticleInfo.makeMap(particles);