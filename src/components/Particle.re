module Styles = {
  open Css;

  let container =
    style([
      textAlign(`center),
      marginTop(rem(3.)),
      marginLeft(`percent(10.0)),
      marginRight(`percent(10.0)),
    ]);

  let name =
    style([
      fontSize(rem(1.875)),
      color(hex("1a202c")),
      marginBottom(rem(1.)),
    ]);

  let latex =
    style([
      fontSize(rem(3.0)),
      color(hex("1a202c")),
      marginBottom(rem(1.)),
    ]);

  let link =
    style([
      fontSize(rem(1.875)),
      textDecoration(`none),
      color(hex("4299e1")),
    ]);

  let latexBlock =
    style([float(`left), width(`percent(30.0)), textAlign(`right)]);

  let infoBlock = style([float(`left), width(`percent(70.0))]);

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

[@react.component]
let make = (~particle) => {
  <MaterialUi_ThemeProvider
    theme={MaterialUi_Theme.create(MaterialUi_ThemeOptions.make())}>
    {MaterialUi.(
       <div className=Styles.container>
         <p className=Styles.name>
           {React.string(ParticleInfo.getName(particle))}
         </p>
         <div className=Styles.latexBlock>
           <p className=Styles.latex>
             {React.string("\\(" ++ ParticleInfo.getLatex(particle) ++ "\\)")}
           </p>
         </div>
         <div className=Styles.infoBlock>
           <Grid container=true alignItems=`Center spacing=`V1>
             <Grid item=true xs=Grid.Xs._12>
               {React.string("Properties")}
             </Grid>
             <Grid item=true xs=Grid.Xs._6>
               {React.string(
                  "\\("
                  ++ Js.Float.toString(ParticleInfo.getMass(particle))
                  ++ "\\)",
                )}
             </Grid>
             <Grid item=true xs=Grid.Xs._6>
               {React.string(ParticleInfo.getEventGenName(particle))}
             </Grid>
           </Grid>
         </div>
       </div>
     )}
  </MaterialUi_ThemeProvider>;
};
