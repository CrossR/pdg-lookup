module Styles = {
  open Css;

  let latexText =
    style([
      display(`initial),
      fontSize(`percent(500.)),
      color(hex("1a202c")),
    ]);
};

[@bs.val]
external katexRenderToString: string => string = "katex.renderToString";

[@react.component]
let make = (~particle) => {
  let rawLatex = ParticleInfo.getRawLatex(particle);

  <MaterialUi_ThemeProvider
    theme={MaterialUi_Theme.create(MaterialUi_ThemeOptions.make())}>
    <div
      className=Styles.latexText
      title=rawLatex
      dangerouslySetInnerHTML={"__html": katexRenderToString(rawLatex)}
    />
  </MaterialUi_ThemeProvider>;
};
