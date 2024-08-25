set -e

# Install AssemblyScript toolchain if needed
if [ ! -d node_modules ] ; then
    npm i
fi

# Compile
npm run build

# Optimize (optional)
wasm-strip app.wasm

# Convert to WAT
#wasm2wat --generate-names app.wasm -o app.wat
