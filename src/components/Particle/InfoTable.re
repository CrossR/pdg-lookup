module Styles = {
  open Css;

  let infoBlock = style([Css.float(`left), maxWidth(`px(250))]);

  let infoLineName = style([textAlign(`left), fontWeight(`semiBold)]);
  let infoLineProp = style([textAlign(`left)]);
};

let getTableRow = namePropetryPair => {
  let name = fst(namePropetryPair);
  let property = snd(namePropetryPair);

  MaterialUi.(
    <TableRow>
      <TableCell variant=`Head> name </TableCell>
      <TableCell> property </TableCell>
    </TableRow>
  );
};

[@react.component]
let make = (~particle) => {
  <MaterialUi_ThemeProvider
    theme={MaterialUi_Theme.create(MaterialUi_ThemeOptions.make())}>
    {MaterialUi.(
       <div className=Styles.infoBlock>
         <Table size=`Small>
           <TableBody>
             {ParticleInfo.getNameValuePair(particle)
              ->Belt.Array.map(pair => getTableRow(pair))
              ->React.array}
           </TableBody>
         </Table>
       </div>
     )}
  </MaterialUi_ThemeProvider>;
};
