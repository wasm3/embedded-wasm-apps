# Prepare
export GOROOT=/opt/go-1.17.3
export PATH=/opt/tinygo-0.21.0/bin:$GOROOT/bin:$PATH
export GO111MODULE=off

# Compile
tinygo  build -target ./target.json       \
        -panic trap -wasm-abi generic     \
        -o app.wasm app.go

# Optimize (optional)
wasm-opt -Os app.wasm -o app.wasm
wasm-strip app.wasm

# Convert to WAT
wasm2wat --generate-names app.wasm -o app.wat
