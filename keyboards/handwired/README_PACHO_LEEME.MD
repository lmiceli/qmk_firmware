parece q se me lio mucho el meter el teclado skeletyl viejo mio en esta rama
no recuerdo q paso ni en q estado estaba pero me acabo de traer esta carpeta desde la rama de 2022
y a ver si la consigo hacer andar

- cosas q voy probando:
- qmk setup, corrio bien, pero el kb no compila

encontre en un log x ahi q estoy obligado a usar el nuevo nombre, voy a tratar de arreglar
esa carpeta antes de q yo tocara nada, ademas voy a dejar claro x ahi q eso no tiene vuelta atras

# QMK Breaking Changes - 2023 Aug 27 Changelog
...
## Changes Requiring User Action {#changes-requiring-user-action}

### Updated Keyboard Codebases {#updated-keyboard-codebases}

| Old Keyboard Name                     | New Keyboard Name                   |
|---------------------------------------|-------------------------------------|
| handwired/dactyl_manuform/3x5_3       | handwired/dactyl_minidox            |

...

### `IGNORE_MOD_TAP_INTERRUPT` behaviour changes ([#20211](https://github.com/qmk/qmk_firmware/pull/20211)) {#i-m-t-i}

Following up from the last breaking changes cycle, `IGNORE_MOD_TAP_INTERRUPT` has been removed and if present in keymap code, will now fail to build. The previous functionality for `IGNORE_MOD_TAP_INTERRUPT` is now default, and should you wish to revert to the old behaviour, you can use `HOLD_ON_OTHER_KEY_PRESS` instead.

For more information, you are invited to read the section on [HOLD_ON_OTHER_KEY_PRESS](../tap_hold#hold-on-other-key-press) in the page on [Tap-Hold configuration options](../tap_hold).
