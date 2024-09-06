#include QMK_KEYBOARD_H

// ❯ cd qmk_firmware/keyboards/splitkb/kyria/keymaps/lmiceli

// qmk flash -kb splitkb/kyria/rev1 -km lmiceli -bl avrdude

enum layers {
    _COLEMAK = 0,
    _NAVIGATION,
    _ARROW,
    _MOUSE,
    _SYMBOL,
    _NUMBER,
    _FUNCTION,
    _GAME
};

// START METHODS 


/*  */
/* ALT TAB */
bool is_alt_tab_active = false;

enum custom_keycodes {          // Make sure have the awesome keycode ready
    ALT_TAB         = SAFE_RANGE,
    LT_NAV_ESC      = LT(_NAVIGATION, KC_ESC),
    LT_ARROW_BSPC   = LT(_ARROW, KC_BSPC),
    LT_MOUSE_TAB    = LT(_MOUSE, KC_TAB),
    LT_FUNCTION_DEL = LT(_FUNCTION, KC_DEL),
    LT_NUMBER_SPC   = LT(_NUMBER, KC_SPC),
    LT_SYMBOL_ENT   = LT(_SYMBOL, KC_ENT),
    LT_MOUSE_H      = LT(_MOUSE, KC_H),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode){
        case ALT_TAB: // super alt tab macro
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
            return false;
    }
    return true;
}

/* ALT TAB END */


bool onBaseLayerColor = true;

#define RBG_VAL 180
#define RBG_VAL_LOW 130
// colores https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight
layer_state_t layer_state_set_user(layer_state_t state) {


  if (is_alt_tab_active) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
  }

  onBaseLayerColor = false;
  switch(biton32(state)) {
  case _GAME:
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(

        KC_NO,LGUI_T(KC_Q), KC_W,         KC_F,         KC_P,         KC_B,                         /**/ KC_J,  KC_L,         KC_U,         KC_Y,         LGUI_T(KC_QUOT),  KC_NO,
        KC_NO,KC_A,         LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,                         /**/ KC_M,  LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), KC_O,             KC_NO,
        KC_NO,KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,   KC_NO, KC_NO,         /**/ TG(7), KC_NO, KC_K,  LT_MOUSE_H,   KC_COMM,      KC_DOT,       KC_SLSH,KC_NO,
              TG(7), KC_LGUI, LT_NAV_ESC,  LT_ARROW_BSPC, LT_MOUSE_TAB,                             /**/ LT_FUNCTION_DEL, LT_NUMBER_SPC, LT_SYMBOL_ENT, KC_LGUI, KC_LGUI
),
// rgb
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
// RGB_HUD, RGB_HUI, BL_OFF, BL_ON,

/* DESKTOP NAVIGATION LAYER */
[_NAVIGATION] = LAYOUT(

        KC_NO,KC_NO, KC_BTN3,             KC_BTN2,      KC_BTN1,             LCTL(KC_PLUS),               /**/ LCAG(KC_1), LCAG(KC_2), LCAG(KC_3), LCAG(KC_4), LCAG(KC_5), KC_NO,

        KC_NO,KC_NO, LGUI(LCTL(KC_LEFT)), LGUI(KC_TAB), LGUI(LCTL(KC_RGHT)), LCTL(KC_PGUP),               /**/ KC_NO ,LGUI(KC_LEFT), LGUI(KC_RGHT), KC_VOLD, KC_VOLU,KC_NO,

        KC_NO,KC_NO, KC_NO,               KC_NO,        KC_NO,               LCTL(KC_MINS), KC_NO,KC_NO,  /**/ KC_TRNS,KC_NO, SGUI(KC_DEL), SGUI(KC_COMM), SGUI( KC_DOT), KC_MPLY, KC_MUTE,KC_NO,

        KC_TRNS,KC_NO,KC_NO,KC_NO,ALT_TAB,                                                                  /**/ KC_NO,   KC_SPC,  LALT(KC_F4), KC_NO,KC_NO

),

[_ARROW] = LAYOUT(

        KC_NO, KC_LGUI,       KC_BTN3,    KC_BTN2,    KC_BTN1,    KC_NO,                    /**/ KC_PGUP,  KC_HOME, KC_UP,   KC_END,  KC_PGDN,KC_NO,
        KC_NO, LALT(KC_LEFT), KC_LALT,    KC_LCTL,    KC_LSFT,    LALT(KC_RGHT),            /**/ LCTL(KC_PGUP), KC_LEFT, KC_DOWN, KC_RGHT, LCTL(KC_PGDN),KC_NO,
        KC_NO, LCTL(KC_Z),    LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO,KC_NO,KC_NO,         /**/ KC_TRNS, KC_NO, KC_CAPS,  KC_F11, KC_F7,   KC_F8,   KC_F9,KC_NO,
            KC_TRNS,KC_NO, ALT_TAB,  KC_NO,   KC_NO,                                          /**/ KC_PGUP, ALT_TAB, KC_PGDN,KC_NO,KC_NO

),

[_MOUSE] = LAYOUT(

        KC_NO,KC_NO,   KC_WH_U, ALT_TAB, KC_WH_D, KC_NO, /**/ KC_NO, KC_WH_U, KC_MS_U, KC_WH_D, KC_NO, KC_NO,

        KC_NO,KC_NO,   KC_LALT, KC_LCTL, KC_LSFT, KC_NO, /**/ KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO,

        KC_NO,QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, /**/ KC_TRNS,KC_NO,KC_NO, KC_WH_L, KC_BTN1,   KC_WH_R, KC_NO,KC_NO,

        KC_TRNS,KC_NO,KC_TRNS, KC_BTN1,   KC_TRNS,              KC_BTN3, KC_BTN1, KC_BTN2,KC_NO,KC_NO

),

[_SYMBOL] =
LAYOUT(
        KC_NO,KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,
        KC_NO,KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,            KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_BTN1,KC_NO,
        KC_NO,KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,KC_NO,KC_NO,            KC_TRNS,KC_NO,KC_NO, KC_BTN1,   KC_NO,   KC_NO,   KC_NO,KC_NO,
        KC_TRNS, KC_NO, KC_RPRN, KC_UNDS, KC_NO,         KC_NO,KC_NO, KC_NO,KC_NO,KC_NO

),

/* number LAYER */
[_NUMBER] =
LAYOUT(
        KC_NO,KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,
        KC_NO,KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO,KC_NO,
        KC_NO,KC_GRV,  KC_1, KC_2, KC_3, KC_BSLS, KC_NO,KC_NO,      KC_TRNS,KC_NO,KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,KC_NO,
        KC_TRNS,KC_NO,KC_0,  KC_MINS, KC_NO,      KC_NO, KC_NO, KC_NO,KC_NO,KC_NO

),

/* func LAYER */
[_FUNCTION] =
LAYOUT(
        KC_NO,KC_F12, KC_F7, KC_F8, KC_F9, KC_NO,                                      KC_NO, RGB_HUD, RGB_HUI, BL_OFF,  BL_ON, KC_NO,
        KC_NO,KC_F11, KC_F4, KC_F5, KC_F6, KC_NO,                                      KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO, KC_NO,
        KC_NO,KC_F10, KC_F1, KC_F2, KC_F3, KC_TAB,  KC_NO,KC_NO,      KC_TRNS, KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,KC_NO,
        KC_TRNS,KC_NO,KC_ESC, KC_BSPC, KC_TAB,                                KC_DEL, KC_SPC, KC_ENT,KC_NO,KC_NO
        )
,

[_GAME] = LAYOUT(

        KC_TAB,  KC_Q,   KC_W,         KC_E,         KC_R,         KC_T,                   /**/                       KC_Y,       KC_U,        KC_I,         KC_O,        KC_P,    KC_BSPC,
        KC_LCTL, KC_A,   KC_S,         KC_D,         KC_F,         KC_G,                   /**/                       KC_H,       KC_J,        KC_K,         KC_L,        KC_SCLN, KC_RCTL,
        KC_LSFT, KC_Z,   KC_X,         KC_C,         KC_V,         KC_B, KC_LBRC,KC_CAPS,  /**/  KC_TRNS,KC_RBRC,     KC_N,       KC_M,        KC_COMM,      KC_DOT,      KC_SLSH, KC_RSFT,
                               KC_TRNS,KC_NO, KC_ESC,   KC_BSPC, LT_MOUSE_TAB,               /**/  KC_DEL, KC_SPC,      KC_ENT,     KC_NO,KC_NO
)
};



// todo

// END LAYOUT


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


