# PDG Lookup

[![Actions Status](https://github.com/CrossR/pdg-lookup/workflows/CI/badge.svg)](https://github.com/CrossR/pdg-lookup/actions)

PDG Code Lookup

## Licensing / Acknowledgements

PDG Lookup is powered using data from the scikit-hep Particle project found
here: https://github.com/scikit-hep/particle, though there is no association
between the two projects. Data used in accordance with their license, which
can be found here: https://github.com/scikit-hep/particle/blob/master/LICENSE.

The `particle` project was used to create Reason objects, which are in turn
compiled to JS objects for display here. The simple python script for that
can be found in `util/`. (If you are confused as to why this was approach
was used, rather than a database/active lookup, this meant the project
could be more easily hosted as a static site. Its also very quick once the
data is cached!).

The GitHub Corner SVG is from https://github.com/tholman/github-corners,
licensed under the MIT license.

## Contributing

Take a look at our [Contributing Guide](CONTRIBUTING.md).
