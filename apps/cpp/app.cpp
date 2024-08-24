
#include "wiring.h"

int LED_BUILTIN = 2;

WASM_EXPORT
void setup() {
  println("🤩 C++ is running!");

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
WASM_EXPORT
void loop() {
  println("Blink");

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                        // wait 100ms
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(900);                        // wait 900ms
}
