/*
 * Project:     embedded-wasm-apps
 * Description: Run sandboxed TinyGo, AssemblyScript, Rust, CPP apps on embedded/IoT devices
 * Author:      Volodymyr Shymanskyy
 * Date:        30.11.2021
 */

#include "wasm-app.h"

w2c_app wasm_app;

#if defined(PARTICLE)
    #include "Particle.h"

    SYSTEM_THREAD(ENABLED)

    void w2c_wiring_publish(struct w2c_wiring*, u32 offset) {
        Particle.publish((const char*)wasm_app.w2c_memory.data + offset);
    }
#elif defined(ARDUINO)
    #include "Arduino.h"
#else
    #error "Platform not supported"
#endif

void w2c_wiring_stopWdt(struct w2c_wiring*) {
#if defined(ESP8266)
    ESP.wdtDisable();
    *((volatile uint32_t*) 0x60000900) &= ~(1); // Hardware WDT OFF
#elif defined(ESP32)
    disableCore0WDT();
#endif
}

void w2c_wiring_delay(struct w2c_wiring*, u32 t) {
    delay(t);
}

u32 w2c_wiring_millis(struct w2c_wiring*) {
    return millis();
}

void w2c_wiring_pinMode(struct w2c_wiring*, u32 pin, u32 mode) {
    switch (mode) {
    case 0: pinMode(pin, INPUT);        break;
    case 1: pinMode(pin, OUTPUT);       break;
    case 2: pinMode(pin, INPUT_PULLUP); break;
    }
}

void w2c_wiring_digitalWrite(struct w2c_wiring*, u32 pin, u32 value) {
    digitalWrite(pin, value);
}

void w2c_wiring_print(struct w2c_wiring*, u32 offset, u32 len) {
    Serial.write((const uint8_t*)wasm_app.w2c_memory.data + offset, len);
}

void os_print_last_error(const char* msg) {
    Serial.println(msg);
    for(;;) { delay(100); }  // Wait forever
}

__attribute__((weak))
void w2c_app_0x5Finitialize(w2c_app*) {}

__attribute__((weak))
void w2c_app_0x5Fstart(w2c_app*) {}

void setup()
{
    Serial.begin(115200);
#if defined(PARTICLE)
    Particle.connect();
    waitUntil(Particle.connected);
#endif
    delay(2000);

    Serial.println("Initializing WebAssembly...");

    wasm_rt_init();
    wasm2c_app_instantiate(&wasm_app, NULL);

    w2c_app_0x5Finitialize(&wasm_app);
    w2c_app_0x5Fstart(&wasm_app);

    w2c_app_setup(&wasm_app);
}

void loop()
{
    w2c_app_loop(&wasm_app);
}

