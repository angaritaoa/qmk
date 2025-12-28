.PHONY: install
install:
	curl -fsSL https://install.qmk.fm | sh

.PHONY: clone
clone:
	rm -rf qmk_firmware; git clone git@github.com:qmk/qmk_firmware.git
	qmk setup --home $(shell pwd)/qmk_firmware
	mkdir -p $(shell pwd)/qmk_firmware/keyboards/planck/keymaps/angaritaoa
#	qmk doctor -n

.PHONY: compile
compile:
	cp -f config.h ./qmk_firmware/keyboards/planck/keymaps/angaritaoa
	cp -f keymap.c ./qmk_firmware/keyboards/planck/keymaps/angaritaoa
	cp -f rules.mk ./qmk_firmware/keyboards/planck/keymaps/angaritaoa
#	qmk clean --all
# qmk list-keyboards
	qmk compile --keymap angaritaoa --keyboard planck/rev7

.PHONY: flash
flash:
	qmk flash --keymap angaritaoa --keyboard planck/rev7
