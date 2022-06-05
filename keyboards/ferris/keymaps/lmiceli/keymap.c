#include QMK_KEYBOARD_H

/*  */
/*  */
/*  */
/* ALT TAB */
bool is_alt_tab_active = false;
enum custom_keycodes {          // Make sure have the awesome keycode ready
  ALT_TAB = SAFE_RANGE,
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_alt_tab_active) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
    return state;
}

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(

LGUI_T(KC_Q), KC_W,         KC_F,         KC_P,         KC_B,         /**/ KC_J,         KC_L,         KC_U,         KC_Y,         LGUI_T(KC_QUOT),

LT(3,KC_A),   LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), LGUI_T(KC_G), /**/ LGUI_T(KC_M), LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LT(6,KC_O),

KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,         /**/ KC_K,         KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,

										 LT(1,KC_ESC),  LT(2,KC_BSPC),/**/ LT(5,KC_SPC), LT(4,KC_ENT)
	),



/* DESKTOP NAVIGATION LAYER */
	[1] = LAYOUT(

KC_NO, KC_BTN2,             KC_BTN3,      KC_BTN1,             LCTL(KC_PLUS),   /**/ KC_NO,        SGUI(KC_L),    SGUI(KC_U),   KC_MPRV, KC_MNXT,

KC_NO, LGUI(LCTL(KC_LEFT)), LGUI(KC_TAB), LGUI(LCTL(KC_RGHT)), KC_NO,         /**/ KC_NO,        SGUI(KC_N),    SGUI(KC_E),   KC_VOLD, KC_VOLU,

KC_NO, KC_NO,               KC_NO,        KC_NO,               LCTL(KC_MINS),   /**/ SGUI(KC_DEL), SGUI(KC_COMM), SGUI(KC_DOT), KC_MPLY, KC_MUTE,

                                 	      KC_NO,               ALT_TAB,       /**/ ALT_TAB,      LALT(KC_F4)//SGUI(KC_SPC), SGUI(KC_ENT)

),

/* ARROW LAYER */

	[2] = LAYOUT(

KC_LGUI,       KC_BTN2,    KC_BTN3,    KC_BTN1,    LCTL(KC_PGUP), /**/ KC_PGUP,      KC_HOME, KC_UP,   KC_END,  KC_PGDN,

LALT(KC_LEFT), KC_LALT,    KC_LCTL,    KC_LSFT,    KC_CAPS,      /**/ LCA(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, LCA(KC_RGHT),

LCTL(KC_Z),    LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_PGDN), /**/ KC_F11,       KC_F7,   KC_F8,   KC_F9,   LALT(KC_RGHT),

                                       ALT_TAB,     KC_NO,        /**/ KC_TAB,       KC_DEL

),

/* MOUSE LAYER */

	[3] = LAYOUT(

KC_NO, KC_WH_U, ALT_TAB, KC_WH_D, KC_NO, /**/ KC_NO, KC_WH_U, KC_MS_U, KC_WH_D, KC_NO,

KC_NO, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, /**/ KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,

KC_NO, KC_NO,   KC_NO,   KC_BTN2,   KC_NO, /**/ KC_NO, KC_WH_L, KC_NO,   KC_WH_R, KC_NO,

              KC_BTN3, KC_BTN1, KC_BTN1, KC_BTN2),

    [4] = LAYOUT(KC_LCBR, KC_AMPR, KC_ASTR,a KC_LPRN, KC_RCBR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RPRN, KC_UNDS, KC_NO, KC_NO),
	[5] = LAYOUT(KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_MINS, KC_NO, KC_NO),
	[6] = LAYOUT(KC_F12, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F11, KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_BSPC, KC_SPC, KC_ENT)
};
