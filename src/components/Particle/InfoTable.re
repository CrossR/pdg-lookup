module Styles = {
  open Css;

  let infoBlock = style([Css.float(`left)]);
  let infoLineName = style([textAlign(`left), fontWeight(`semiBold)]);
  let infoLineProp = style([textAlign(`left)]);
  let cell = ReactDOMStyle.make(
    ~borderColor="white",
    ~padding="5px",
    ~minWidth="0.1rem",
    ()
    );
};

let getTableRow = ((p1, p2)) => {

  let getName = (p: ParticleInfo.propertyValue) => p.property;
  let getValue = (p: ParticleInfo.propertyValue) => {
    switch (p.units) {
      | Some(u) => p.value ++ " " ++ u
      | None => p.value
    }
  }


  MaterialUi.(
    <TableRow>
      <TableCell style=Styles.cell variant=`Head> {getName(p1)} </TableCell>
      <TableCell style=Styles.cell> {getValue(p1)} </TableCell>
      <TableCell style=Styles.cell variant=`Head> {getName(p2)} </TableCell>
      <TableCell style=Styles.cell> {getValue(p2)} </TableCell>
    </TableRow>
  );
};

let getTable = (particle) => {
  let infoPairs = ParticleInfo.getProperties(particle);
  let midPoint = Array.size(infoPairs) / 2;
  let firstHalf = Array.slice(infoPairs, ~offset=0, ~len=midPoint);
  let secondHalf = Array.slice(infoPairs, ~offset=midPoint, ~len=Array.size(infoPairs) - midPoint);

  Array.zip(firstHalf, secondHalf) -> Array.map(getTableRow)
};

[@react.component]
let make = (~particle) => {
  <MaterialUi_ThemeProvider
    theme={MaterialUi_Theme.create(MaterialUi_ThemeOptions.make())}>
    {MaterialUi.(
       <div className=Styles.infoBlock>
         <Table size=`Small>
           <TableBody>
             {getTable(particle)
              ->React.array}
           </TableBody>
         </Table>
       </div>
     )}
  </MaterialUi_ThemeProvider>;
};
