1. cd ~/repos/personal/qmk_firmware/keyboards/redox/keymaps/lmiceli
2. meter el json
3. qmk json2c -o keymap.c pacho_19.json
4. qmk flash -kb redox -km lmiceli 

NOTA: a veces hara falta updatear qmk y hacer QMK SETUP o make git-submodule o todo


