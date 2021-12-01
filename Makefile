
.PHONY: all clean

APP ?= assemblyscript

all:
	-@rm apps/$(APP)/app.wasm
	cd apps/$(APP) && ./build.sh
	@cp apps/$(APP)/app.wasm ./
	wasm2c app.wasm -o wasm-app.c
	@mv wasm-app.* ./src
	@rm app.wasm

clean:
	-@rm ./src/wasm-app.*
	-@rm -rf ./build ./.pio
	-@rm *_firmware_*.bin


### Particle helpers

DEVICE   ?= "Photon"
DEV_TYPE ?= photon

particle_compile: all
	@particle compile $(DEV_TYPE) ./src

particle_erase:
	@particle usb dfu
	@particle flash --usb tinker

particle_upload:
	@particle flash $(DEVICE) ./src/

particle_upload_usb: clean compile
	@particle usb dfu
	@particle flash --usb *_firmware_*.bin
	-@rm *_firmware_*.bin

particle_monitor:
	@particle serial monitor --follow


### PlatformIO helpers

pio_compile: all
	@pio run

pio_upload: all
	@pio run -t upload

pio_monitor:
	@pio device monitor --quiet

