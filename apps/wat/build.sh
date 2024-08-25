set -e

# Convert WAT to WASM
wat2wasm main.wat -o app.wasm
