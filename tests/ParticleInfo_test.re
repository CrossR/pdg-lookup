open Jest;
open Expect;

describe("Particle Info Test", () => {
  test("Can find result with PDG", () => {
    switch (ParticleData.getWithPDG(11)) {
    | Some(p) => expect(ParticleInfo.getName(p)) |> toEqual("e-")
    | None => fail("Particle not found with PDG")
    }
  });

  test("Can find result with Name", () => {
    switch (ParticleData.getWithName("e-")) {
    | Some(p) => expect(ParticleInfo.getPdg(p)) |> toEqual(11)
    | None => fail("Particle not found with its name")
    }
  });

  test("Can get inverted particle", () => {
    let electron = Belt.Map.String.getExn(ParticleData.particleNameMap, "e-");

    switch (ParticleInfo.invert(electron, ParticleData.particlePdgMap)) {
    | Some(p) => expect(ParticleInfo.getName(p)) |> toEqual("e+")
    | None => fail("Can't find positron")
    };
  });
});
