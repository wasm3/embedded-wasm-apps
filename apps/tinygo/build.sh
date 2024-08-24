set -e

# Prepare
export GOROOT=/opt/go-v1.23.0
export PATH=/opt/tinygo-v0.33.0/bin:$GOROOT/bin:$PATH
export GO111MODULE=off

# TODO: https://github.com/tinygo-org/tinygo/issues/4223

# Compile
tinygo build -target ./target.json -o app.wasm app.go

# Optimize (optional)
wasm-opt -Os app.wasm -o app.wasm
wasm-strip app.wasm

# Convert to WAT
wasm2wat --generate-names app.wasm -o app.wat
