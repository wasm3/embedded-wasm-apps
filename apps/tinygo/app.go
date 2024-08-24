package main

import (
  . "./wiring"
  "strconv"
)

var LED uint = 2

//export setup
func setup() {
    PinMode(LED, OUTPUT)

    Println("🤖 TinyGo is running!")
}

//export loop
func loop() {
    t := strconv.FormatUint(uint64(Millis()), 10)
    Println(t + " Blink")

    DigitalWrite(LED, HIGH)
    Delay(100)
    DigitalWrite(LED, LOW)
    Delay(900)
}

func main() {}
