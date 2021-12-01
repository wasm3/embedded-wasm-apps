/*
 * Project particle-wasm-apps
 * Description: Run TinyGo, AssemblyScript, Rust, CPP apps on Particle
 * Author:      Volodymyr Shymanskyy
 * Date:        30.11.2021
 */

#include "wasm-rt-helpers.h"

#if defined(PARTICLE)

SYSTEM_MODE(SEMI_AUTOMATIC)
SYSTEM_THREAD(ENABLED)

void platform_init() {
    Particle.connect();
}

IMPORT_IMPL_PARTICLE(Z_publishZ_vi, void, (wasm_ptr ev), {
    Particle.publish((const char*)MEMACCESS(ev));
});

#else

void platform_init() {
}

#endif

IMPORT_IMPL(Z_wasi_snapshot_preview1Z_fd_writeZ_iiiii, u32, (u32 fd, wasm_ptr iovs_ptr, u32 iovs_len, wasm_ptr nwritten), {
    return 58;
});

IMPORT_IMPL_WIRING(Z_delayZ_vi, void, (u32 t), {
    delay(t);
});

IMPORT_IMPL_WIRING(Z_millisZ_iv, u32, (void), {
    return millis();
});

IMPORT_IMPL_WIRING(Z_pinModeZ_vii, void, (u32 pin, u32 mode), {
    switch (mode) {
    case 0: pinMode(pin, INPUT);        break;
    case 1: pinMode(pin, OUTPUT);       break;
    case 2: pinMode(pin, INPUT_PULLUP); break;
    }
});

IMPORT_IMPL_WIRING(Z_digitalWriteZ_vii, void, (u32 pin, u32 value), {
    digitalWrite(pin, value);
});


IMPORT_IMPL_WIRING(Z_printZ_vii, void, (wasm_ptr buf, u32 len), {
    //Serial.printf("print mem:0x%x, off:0x%x, len:%d\n", (void*)(Z_memory->data), buf, len);
    Serial.write((const uint8_t*)MEMACCESS(buf), len);
});

void setup()
{
    Serial.begin(115200);
    delay(1000);

    platform_init();

    Serial.println("Initializing WebAssembly...");

    wasm_init();

    wasm_Z_setupZ_vv();
}

void loop()
{
    wasm_Z_loopZ_vv();
}
