module Styles = {
  open Css

  let latexText = style(list{display(#initial), fontSize(#rem(5.)), color(hex("1a202c"))})
}

@val
external katexRenderToString: string => string = "katex.renderToString"

@react.component
let make = (~particle) => {
  let rawLatex = ParticleInfo.getRawLatex(particle)

  <div
    className=Styles.latexText
    title=rawLatex
    dangerouslySetInnerHTML={"__html": katexRenderToString(rawLatex)}
  />
}
