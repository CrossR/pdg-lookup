# PDG Code Lookup

[![Actions Status](https://img.shields.io/github/workflow/status/CrossR/pdg-lookup/CI)](https://github.com/CrossR/pdg-lookup/actions)
[![Website Status](https://img.shields.io/website?url=https%3A%2F%2Fcrossr.github.io%2Fpdg-lookup%2F)](https://crossr.github.io/pdg-lookup/)
[![MIT license](https://img.shields.io/badge/License-MIT-blue.svg)](https://lbesson.mit-license.org/)

![Website Preview](https://user-images.githubusercontent.com/10038688/111888833-06812400-89d8-11eb-949e-a34ecf859b16.png)

A simple website to lookup particle data using Particle Data Group (PDG) codes.
Also accepts searches via name, and returns back some common particle properties,
assuming they are currently known.

Was created out of a need for the occasional search of some obscure PDG appearing
in MC results, and not wanting to poke around the PDG website or random old websites
that Google seems to promote for some reason.

Uses the 2020 PDG Code Data, from https://pdg.lbl.gov/. Further detail of how
the data is built up is below.

## Licensing / Acknowledgements

PDG Lookup is powered using data from the scikit-hep Particle project found
here: https://github.com/scikit-hep/particle, though there is no association
between the two projects. Data used in accordance with their license, which
can be found here: https://github.com/scikit-hep/particle/blob/master/LICENSE.

The `particle` project was used to create Reason objects, which are in turn
compiled to JS objects for display here. The simple python script for that
can be found in `util/`.

If you are confused as to why this was approach was used, rather than a
database/active lookup, this meant the project could be more easily hosted as
a static site (which is free with GitHub Pages). Its also very quick once the
data is cached!

The GitHub Corner SVG is from https://github.com/tholman/github-corners,
licensed under the MIT license.

## Contributing

Take a look at our [Contributing Guide](CONTRIBUTING.md).
