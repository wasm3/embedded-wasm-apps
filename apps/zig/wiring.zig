pub const PinMode = enum(i32) {
    INPUT,
    OUTPUT,
    INPUT_PULLUP
};

pub const Digital = enum(i32) {
    LOW,
    HIGH
};

const wiring = struct {
    extern "wiring" fn millis() i32;
    extern "wiring" fn delay(ms: i32) void;
    extern "wiring" fn pinMode(pin: i32, mode: PinMode) void;
    extern "wiring" fn digitalWrite(pin: i32, value: Digital) void;
    extern "wiring" fn print(buf: *const u8, len: u32) void;
};

// Public functions

pub const millis        = wiring.millis;
pub const delay         = wiring.delay;
pub const digitalWrite  = wiring.digitalWrite;
pub const pinMode       = wiring.pinMode;

pub fn print(str: []const u8) void {
    wiring.print(&str[0], str.len);
}

pub fn println(str: []const u8) void {
    print(str);
    print("\n");
}
