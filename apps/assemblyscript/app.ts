import * as dev from "./wiring";

let LED = 7;

export function setup(): void {
  dev.pinMode(LED, dev.OUTPUT);

  dev.println('🚀 AssemblyScript is running!')
}

export function loop(): void {
  const time = dev.millis();
  dev.println(time.toString());

  dev.digitalWrite(LED, dev.HIGH);
  dev.delay(100);
  dev.digitalWrite(LED, dev.LOW);
  dev.delay(900);
}
