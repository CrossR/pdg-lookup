/*
 * Functions to interface with the giant particle data array with.
 */

let makePdgMap = particles => {
  let pdgCodes = Belt.Array.map(particles, p => p.ParticleInfo.pdg);
  Belt.Map.Int.fromArray(Belt.Array.zip(pdgCodes, particles));
};

let makeNameMap = particles => {
  let names =
    Belt.Array.map(particles, p =>
      String.lowercase_ascii(p.ParticleInfo.name)
    );
  Belt.Map.String.fromArray(Belt.Array.zip(names, particles));
};

let particlePdgMap = makePdgMap(ParticleData.data);
let getWithPDG = pdg => Belt.Map.Int.get(particlePdgMap, pdg);
let particleNameMap = makeNameMap(ParticleData.data);
let getWithName = name => {
  let lowerName = String.lowercase_ascii(name);

  switch (Belt.Map.String.get(particleNameMap, lowerName)) {
  | Some(p) => Some(p)
  | None =>
    switch (Belt.Map.String.get(ParticleNames.namePDGMap, lowerName)) {
    | Some(pdg) => getWithPDG(pdg)
    | None => None
    }
  };
};
