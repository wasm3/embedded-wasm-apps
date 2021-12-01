
.PHONY: all clean

DEVICE   ?= "Photon"
DEV_TYPE ?= photon
APP_LANG ?= assemblyscript

all:
	-@rm apps/$(APP_LANG)/app.wasm
	cd apps/$(APP_LANG) && ./build.sh
	@cp apps/$(APP_LANG)/app.wasm ./
	wasm2c app.wasm -o wasm-app.c
	@mv wasm-app.* ./src
	@rm app.wasm

clean:
	-@rm ./src/wasm-app.*
	-@rm -rf ./build ./.pio
	-@rm *_firmware_*.bin

############################
### UPLOAD
############################
compile: all
	@particle compile $(DEV_TYPE) ./src

erase:
	@particle usb dfu
	@particle flash --usb tinker

upload:
	@particle flash $(DEVICE) ./src/

upload_usb: clean compile
	@particle usb dfu
	@particle flash --usb *_firmware_*.bin
	-@rm *_firmware_*.bin

monitor:
	#@particle serial monitor --follow
	@pio device monitor
