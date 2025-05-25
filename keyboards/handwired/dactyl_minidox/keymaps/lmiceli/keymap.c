#include QMK_KEYBOARD_H

/*
 *
 *
 * NO PROBADOS NINGUNO
 *
   qmk flash -kb handwired/dactyl_minidox
   qmk flash -kb handwired/dactyl_minidox -km lmiceli

   qmk flash -kb handwired/dactyl_minidox -km lmiceli -bl :avrdude-split-left
   qmk flash -kb handwired/dactyl_minidox -km lmiceli -bl :avrdude-split-right
*/
/*  */

/* new for sync most of my existing keymaps */
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
    LT_ARROW_SP     = LT(_ARROW, KC_SPC),
    LT_MOUSE_TAB    = LT(_MOUSE, KC_TAB),
    LT_FUNCTION_DEL = LT(_FUNCTION, KC_DEL),
    LT_NUMBER_BSP   = LT(_NUMBER, KC_BSPC),
    LT_SYMBOL_ENT   = LT(_SYMBOL, KC_ENT),
    LT_MOUSE_H      = LT(_MOUSE, KC_H),
    LT_FUNCTION_O   = LT(_FUNCTION, KC_O),

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
        // ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
        LCTL_T(KC_Q),     KC_W,         KC_F,         KC_P,         KC_B,          KC_J,            KC_L,         KC_U,         KC_Y,    LCTL_T(KC_BSPC),
        // ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        LT(3,KC_A),   LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T),     KC_G,          KC_M,        LSFT_T(KC_N), LGUI_T(KC_E), LALT_T(KC_I), LT_FUNCTION_O,
        // ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,          KC_K,         LT_MOUSE_H,   KC_COMM,      KC_DOT,       KC_SLSH,
        // ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
        LT_NAV_ESC,   LT_ARROW_SP,  LT_MOUSE_TAB,    LT_NUMBER_BSP, LT_SYMBOL_ENT, KC_LCTL
        //                             ╰─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────┴─────────────╯
        //                         LT_NAV_ESC,   LT_ARROW_BSPC    /**/  LT_FUNCTION_DEL, LT_NUMBER_SPC, LT_SYMBOL_ENT
        ),

    /* DESKTOP NAVIGATION LAYER */
    [_NAVIGATION] = LAYOUT_split_3x5_3(
        _______, KC_BTN3      , KC_BTN2    , KC_BTN1      , _______,     LCAG(KC_1)  , LCAG(KC_2)  , LCAG(KC_3)  , LCAG(KC_4), LCAG(KC_5),
        ALT_TAB, G(C(KC_LEFT)), G(C(KC_UP)), G(C(KC_RGHT)), ALT_TAB,     G(KC_PLUS)  , C(KC_LEFT)  , C(KC_RGHT)  , KC_VOLD   , KC_VOLU   ,
        _______, _______      , _______    , ALT_TAB      , _______,     G(KC_MINS)  , RCS(KC_COMM), RCS( KC_DOT), KC_MPLY   , KC_MUTE   ,
        KC_BTN3    , KC_BTN1      , KC_BTN2,     LAG(KC_LEFT), RCS(KC_DEL) ,LAG(KC_RGHT)

            ),

    [_ARROW] = LAYOUT_split_3x5_3(

        KC_LCTL         , KC_BTN3, KC_BTN2, KC_BTN1, _______      ,     KC_PGUP   , KC_HOME, KC_UP  , KC_END , KC_PGDN   ,
        ALT_TAB         , KC_LALT, KC_LGUI, KC_LSFT, ALT_TAB      ,     KC_F11    , KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS   ,
        A(G(KC_LEFT))   , _______, _______, ALT_TAB, A(G(KC_RGHT)),     G(KC_PGUP), KC_F7  , KC_F8  , KC_F9  , G(KC_PGDN),
        _______, _______, _______,     KC_DEL    , KC_BSPC, KC_PGDN

        ),

    [_MOUSE] = LAYOUT_split_3x5_3(

        KC_NO,   KC_WH_U, ALT_TAB, KC_WH_D, KC_NO, /**/ KC_NO, KC_WH_U, KC_MS_U, KC_WH_D, KC_NO,

        KC_NO,   KC_LALT, KC_LGUI, KC_LSFT, KC_NO, /**/ KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,

        QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO, /**/ KC_NO, KC_WH_L, KC_BTN1,   KC_WH_R, KC_NO,

        KC_TRNS, KC_BTN1,   KC_TRNS,    KC_BTN3, KC_BTN1, KC_BTN2

        ),

    [_SYMBOL] =
        LAYOUT_split_3x5_3(
            KC_QUOT, KC_LT  , KC_GT  , KC_DQT , KC_DOT ,    KC_AMPR, KC_LBRC, KC_RBRC, KC_SCLN, KC_PERC,
            KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,    KC_PIPE, KC_LPRN, KC_RPRN, KC_COLN, KC_QUES,
            KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_GRV ,    KC_TILD, KC_LCBR, KC_RCBR, KC_DLR , KC_AT,

            KC_BSPC, KC_UNDS, KC_LGUI,    KC_LSFT, _______, KC_LCTL

            ),

    /* number LAYER */
    [_NUMBER] =
        LAYOUT_split_3x5_3(
            _______, KC_7, KC_8, KC_9, _______,    _______, _______, _______, _______, KC_LCTL,
            KC_0   , KC_4, KC_5, KC_6, _______,    _______, KC_LSFT, KC_LGUI, KC_LALT, _______,
            _______, KC_1, KC_2, KC_3, _______,    _______, _______, _______, _______, _______,
            KC_BSPC, KC_SPC, KC_DEL,    _______, _______, KC_NO

            ),

    /* func LAYER */
    [_FUNCTION] =
        LAYOUT_split_3x5_3(
            KC_F12, KC_F7, KC_F8, KC_F9, _______,      _______, _______, _______, KC_LCTL, _______,
            KC_F11, KC_F4, KC_F5, KC_F6, _______,      _______, KC_LSFT, KC_LGUI, KC_LALT, _______,
            KC_F10, KC_F1, KC_F2, KC_F3,  KC_TAB,      _______, _______, _______, _______, QK_BOOT,
            KC_ESC, KC_SPC, KC_TAB,      KC_BSPC, KC_ENT, KC_LCTL)
};
