#!/usr/bin/bash

set -e

# Prepare
export PATH=/opt/virgil/bin:$PATH

# Compile
v3c -target=wasm app.v3

# TODO: /opt/virgil/lib/util/{StringBuilder,Chars,Ints,Longs,Arrays,Utf8,Vector,Ranges}.v3

# Optimize (optional)
wasm-opt -Os app.wasm -o app.wasm
wasm-strip app.wasm

# Convert to WAT
wasm2wat --generate-names app.wasm -o app.wat
