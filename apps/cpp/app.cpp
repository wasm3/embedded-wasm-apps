
#include <wiring.h>
#include <FixedBufferStream.h>

const int LED_BUILTIN = 2;

void setup() {
  println("🤩 C++ is running!");

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  static char buffer[128];
  FixedBufferStream ss(buffer, sizeof(buffer));
  ss << millis() << " Blink" << ss.endl;
  print(ss.get_buffer());

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                        // wait 100ms
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(900);                        // wait 900ms
}
