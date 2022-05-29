/** @file keymap.c
 *  @brief keymap.c that includes key layout and keylogs functions
 */

#include "lmiceli.h"

// #ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
// uint32_t layer_state_set_keymap(uint32_t state) {
//     rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
//     switch (biton32(state)) {
//         case _COLEMAK:
//             rgblight_sethsv_noeeprom_red();
//             break;
//         case _NAVMEDIA:
//             rgblight_sethsv_noeeprom_green();
//             break;
//         default:  // for any other layers, or the default layer
//             rgblight_mode(RGBLIGHT_MODE_STATIC_GRADIENT + 3);
//             rgblight_sethsv_red();
//             break;
//     }
//     return state;
// }
// #endif


// wip basado en kyria(no color individual)
bool onBaseLayerColor = true;

// #define RBG_VAL 180
// #define RBG_VAL_LOW 130
#define RBG_VAL 80
#define RBG_VAL_LOW 70
// colores https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight
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



// bool process_record_user(uint16_t keycode, keyrecord_t *record){
//     bool user_records_press=true;

//     if (record->event.pressed){
//         add_keylog(keycode);
//     }

//     switch (keycode){
//         case QWERTY:
//             if (record->event.pressed){
//                 set_single_persistent_default_layer(_QWERTY);
//             }
//             break;

//         case LOWER:
//             if(record->event.pressed){
//                 layer_on(_LOWER);
//                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
//             }else{
//                 layer_off(_LOWER);
//                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
//             }
//             break;

//         case RAISE:
//             if (record->event.pressed){
//                 layer_on(_RAISE);
//                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
//             }else{
//                 layer_off(_RAISE);
//                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
//             }
//             break;

//         case ADJUST:
//             if (record->event.pressed){
//                 layer_on(_ADJUST);
//             }else{
//                 layer_off(_ADJUST);
//             }
//             break;

//         case RGB_MOD:
//             #ifdef RGBLIGHT_ENABLE
//             if(record->event.pressed){
//                 rgblight_mode(RGB_current_mode);
//                 rgblight_step();
//                 RGB_current_mode = rgblight_get_mode();
//             }
//             #endif
//             break;

//         case RGBRST:
//             #ifdef RGBLIGHT_ENABLE
//             if(record->event.pressed){
//                 eeconfig_update_rgblight_default();
//                 rgblight_enable();
//                 RGB_current_mode = rgblight_get_mode();
//             }
//             #endif
//             break;

//         default:
//             user_records_press=false;
//             break;
//     }

//     return false==user_records_press;
// }
