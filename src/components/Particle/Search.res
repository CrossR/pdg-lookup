open Mui

module Styles = {
  open Css

  let baseStyle = list{
    fontSize(#em(3.)),
    width(#percent(100.)),
    borderTopWidth(#zero),
    borderLeftWidth(#zero),
    borderRightWidth(#zero),
    outlineStyle(#none),
    backgroundColor(#transparent),
  }
  let searchField = style(list{borderBottomColor(#hex("ffffff")), ...baseStyle})

  let invalidSeachField = style(list{borderBottomColor(#hex("ff6961")), ...baseStyle})
}

@react.component
let make = (~dispatch, ~invalidSearch) =>
  <ThemeProvider theme={Theme(Theme.create({}))}>
    <input
      className={invalidSearch ? Styles.invalidSeachField : Styles.searchField}
      type_="search"
      autoFocus=true
      placeholder="Search with PDG Number or Name"
      onChange={e => dispatch((e->ReactEvent.Form.target)["value"])}
    />
  </ThemeProvider>
