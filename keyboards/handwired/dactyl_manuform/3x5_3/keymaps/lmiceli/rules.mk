# Includes
# SRC += features/caps_word.c

# Build Options
#   change yes to no to disable
#
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# DYNAMIC_MACRO_ENABLE = yes  # Create macros on the fly
# RGB_MATRIX_DRIVER = WS2812
INDICATOR_LIGHTS = no      # Enable indicator lights for caps lock, etc.
TAP_DANCE_ENABLE = no      # Send different keycodes if tapped multiple times
# KEY_OVERRIDE_ENABLE = yes   # Override key combos
COMBO_ENABLE = no          # Custom key combos

LTO_ENABLE = yes

#MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
AUDIO_ENABLE = no
RGBLIGHT_ENABLE = no
OLED_ENABLE = no

DEBOUNCE_TYPE = asym_eager_defer_pk
AUTO_SHIFT_ENABLE = no
BACKLIGHT_ENABLE = no
#AUTO_SHIFT_MODIFIERS

TAP_DANCE_ENABLE=yes

# RGB_MATRIX_SUPPORTED = yes
