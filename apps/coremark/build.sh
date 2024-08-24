set -e

# Compile
clang-16 --target=wasm32 --no-standard-libraries -Wl,--no-entry \
    -Wl,--stack-first -Wl,-z,stack-size=512 \
    -g0 -s -O3 -DFLAGS_STR="-O3" -I./ -o app.wasm \
    core_list_join.c core_main.c core_matrix.c core_state.c core_util.c core_portme.c cvt.c

# TODO: -mbulk-memory -mnontrapping-fptoint -msign-ext

# Convert to WAT
wasm2wat --generate-names app.wasm -o app.wat
