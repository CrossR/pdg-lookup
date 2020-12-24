[@react.component]
let make = () => {
  let route = Router.useRouter();

  switch (route) {
  | Some(Particle) => <PageParticle />
  | None => <PageNotFound />
  };
};
