/** @file keymap.c
 *  @brief keymap.c that includes key layout and keylogs functions
 */

#include "lmiceli.h"

// -----------------------------------------------------------
// COMBOS
// TODO: IMPROVE https://beta.docs.qmk.fm/using-qmk/software-features/feature_combos
const uint16_t PROGMEM L_U__COMBO[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM H_COMMA__COMBO[] = {KC_H, KC_COMMA, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(L_U__COMBO, KC_J),
    COMBO(H_COMMA__COMBO, KC_K), // keycodes with modifiers are possible too!
};

// -----------------------------------------------------------

// RGB
// wip basado en kyria(no color individual), mas ideas en bak folder
// ESTO ERA MUY BRILLANTE
// #define RBG_VAL 180
// #define RBG_VAL_LOW 130
#define RBG_VAL 80
#define RBG_VAL_LOW 70
// colores https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight

bool onBaseLayerColor = true;

layer_state_t layer_state_set_user(layer_state_t state) {
  onBaseLayerColor = false;
  switch(biton32(state)) {
  case _NAVMEDIA:
    // green-ish
    rgblight_sethsv_noeeprom(72, 255, RBG_VAL);
    break;
  case _ARROW:
    // blu
    rgblight_sethsv_noeeprom(150, 255, RBG_VAL);
    break;
  case _FUNCTION:
    // blu
    rgblight_sethsv_noeeprom(150, 255, RBG_VAL);
    break;
  case _MOUSE:
    rgblight_sethsv_noeeprom(80, 255, RBG_VAL);
    break;
  case _SYMBOL:
    rgblight_sethsv_noeeprom(10, 225, RBG_VAL);
    break;
  case _NUMBER:
    rgblight_sethsv_noeeprom(30, 255, RBG_VAL);
    break;
  default:
    // Default colors
    rgblight_sethsv(222, 255, RBG_VAL_LOW);
	onBaseLayerColor = true;
    break;
  }
  return state;
}

// Handle Caps lock led

void led_set_user(uint8_t usb_led) {
  if (onBaseLayerColor){
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_sethsv_noeeprom(15, 255, RBG_VAL);  
    }
    else {
        // Default colors
        rgblight_sethsv(190, 255, RBG_VAL_LOW);
    }
  }
}
