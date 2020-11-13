module Styles = {
  open Css;

  let container = style([alignItems(`center), textAlign(`center)]);

  let name = style([fontSize(rem(1.875)), color(hex("1a202c"))]);

  let latexText =
    style([
      fontSize(rem(5.0)),
      color(hex("1a202c")),
      alignItems(`center),
      paddingRight(`px(50)),
    ]);

  let link =
    style([
      fontSize(rem(1.875)),
      textDecoration(`none),
      color(hex("4299e1")),
    ]);

  let latexContainer = style([Css.float(`left), alignItems(`center)]);

  let infoBlock = style([Css.float(`left), maxWidth(`px(250))]);

  let infoLineName = style([textAlign(`left), fontWeight(`semiBold)]);
  let infoLineProp = style([textAlign(`left)]);

  let gridContainer =
    style([maxWidth(`px(500)), margin(`auto), alignContent(`center)]);
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
       <div className=Styles.container>
         <div className=Styles.latexContainer>
           <p className=Styles.latexText>
             {React.string(ParticleInfo.getLatex(particle))}
           </p>
         </div>
         <div className=Styles.infoBlock>
           <Table size=`Small>
             <TableHead>
               <TableRow>
                 <TableCell> "Property" </TableCell>
                 <TableCell> "Value" </TableCell>
               </TableRow>
             </TableHead>
             <TableBody>
               {ParticleInfo.getNameValuePair(particle)
                ->Belt.Array.map(pair => getTableRow(pair))
                ->React.array}
             </TableBody>
           </Table>
         </div>
       </div>
     )}
  </MaterialUi_ThemeProvider>;
};
