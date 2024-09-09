#include QMK_KEYBOARD_H

/*
 *
 * // this is only for the first time of setting ee hands?
 *
   qmk flash -kb handwired/dactyl_manuform/3x5_3 -km lmiceli -bl :avrdude-split-left
   qmk flash -kb handwired/dactyl_manuform/3x5_3 -km lmiceli -bl :avrdude-split-right
*/

/*  */

enum skeletyl_tap_dances {
    //   TD_Q_GUI
    TD_G_CAPS,
    TD_TAB_MOUSE
};


enum layers {
    _COLEMAK = 0,
    _NAVIGATION,
    _ARROW,
    _MOUSE,
    _SYMBOL,
    _NUMBER,
    _FUNCTION,
};

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
	[0] = LAYOUT_split_3x5_3(

LGUI_T(KC_Q), KC_W,         KC_F,         KC_P,         KC_B,         /**/ KC_J,  KC_L,         KC_U,         KC_Y,         LGUI_T(KC_QUOT),
/*LT(3,KC_A)*/                                          /*TD(TD_G_CAPS)*/                                             /*LT(6,KC_O)*/
KC_A,         LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,         /**/ KC_M,  LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), KC_O,

KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,         /**/ KC_K,  LT_MOUSE_H,   KC_COMM,      KC_DOT,       KC_SLSH,

			            // LT_NAV_ESC,   LT_ARROW_BSPC, TG(_MOUSE),      /**/ LT_FUNCTION_DEL, LT_NUMBER_SPC, LT_SYMBOL_ENT
			            //LT_NAV_ESC,   LT_ARROW_BSPC, TD(TD_TAB_MOUSE),    /**/ LT_FUNCTION_DEL, LT_NUMBER_SPC, LT_SYMBOL_ENT
                        LT_NAV_ESC,   LT_ARROW_BSPC, LT_MOUSE_TAB,    /**/  LT_FUNCTION_DEL, LT_NUMBER_SPC, LT_SYMBOL_ENT
	),

/* DESKTOP NAVIGATION LAYER */
	[_NAVIGATION] = LAYOUT_split_3x5_3(

KC_NO, KC_BTN3,             KC_BTN2,      KC_BTN1,             LCTL(KC_PLUS),   /**/ LCAG(KC_1), LCAG(KC_2), LCAG(KC_3), LCAG(KC_4), LCAG(KC_5), /*KC_MPRV, KC_MNXT,*/

KC_NO, LGUI(LCTL(KC_LEFT)), LGUI(KC_TAB), LGUI(LCTL(KC_RGHT)), LCTL(KC_PGUP),   /**/ KC_NO ,LGUI(KC_LEFT), LGUI(KC_RGHT), KC_VOLD, KC_VOLU,

KC_NO, KC_NO,               KC_NO,        KC_NO,               LCTL(KC_MINS),   /**/ SGUI(KC_DEL), SGUI(KC_COMM), SGUI( KC_DOT), KC_MPLY, KC_MUTE,

                                 	      KC_NO,KC_NO,ALT_TAB,                  /**/ KC_NO,   KC_SPC,  LALT(KC_F4)//SGUI(KC_SPC), SGUI(KC_ENT)

),

	[_ARROW] = LAYOUT_split_3x5_3(

KC_LGUI,       KC_BTN3,    KC_BTN2,    KC_BTN1,    KC_NO,         /**/ KC_PGUP,  KC_HOME, KC_UP,   KC_END,  KC_PGDN,
                                                                    /*LCA(KC_LEFT)*/                            /*LCA(KC_RGHT)*/
LALT(KC_LEFT), KC_LALT,    KC_LCTL,    KC_LSFT,    LALT(KC_RGHT), /**/ LCTL(KC_PGUP), KC_LEFT, KC_DOWN, KC_RGHT, LCTL(KC_PGDN),

LCTL(KC_Z),    LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO,         /**/ KC_CAPS,  KC_F11, KC_F7,   KC_F8,   KC_F9,

                                       ALT_TAB,  KC_NO,   KC_NO,  /**/ KC_PGUP, ALT_TAB, KC_PGDN

),

	[_MOUSE] = LAYOUT_split_3x5_3(

KC_NO,   KC_WH_U, ALT_TAB, KC_WH_D, KC_NO, /**/ KC_NO, KC_WH_U, KC_MS_U, KC_WH_D, KC_NO,

KC_NO,   KC_LALT, KC_LCTL, KC_LSFT, KC_NO, /**/ KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,

QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO, /**/ KC_NO, KC_WH_L, KC_BTN1,   KC_WH_R, KC_NO,

                KC_TRNS, KC_BTN1,   KC_TRNS,    KC_BTN3, KC_BTN1, KC_BTN2

),

    [_SYMBOL] =
    LAYOUT_split_3x5_3(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,            KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_BTN1,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,            KC_NO, KC_BTN1,   KC_NO,   KC_NO,   KC_NO,
     KC_RPRN, KC_UNDS, KC_NO,         KC_NO,KC_NO, KC_NO

),

     /* number LAYER */
	[_NUMBER] =
	LAYOUT_split_3x5_3(
	KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO,
	KC_GRV,  KC_1, KC_2, KC_3, KC_BSLS,       KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_0,  KC_MINS, KC_NO,      KC_NO, KC_NO, KC_NO

),

	 /* func LAYER */
	[_FUNCTION] =
	LAYOUT_split_3x5_3(
	KC_F12, KC_F7, KC_F8, KC_F9, KC_NO,       KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
	KC_F11, KC_F4, KC_F5, KC_F6, KC_NO,       KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_NO,
	KC_F10, KC_F1, KC_F2, KC_F3, KC_TAB,      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
	              KC_ESC, KC_BSPC, KC_TAB,    KC_DEL, KC_SPC, KC_ENT)
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    //[TD_Q_GUI] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_LGUI)
    [TD_G_CAPS] =  ACTION_TAP_DANCE_DOUBLE(KC_G, KC_CAPS),
    [TD_TAB_MOUSE] = ACTION_TAP_DANCE_LAYER_MOVE(KC_M, 3)
};



// Quantum keys / Abbreviations
// BAK/IDEAS
/*
enum custom_keycodes {
    VVV = KC_TRNS,
    XXX = KC_NO,
    CSA_Q = MEH_T(KC_Q),
    CSA_F1 = MEH_T(KC_F1),
    CSA_1 = MEH_T(KC_1),
    CA_W = LCA_T(KC_W),
    CA_F2 = LCA_T(KC_F2),
    CA_2 = LCA_T(KC_2),
    CS_E = C_S_T(KC_E),
    CS_F = C_S_T(KC_F),
    CS_I = C_S_T(KC_I),
    CS_U = C_S_T(KC_U),
    CS_F3 = C_S_T(KC_F3),
    CS_3 = C_S_T(KC_3),
    CS_F8 = C_S_T(KC_F8),
    CS_8 = C_S_T(KC_8),
    CA_O = LCA_T(KC_O),
    CA_Y = LCA_T(KC_Y),
    CA_F9 = LCA_T(KC_F9),
    CA_9 = LCA_T(KC_9),
    CSA_P = MEH_T(KC_P),
    CSA_SCLN = MEH_T(KC_SCLN),
    CSA_F10 = MEH_T(KC_F10),
    CSA_0 = MEH_T(KC_0),
    LGUI_A = LGUI_T(KC_A),
    LGUI_FIND = LGUI_T(KC_FIND),
    LGUI_GRV = LGUI_T(KC_GRV),
    LALT_S = LALT_T(KC_S),
    LALT_R = LALT_T(KC_R),
    LALT_HOME = LALT_T(KC_HOME),
    LCTL_D = LCTL_T(KC_D),
    LCTL_S = LCTL_T(KC_S),
    LCTL_PGUP = LCTL_T(KC_PGUP),
    LCTL_LBRC = LCTL_T(KC_LBRC),
    LSFT_F = LSFT_T(KC_F),
    _LSFT_T = LSFT_T(KC_T),
    LSFT_PGDN = LSFT_T(KC_PGDN),
    LSFT_RBRC = LSFT_T(KC_RBRC),
    RSFT_J = RSFT_T(KC_J),
    RSFT_N = RSFT_T(KC_N),
    RSFT_DOWN = RSFT_T(KC_DOWN),
    RSFT_MINS = RSFT_T(KC_MINS),
    RCTL_K = RCTL_T(KC_K),
    RCTL_E = RCTL_T(KC_E),
    RCTL_UP = RCTL_T(KC_UP),
    RCTL_EQL = RCTL_T(KC_EQL),
    RALT_L = RALT_T(KC_L),
    RALT_I = RALT_T(KC_I),
    RALT_RGHT = RALT_T(KC_RGHT),
    RALT_BSLS = RALT_T(KC_BSLS),
    RGUI_SCLN = RGUI_T(KC_SCLN),
    RGUI_O = RGUI_T(KC_O),
    RGUI_F11 = RGUI_T(KC_F11),
    RGUI_QUOT = RGUI_T(KC_QUOT),
    LT3_SPC = LT(3,KC_SPC),
    LT2_TAB = LT(2,KC_TAB),
    DF_QWERTY = DF(0),
    DF_COLEMAK = DF(1),
};
*/
