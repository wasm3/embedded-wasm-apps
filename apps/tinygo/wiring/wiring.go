package wiring

const (
    LOW  = 0
    HIGH = 1

    INPUT           =  0
    OUTPUT          =  1
    INPUT_PULLUP    =  2
)

//go:wasm-module wiring
//go:export millis
func Millis() uint

//go:wasm-module wiring
//go:export delay
func Delay(ms uint)

//go:wasm-module wiring
//go:export pinMode
func PinMode(pin, mode uint)

//go:wasm-module wiring
//go:export digitalWrite
func DigitalWrite(pin, value uint)

//go:wasm-module wiring
//go:export print
func Print(s string)

func Println(s string) {
    Print(s)
    Print("\n")
}
