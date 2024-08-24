const w = @import("./wiring.zig");
const std = @import("std");

const LED = 2;

export fn setup() void {
    w.println("⚡ Zig is running!");
    w.pinMode(LED, w.PinMode.OUTPUT);
}

var buf: [128]u8 = undefined;

export fn loop() void {
    const t = w.millis();
    if (std.fmt.bufPrint(&buf, "{} Blink", .{t})) |res| {
        w.println(res);
    } else |err| {
        err catch {};
    }

    w.digitalWrite(LED, w.Digital.LOW);
    w.delay(900);
    w.digitalWrite(LED, w.Digital.HIGH);
    w.delay(100);
}
