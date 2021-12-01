# embedded-wasm-apps
Run statically-compiled
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/assemblyscript.svg" width="18" height="18" /> AssemblyScript](apps/assemblyscript/app.ts), 
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/rust.svg" width="18" height="18" /> Rust](apps/rust/src/app.rs), 
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/cplusplus.svg" width="18" height="18" /> C/C++](apps/cpp/app.cpp), 
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/go.svg" width="18" height="18" /> TinyGo](apps/tinygo/app.go), 
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/zig.svg" width="18" height="18" /> Zig](apps/zig/main.zig), 
etc. on any embedded platform, using WebAssembly

## Building `WASM` apps

```sh
make APP=assemblyscript

make APP=rust

make APP=cplusplus

make APP=go

make APP=zig
```

## Building and running on `PlatformIO`

```sh
pio run -t upload

# Open serial monitor
pio device monitor
```

## Building and running on `Particle`

```sh
particle flash MyDevice ./src/

# Open serial monitor
particle serial monitor --follow
```
