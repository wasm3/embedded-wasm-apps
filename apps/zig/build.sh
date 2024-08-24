# Prepare
export PATH=/opt/zig-linux-x86_64-0.13.0:$PATH

# Compile
zig build-exe main.zig -target wasm32-freestanding -fno-entry -rdynamic \
    --initial-memory=65536 --max-memory=65536 --stack 2048 \
    -OReleaseFast -femit-bin=app.wasm

# Optimize (optional)
wasm-opt -Os app.wasm -o app.wasm
wasm-strip app.wasm

# Convert to WAT
wasm2wat --generate-names app.wasm -o app.wat
