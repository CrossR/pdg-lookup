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
  <MaterialUi_ThemeProvider theme={MaterialUi_Theme.create(MaterialUi_ThemeOptions.make())}>
    <input
      className={invalidSearch ? Styles.invalidSeachField : Styles.searchField}
      type_="search"
      autoFocus=true
      placeholder="Input PDG"
      onChange={e => dispatch((e->ReactEvent.Form.target)["value"])}
    />
  </MaterialUi_ThemeProvider>
