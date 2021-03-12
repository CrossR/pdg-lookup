module Styles = {
  open Css;

  let searchField =
    style([
      fontSize(`em(3.)),
      width(`percent(100.)),
      borderTopWidth(`zero),
      borderLeftWidth(`zero),
      borderRightWidth(`zero),
      borderBottomColor(`hex("ffffff")),
      outlineStyle(`none),
      backgroundColor(`transparent),
    ]);
};

[@react.component]
let make = (~dispatch) => {
  <MaterialUi_ThemeProvider
    theme={MaterialUi_Theme.create(MaterialUi_ThemeOptions.make())}>
    <input
      className=Styles.searchField
      type_="search"
      autoFocus=true
      placeholder="Input PDG"
      onChange={e => dispatch(e->ReactEvent.Form.target##value)}
    />
  </MaterialUi_ThemeProvider>;
};
