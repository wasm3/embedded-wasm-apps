# embedded-wasm-apps
Run statically-compiled
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/assemblyscript.svg" width="18" height="18" /> AssemblyScript](apps/assemblyscript/app.ts), 
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/rust.svg" width="18" height="18" /> Rust](apps/rust/src/app.rs), 
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/cplusplus.svg" width="18" height="18" /> C/C++](apps/cpp/app.cpp), 
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/go.svg" width="18" height="18" /> TinyGo](apps/tinygo/app.go), 
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/zig.svg" width="18" height="18" /> Zig](apps/zig/main.zig), 
etc. on any embedded platform, using WebAssembly

## Example
```log
$ make APP=rust
$ pio run -e esp32 -t upload
$ pio device monitor
Initializing WebAssembly...
🦀 Rust is running!

$ make APP=assemblyscript
$ pio run -e esp32 -t upload
$ pio device monitor
Initializing WebAssembly...
🚀 AssemblyScript is running!

$ make APP=tinygo
$ pio run -e esp32 -t upload
$ pio device monitor
Initializing WebAssembly...
🤖 TinyGo is running!
```

## Building `WASM` apps

Ensure [`WABT`](https://github.com/WebAssembly/wabt) and [`Binarien`](https://github.com/WebAssembly/binaryen) tools are in your `PATH`.

```sh
# AssemblyScript (needs Node.js)
cd apps/assemblyscript
npm install
cd ../..
make APP=assemblyscript

# Rust
rustup target add wasm32-unknown-unknown
make APP=rust

# C/C++ (needs wasienv)
make APP=cpp

# TinyGo (needs TinyGo v0.21.0 and Go v1.17.3)
make APP=tinygo

# TinyGo (needs Zig v0.9.0)
make APP=zig
```

## Building and running with `PlatformIO`

```sh
# For ESP32:
pio run -e esp32 -t upload

# For ESP8266:
pio run -e esp8266 -t upload

# Open serial monitor
pio device monitor
```

## Building and running with `Particle`

Requires [`particle-cli`](https://docs.particle.io/tutorials/developer-tools/cli/).
Should work on all Particle devices i.e. `Spark Core`, `Photon`, `Electron`, `Argon`, `Boron`:

```sh
particle flash MyDevice ./src/

# Open serial monitor
particle serial monitor --follow
```
