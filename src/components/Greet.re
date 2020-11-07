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
let make = (~name) => {
  <div className=Styles.container>
    <p className=Styles.text>
      {React.string({j|👋 Welcome $name! You can edit me in |j})}
      <code> {React.string("src/components/Greet.re")} </code>
    </p>
    <a
      className=Styles.link
      href="https://reasonml.github.io/reason-react/">
      {React.string("Learn Reason React")}
    </a>
  </div>;
};
