package main

import (
  . "./wiring"
  "strconv"
)

var LED uint = 19

//export setup
func setup() {
    PinMode(LED, OUTPUT)

    Println("TinyGo is running 🤖")
}

//export loop
func loop() {
    time := Millis()
    Println(strconv.FormatUint(uint64(time), 10))

    DigitalWrite(LED, HIGH)
    Delay(100)
    DigitalWrite(LED, LOW)
    Delay(900)
}

func main() {}
