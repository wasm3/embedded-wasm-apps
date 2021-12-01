# Prepare
export PATH=/opt/zig-linux-x86_64-0.9.0:$PATH

# Compile
zig build-lib main.zig -target wasm32-freestanding \
    --initial-memory=65536 --max-memory=65536 --stack 2048 \
    -dynamic -OReleaseFast -femit-bin=app.wasm

# Optimize (optional)
wasm-opt -Os app.wasm -o app.wasm
wasm-strip app.wasm

# Convert to WAT
wasm2wat --generate-names app.wasm -o app.wat
