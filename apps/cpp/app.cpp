
#include "wiring.h"

const int LED_BUILTIN = 2;

void setup() {
  println("🤩 C++ is running!");

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

char buff[128];

// the loop function runs over and over again forever
void loop() {
  size_t offset = itoa(millis(), buff, 10);
  strcpy(buff + offset, " Blink");
  println(buff);

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                        // wait 100ms
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(900);                        // wait 900ms
}
