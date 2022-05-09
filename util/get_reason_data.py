import particle

OUTPUT_FILE_NAME = "../src/data/ParticleData.res"


def escape_latex(txt):
    return txt.replace("\\", "\\\\")


def quoted(str):
    return f'"{str}"'


def option(val, quote=False):
    if val is not None:
        if quote:
            return f"Some({quoted(val)})"

        return f"Some({val})"
    return "None"


def write_particle(particle_file, p: particle.Particle):

    anti = "true" if p.anti_flag else "false"

    particle_file.write(
        "\n".join(
            [
                f"  {{",
                f"    pdg: {int(p.pdgid)},",
                f"    name: {quoted(p.name)},",
                f"    mass: {option(p.mass)},",
                f"    width: {option(p.width)},",
                f"    charge: {option(p.charge)},",
                f"    iValue: {option(p.I)},",
                f"    gValue: {int(p.G)},",
                f"    cValue: {int(p.C)},",
                f"    pValue: {int(p.P)},",
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
                    " *",
                    " * Do not hand edit! This is pre-generated!",
                    " *",
                    f" * Generated using particle v{particle.__version__}.",
                    " */",
                    "",
                    "open ParticleInfo",
                    "",
                    "let data = [",
                    "",
                ]
            )
        )

        for _, p in enumerate(particle.Particle.all()):
            write_particle(particle_file, p)

        particle_file.write("\n".join(["]", "",]))


if __name__ == "__main__":
    main()
