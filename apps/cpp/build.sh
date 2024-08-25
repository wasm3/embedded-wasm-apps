set -e

export PATH=/opt/wasi-sdk/bin:$PATH

# Compile
clang --target=wasm32 -nostdlib -z stack-size=4096      \
    -Wl,--no-entry -Wl,--stack-first -Wl,--strip-all    \
    -Wl,--initial-memory=65536 -Wl,-z,stack-size=4096   \
    -Os -o app.wasm app.cpp

# Optimize (optional)
wasm-opt -O3 app.wasm -o app.wasm
wasm-strip app.wasm

# Convert to WAT
wasm2wat --generate-names app.wasm -o app.wat
