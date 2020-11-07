module Styles = {
  open Css;

  let container = style([textAlign(center), marginTop(rem(3.))]);

  let text =
    style([
      fontSize(rem(1.875)),
      color(hex("1a202c")),
      marginBottom(rem(1.)),
    ]);

  let link =
    style([
      fontSize(rem(1.875)),
      textDecoration(`none),
      color(hex("4299e1")),
    ]);
};

[@react.component]
let make = (~particle) => {
  <div className=Styles.container>
    <p className=Styles.text>
      {React.string(ParticleInfo.getName(particle))}
    </p>
    <p className=Styles.text>
      {React.string("\\(" ++ ParticleInfo.getLatex(particle) ++ "\\)")}
    </p>
  </div>;
};
