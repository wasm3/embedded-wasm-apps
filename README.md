# embedded-wasm-apps
Run **native, statically-compiled**
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/assemblyscript.svg" width="18" height="18" /> AssemblyScript](apps/assemblyscript/app.ts), 
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/rust.svg" width="18" height="18" /> Rust](apps/rust/src/app.rs), 
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/cplusplus.svg" width="18" height="18" /> C/C++](apps/cpp/app.cpp), 
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/go.svg" width="18" height="18" /> TinyGo](apps/tinygo/app.go), 
[<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/zig.svg" width="18" height="18" /> Zig](apps/zig/main.zig), 
etc. apps on any embedded platform, using WebAssembly

## How it works

1. Compile source code to `wasm`
2. Translate `wasm` to `C` (using [`wasm2c`](https://github.com/WebAssembly/wabt/blob/main/wasm2c/README.md) from WABT)
3. Compile produced `C` and link with a thin runtime implementation, using the **native platform toolchain**

## Example
```log
$ make APP=rust
    Finished release [optimized] target(s) in 0.00s
$ pio run -e esp32 -t upload
$ pio device monitor
Initializing WebAssembly...
🦀 Rust is running!

$ make APP=assemblyscript
    > npm run asbuild:optimized
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
pio device monitor --quiet
```

## Building and running with `Particle`

Requires [`particle-cli`](https://docs.particle.io/tutorials/developer-tools/cli/).
Should work on all Particle devices i.e. `Spark Core`, `Photon`, `Electron`, `Argon`, `Boron`:

```sh
particle flash MyDevice ./src/

# Open serial monitor
particle serial monitor --follow
```
