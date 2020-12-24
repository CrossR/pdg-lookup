module Styles = {
  open Css;

  let searchText = style([fontSize(rem(5.0))]);
};

[@react.component]
let make = (~dispatch) => {

  <MaterialUi_ThemeProvider
    theme={MaterialUi_Theme.create(MaterialUi_ThemeOptions.make())}>
    {MaterialUi.(
       <TextField
         label={React.string("")}
         placeholder="Input PDG"
         _type="search"
         onChange={e => dispatch(e->ReactEvent.Form.target##value)}
       />
     )}
  </MaterialUi_ThemeProvider>;
};
