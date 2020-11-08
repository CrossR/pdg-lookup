from particle import Particle

OUTPUT_FILE_NAME = "../src/data/ParticleData.re"


def escape_latex(txt):
    return txt.replace("\\", "\\\\")


def quoted(str):
    return f'"{str}"'


def option(val, quote=False):
    if val:
        if quote:
            return f"Some({quoted(val)})"

        return f"Some({val})"
    return "None"


def wrap_minus(num):
    if num < 0:
        return f"({num})"
    return num


def write_particle(particle_file, p: Particle):

    anti = "true" if p.anti_flag else "false"

    particle_file.write(
        "\n".join(
            [
                f"  {{",
                f"    pdg: {wrap_minus(int(p.pdgid))},",
                f"    name: {quoted(p.name)},",
                f"    mass: {option(p.mass)},",
                f"    width: {option(p.width)},",
                f"    charge: {option(p.charge)},",
                f"    iValue: {option(p.I)},",
                f"    gValue: {wrap_minus(int(p.G))},",
                f"    cValue: {wrap_minus(int(p.C))},",
                f"    pValue: {wrap_minus(int(p.P))},",
                f"    anti: {anti},",
                f"    latex: {quoted(escape_latex(p.latex_name))},",
                f"  }},",
                "",
            ]
        )
    )


def main():
    with open(OUTPUT_FILE_NAME, "w") as particle_file:

        particle_file.write(
            "\n".join(
                [
                    "/*",
                    " * Particle data records, produced from scikit-hep Particle",
                    " * library using script in util/.",
                    " */",
                    "",
                    "open ParticleInfo;",
                    "",
                    "let data = [|",
                    "",
                ]
            )
        )

        for i, p in enumerate(Particle.all()):
            write_particle(particle_file, p)

        particle_file.write(
            "\n".join(["|];", "let particleMap = ParticleInfo.makeMap(data);", ""])
        )


if __name__ == "__main__":
    main()
