[@react.component]
let make = () => {
  let route = Router.useRouter();

  switch (route) {
  | Some(Home(pdg)) => <PageHome pdg />
  | None => <PageNotFound />
  };
};
