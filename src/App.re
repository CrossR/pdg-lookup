[@react.component]
let make = () => {
  let route = Router.useRouter();

  switch (route) {
  | Some(ParticleFound(pdg)) => <PageParticle pdg />
  | None => <PageNotFound />
  };
};
