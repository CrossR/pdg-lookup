module Styles = {
  open Css;

  let searchField = style([width(`percent(100.)), paddingLeft(`percent(10.)), paddingRight(`percent(10.))]);
};

[@react.component]
let make = (~dispatch) => {

  <MaterialUi_ThemeProvider
    theme={MaterialUi_Theme.create(MaterialUi_ThemeOptions.make())}>
    {MaterialUi.(
       <TextField
         className=Styles.searchField
         label={React.string("")}
         placeholder="Input PDG"
         _type="search"
         onChange={e => dispatch(e->ReactEvent.Form.target##value)}
       />
     )}
  </MaterialUi_ThemeProvider>;
};
