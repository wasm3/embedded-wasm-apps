#![no_std]

mod wiring;
use wiring::*;

const LED: u32 = 2;

#[no_mangle]
pub extern fn setup() {
    pinMode(LED, OUTPUT);
    println("🦀 Rust is running!");
}

#[no_mangle]
pub extern fn r#loop() {
    println("Blink");

    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(900);
}
