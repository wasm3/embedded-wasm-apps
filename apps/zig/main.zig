const w = @import("./wiring.zig");

const LED = 2;

export fn setup() void {
    w.println("⚡ Zig is running!");
    w.pinMode(LED, w.PinMode.OUTPUT);
}

export fn loop() void {
    w.digitalWrite(LED, w.Digital.LOW);
    w.delay(900);
    w.digitalWrite(LED, w.Digital.HIGH);
    w.delay(100);
}
