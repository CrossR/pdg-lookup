type t = {
  pdg: int,
  name: string,
  latex: string,
  mass: option<float>,
  width: option<float>,
  charge: option<float>,
  iValue: option<float>,
  gValue: int,
  cValue: int,
  pValue: int,
  anti: bool,
}

let getPdg = particle => particle.pdg
let getName = particle => particle.name
let getMass = particle => particle.mass
let getWidth = particle => particle.width
let getCharge = particle => particle.charge
let getI = particle => particle.iValue
let getG = particle => particle.gValue
let getC = particle => particle.cValue
let getP = particle => particle.pValue
let isAnti = particle => particle.anti
let getLatex = particle => "\\(" ++ (particle.latex ++ "\\)")
let getRawLatex = particle => particle.latex

let invert = (particle, particles) => Belt.Map.Int.get(particles, -1 * getPdg(particle))

let getPdgName = particle =>
  "PDG " ++ (Belt.Int.toString(getPdg(particle)) ++ (": " ++ getName(particle)))

let getUnknownQuantity = quantity =>
  switch quantity {
  | Some(m) => Belt.Float.toString(m)
  | None => " ?"
  }

type propertyValue = {
  property: string,
  value: string,
  units: option<string>,
}

let makeProperty = ((property, value, units)) => {property, value, units}

let getProperties = p =>
  [
    ("PDG", Belt.Int.toString(getPdg(p)), None),
    ("Mass", getUnknownQuantity(getMass(p)), Some("MeV")),
    ("Charge", getUnknownQuantity(getCharge(p)), None),
    ("Width", getUnknownQuantity(getWidth(p)), None),
    ("I", getUnknownQuantity(getI(p)), None),
    ("G", Belt.Int.toString(getG(p)), None),
    ("C", Belt.Int.toString(getC(p)), None),
    ("P", Belt.Int.toString(getP(p)), None),
  ]->Array.map(x => makeProperty(x))
