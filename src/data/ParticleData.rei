let particlePdgMap: Belt.Map.Int.t(ParticleInfo.t);
let getWithPDG: int => option(ParticleInfo.t);

let particleNameMap: Belt.Map.String.t(ParticleInfo.t);
let getWithName: string => option(ParticleInfo.t);
