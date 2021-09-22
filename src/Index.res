%raw(`require('./styles.css')`)

switch ReactDOM.querySelector("root") {
| Some(e) => ReactDOM.render(<App />, e)
| None => ()
}
