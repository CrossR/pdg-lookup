module Styles = {
  open Css;

  let latexText =
    style([
      display(`initial),
      fontSize(rem(5.0)),
      color(hex("1a202c")),
    ]);
};

[@react.component]
let make = (~particle) => {
  <MaterialUi_ThemeProvider
    theme={MaterialUi_Theme.create(MaterialUi_ThemeOptions.make())}>
      <p className=Styles.latexText>
        {React.string(ParticleInfo.getLatex(particle))}
      </p>
  </MaterialUi_ThemeProvider>;
};
