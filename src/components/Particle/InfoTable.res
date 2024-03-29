open Mui

module Styles = {
  open Css

  let infoBlock = style(list{Css.float(#left)})
  let infoLineName = style(list{textAlign(#left), fontWeight(#semiBold)})
  let infoLineProp = style(list{textAlign(#left)})
  let cell = ReactDOMStyle.make(~borderColor="white", ~padding="5px", ~minWidth="0.1rem", ())
}

let getTableRow = ((p1, p2)) => {
  let getName = (p: ParticleInfo.propertyValue) => p.property->React.string
  let getValue = (p: ParticleInfo.propertyValue) =>
    switch p.units {
    | Some(u) => React.string(p.value ++ (" " ++ u))
    | None => p.value->React.string
    }

  <TableRow>
    <TableCell style=Styles.cell variant=TableCell.Head> {getName(p1)} </TableCell>
    <TableCell style=Styles.cell> {getValue(p1)} </TableCell>
    <TableCell style=Styles.cell variant=TableCell.Head> {getName(p2)} </TableCell>
    <TableCell style=Styles.cell> {getValue(p2)} </TableCell>
  </TableRow>
}

let getTable = particle => {
  let infoPairs = ParticleInfo.getProperties(particle)
  let midPoint = Array.size(infoPairs) / 2
  let firstHalf = Array.slice(infoPairs, ~offset=0, ~len=midPoint)
  let secondHalf = Array.slice(infoPairs, ~offset=midPoint, ~len=Array.size(infoPairs) - midPoint)

  Array.zip(firstHalf, secondHalf)->Array.map(getTableRow)
}

@react.component
let make = (~particle) =>
  <ThemeProvider theme={Theme(Theme.create({}))}>
    {<div className=Styles.infoBlock>
      <Table size=Table.Small>
        <TableBody> {getTable(particle)->React.array} </TableBody>
      </Table>
    </div>}
  </ThemeProvider>
