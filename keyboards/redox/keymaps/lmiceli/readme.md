cd ~/dev/github/qmk_firmware/keyboards/redox/keymaps/lmiceli/
2. meter el json
qmk json2c -o keymap.c pacho_	
qmk flash -kb redox -km lmiceli 

NOTA: a veces hara falta updatear qmk y hacer QMK SETUP o make git-submodule o todo


