set -e

# Compile
npm run build

# Optimize (optional)
wasm-strip app.wasm

# Convert to WAT
#wasm2wat --generate-names app.wasm -o app.wat
