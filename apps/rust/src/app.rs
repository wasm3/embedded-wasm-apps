#![no_std]

mod arduino;
use arduino::*;

#[no_mangle]
pub extern fn r#setup() {
    pinMode(7, OUTPUT);
    println("🦀 Rust is running!");
}

#[no_mangle]
pub extern fn r#loop() {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);
    delay(900);
}
