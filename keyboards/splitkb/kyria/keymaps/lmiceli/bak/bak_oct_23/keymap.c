#include QMK_KEYBOARD_H

// ❯ cd qmk_firmware/keyboards/splitkb/kyria/keymaps/lmiceli
// ❯ qmk json2c -o keymap.c k14.json
// ❯ qmk flash -kb kyria -km lmiceli -bl avrdude


enum layers {
  _COLEMAK = 0,
  _NAVMEDIA,
  _ARROW,
	_MOUSE,
	_SYMBOL,
	_NUMBER,
	_FUNCTION,
	_SCREEN
};

// todo
// reset, debug, etc,
// other features to research, drashna's map
// rgb per layer
// better organization

// BASE cole dh
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT(
		SGUI(KC_TAB), KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                 						/*|*/						  	KC_J, 		KC_L, 		  KC_U, 	    KC_Y, 	      KC_CAPS, 	    KC_WH_U,
		LT(1,KC_ESC), 		  LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), LT(7,KC_G),      								/*|*/						  	LT(7,KC_M), LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), LT(7,KC_QUOT),
		LGUI(KC_TAB), KC_Z, 		KC_X, 		  KC_C,   		KC_D, 		  KC_V, 		LT(5,KC_F5),  LT(4,KC_F11), 	/*|*/	KC_F8,  	KC_F9, 		KC_K, 		KC_H, 		  KC_COMM, 		KC_DOT, 	  KC_SLSH, 		KC_WH_D,
        /*********************************************************************************************************************|****************************************************************************************************************/
										KC_F3, 		KC_F6, 		 LT(7,KC_ESC),   LT(2,KC_BSPC),   LT(3,KC_TAB), 			/*|*/		LT(4,KC_ENT), LT(5,KC_SPC), LT(6,KC_DEL), KC_F7, KC_F2
	),


	[_NAVMEDIA] = LAYOUT(
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_BTN1, LGUI(KC_A),                            KC_NO, RGB_HUD, RGB_HUI, BL_OFF, BL_ON, KC_TRNS,
            KC_TRNS, MEH(KC_SPC), MEH(KC_LEFT), MEH(KC_UP), MEH(KC_RGHT), LCAG(KC_X),     KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS,
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, LGUI(KC_BSLS), KC_NO, KC_NO,             KC_NO, KC_NO, KC_NO, KC_MRWD, KC_MFFD, KC_NO, KC_NO, KC_TRNS,
                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              KC_MSTP, KC_MPLY, KC_MUTE, KC_NO, KC_NO),


            [_ARROW] = LAYOUT(
                    KC_F12, LALT(KC_1), KC_BTN2, KC_BTN3, KC_BTN1, MEH(KC_LEFT),      KC_PGUP, KC_HOME, KC_UP, KC_END, KC_PGDN, KC_NO,
                    KC_F11, LALT(KC_LEFT), KC_LALT, KC_LCTL, KC_LSFT, MEH(KC_RGHT),   LALT(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, LALT(KC_RGHT), KC_NO,
                    KC_F10, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_TAB), LSFT(KC_F6), KC_NO,          KC_BTN1, KC_MS_U, KC_INS, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_UP), LGUI(KC_RGHT), KC_NO,
                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_MS_L, KC_MS_D, KC_MS_R, MEH(KC_LEFT), MEH(KC_RGHT)),



	[_MOUSE] = LAYOUT(
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                    KC_NO, KC_WH_U, KC_MS_U, KC_WH_D, KC_NO, KC_TRNS,
            KC_TRNS, KC_NO, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,              KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_TRNS,
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_NO, KC_WH_L, KC_NO, KC_WH_R, KC_NO, KC_TRNS,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_BTN3, KC_BTN1, KC_BTN2, KC_NO, KC_NO
                            ),


    [_SYMBOL] = LAYOUT(
            KC_TRNS, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
            KC_TRNS, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,      KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO, KC_TRNS,
            KC_TRNS, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
              KC_NO, KC_NO, KC_GT, KC_RPRN, KC_UNDS,           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
              ),
	[_NUMBER] =
            LAYOUT(
                    KC_TRNS, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,         KC_NO,KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
                    KC_TRNS, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,          KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO, KC_TRNS,
                    KC_TRNS, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
                       KC_NO, KC_NO, KC_DOT, KC_0, KC_MINS,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
                       ),


	[_FUNCTION] = LAYOUT(
            KC_TRNS, KC_F12, KC_F7, KC_F8, KC_F9, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
            KC_TRNS, KC_F11, KC_F4, KC_F5, KC_F6, KC_NO,     KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO, KC_TRNS,
            KC_TRNS, KC_F10, KC_F1, KC_F2, KC_F3, KC_NO, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
               KC_NO, KC_NO, KC_ESC, KC_BSPC, KC_TAB,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

	[_SCREEN] = LAYOUT(
		KC_NO, KC_NO, KC_BTN2, KC_BTN3, KC_BTN1, KC_NO,								 /*|*/ 							KC_NO, SGUI(KC_L), SGUI(KC_U), SGUI(KC_Y), 		KC_NO, EEP_RST,
		KC_TRNS, MEH(KC_SPC), MEH(KC_LEFT), MEH(KC_UP), MEH(KC_RGHT), KC_NO, 		 /*|*/							KC_NO, SGUI(KC_N), SGUI(KC_E), SGUI(KC_I), 		KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO,     				 /*|*/			KC_NO, KC_NO,   KC_NO, SGUI(KC_H), SGUI(KC_COMM), SGUI(KC_DOT), KC_NO, RESET,
		/*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*//*|*/
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 					/*|*//*|*//*|*/						  SGUI(KC_ENT), SGUI(KC_SPC), SGUI(KC_DEL), KC_NO, KC_NO
	)
};






/**

FUTURE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(SGUI(KC_TAB), KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_CAPS, KC_WH_U, KC_F11, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_QUOT, LGUI(KC_TAB), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_MS_L, KC_MS_R, KC_MS_D, KC_MS_U, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_WH_D, KC_BTN2, KC_BTN1, LT(1,KC_ESC), LT(2,KC_BSPC), LT(3,KC_TAB), LT(4,KC_ENT), LT(5,KC_SPC), LT(6,KC_DEL), KC_WH_L, KC_WH_R),
	[1] = LAYOUT(KC_NO, KC_NO, KC_BTN2, KC_BTN3, KC_BTN1, KC_NO, KC_NO, SGUI(KC_L), SGUI(KC_U), SGUI(KC_Y), KC_MPRV, KC_MNXT, KC_TRNS, KC_NO, MEH(KC_LEFT), MEH(KC_UP), MEH(KC_RGHT), KC_NO, KC_NO, SGUI(KC_N), SGUI(KC_E), SGUI(KC_I), KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SGUI(KC_H), SGUI(KC_COMM), SGUI(KC_DOT), KC_MUTE, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SGUI(KC_ENT), SGUI(KC_SPC), SGUI(KC_DEL), KC_NO, KC_NO),
	[2] = LAYOUT(KC_NO, LALT(KC_1), KC_BTN2, KC_BTN3, KC_BTN1, KC_NO, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_PGDN, KC_NO, LALT(KC_LEFT), KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, LALT(KC_RGHT), LCA(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, LCA(KC_RGHT), KC_NO, KC_NO, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_TAB), LSFT(KC_F6), KC_NO, KC_BTN1, KC_MS_U, KC_INS, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_UP), LGUI(KC_RGHT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, MEH(KC_LEFT), MEH(KC_RGHT)),
	[3] = LAYOUT(KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_MS_U, KC_WH_D, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_WH_L, KC_NO, KC_WH_R, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN2, KC_BTN1, KC_BTN3, KC_NO, KC_NO),
	[4] = LAYOUT(KC_TRNS, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO, KC_TRNS, KC_TRNS, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_GT, KC_RPRN, KC_UNDS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[5] = LAYOUT(KC_TRNS, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO, KC_TRNS, KC_TRNS, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_DOT, KC_0, KC_MINS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[6] = LAYOUT(KC_TRNS, KC_F12, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_F11, KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO, KC_TRNS, KC_TRNS, KC_F10, KC_F1, KC_F2, KC_F3, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_ESC, KC_BSPC, KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};
**/
// END LAYOUT

// START METHODS

bool onBaseLayerColor = true;

#define RBG_VAL 180
#define RBG_VAL_LOW 130
// colores https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight
layer_state_t layer_state_set_user(layer_state_t state) {
  onBaseLayerColor = false;
  switch(biton32(state)) {
  case _SCREEN:
    // green-ish
    rgblight_sethsv_noeeprom(72, 255, RBG_VAL);
    break;
  case _ARROW:
    // blu
    rgblight_sethsv_noeeprom(150, 255, RBG_VAL);
    break;
  case _MOUSE:
    rgblight_sethsv_noeeprom(80, 255, RBG_VAL);
    break;
  case _SYMBOL:
    rgblight_sethsv_noeeprom(10, 5, RBG_VAL);
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





// END METHODS




// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),


