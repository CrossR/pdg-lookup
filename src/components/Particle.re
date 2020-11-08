module Styles = {
  open Css;

  let container =
    style([
      alignItems(`center),
      textAlign(`center),
      marginLeft(`percent(15.0)),
      marginRight(`percent(15.0)),
    ]);

  let name = style([fontSize(rem(1.875)), color(hex("1a202c"))]);

  let latexText =
    style([
      fontSize(rem(5.0)),
      color(hex("1a202c")),
      alignItems(`center),
    ]);

  let link =
    style([
      fontSize(rem(1.875)),
      textDecoration(`none),
      color(hex("4299e1")),
    ]);

  let latexContainer =
    style([Css.float(`left), width(`percent(35.0)), alignItems(`center)]);

  let infoBlock = style([Css.float(`left), width(`percent(65.0))]);

  let infoLineName = style([textAlign(`left), fontWeight(`semiBold)]);
  let infoLineProp = style([textAlign(`left)]);

  let gridContainer =
    style([
      width(`percent(100.0)),
      height(`percent(100.0)),
      maxWidth(`px(980)),
      margin(`auto),
      margin(`px(30)),
      alignContent(`center),
    ]);
};

let getPropertyLine = (infoSizePair) => {
  let info = fst(infoSizePair);
  let size = snd(infoSizePair);
  let name = fst(info);
  let property = snd(info);

  MaterialUi.(
    [|
      <Grid item=true xs=fst(size)>
        <p className=Styles.infoLineName> {React.string(name)} </p>
      </Grid>,
      <Grid item=true xs=snd(size)>
        <p className=Styles.infoLineProp> {React.string(property)} </p>
      </Grid>,
    |]
  )
  ->React.array;
};

[@react.component]
let make = (~particle) => {

  <MaterialUi_ThemeProvider
    theme={MaterialUi_Theme.create(MaterialUi_ThemeOptions.make())}>
    {MaterialUi.(
       <div className=Styles.container>
         <p className=Styles.name>
           {React.string(ParticleInfo.getPdgName(particle))}
         </p>
         <div className=Styles.latexContainer>
           <p className=Styles.latexText>
             {React.string(ParticleInfo.getLatex(particle))}
           </p>
         </div>
         <div className=Styles.infoBlock>
           <Grid container=true alignItems=`Center>
             {ParticleInfo.getInfoPairsForGrid(particle)
              ->Belt.Array.map(pair => getPropertyLine(pair))
              ->React.array}
           </Grid>
         </div>
       </div>
     )}
  </MaterialUi_ThemeProvider>;
};
