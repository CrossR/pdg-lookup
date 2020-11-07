1) Write Particle.re -> Type to store params, few helpers to move between particles.
2) Component for particle to React elem
    b) Quick debug stop, show a hard coded particle.
3) Tiny python script for datafile to re List[t]. Probably quickest way.
    b) Will need to benchmark that...loading 1 giant thing could be worse than
        dynamic parsing of the raw file.
4) Component for Input Box
5) Add the actual interaction : Input -> clean input -> <Particle pdg=11>
6) Styling pass.

Files:

component
        | Particle.re
        | PdgInput.re

util
    | convert.py

lib
    | Particle.re
    | Particles.re

assets
      | conversion.csv