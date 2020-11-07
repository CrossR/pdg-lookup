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
    pdg = p.pdgid.__int__()
    name = p.name
    latex = p.latex_name
    try:
        event_gen_name = p.evtgen_name
    except:
        event_gen_name = None
    mass = p.mass
    charge = p.charge
    anti = "true" if p.anti_flag else "false"

    particle_file.write(
        "\n".join(
            [
                f"  {{",
                f"    pdg: {wrap_minus(pdg)},",
                f"    name: {quoted(name)},",
                f"    mass: {option(mass)},",
                f"    charge: {option(charge)},",
                f"    anti: {anti},",
                f"    latex: {quoted(escape_latex(latex))},",
                f"    eventGenName: {option(event_gen_name, quote=True)},",
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
