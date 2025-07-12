#include QMK_KEYBOARD_H

/*

 qmk flash -kb handwired/dactyl_minidox -km lmiceli
 en el lado q sea (entiendo q si no lo hago en los dos uno se me queda desactualizado

 para programar el handednes se hace una vez asi:

 make handwired/dactyl_minidox:lmiceli:avrdude-split-left
 make handwired/dactyl_minidox:lmiceli:avrdude-split-right


 reset:
 https://www.dlford.io/keyboard-build-guide-per-key-rgb-leds/

con las pinzitas, apenas se ve asi q espero q no me vuelva a desprogramar
el qmk_boot


*/


/* new for sync most of my existing keymaps */
enum layers {
    _COLEMAK = 0,
    _MOUSE,
    _ARROW,
    _NAVIGATION,
    _SYMBOL,
    _NUMBER,
    _FUNCTION,
    _SERVICE,
};

/*  */
/* ALT TAB */
bool is_alt_tab_active = false;
//#define MOUSE_TIMEOUT 10000  // 10 seconds in milliseconds
//uint32_t mouse_timer = 0;

enum custom_keycodes {          // Make sure have the awesome keycode ready
    ALT_TAB         = SAFE_RANGE,
    LT_MOUSE_H      = LT(_MOUSE, KC_H),
    LT_ARROW_SP     = LT(_ARROW, KC_SPC),
    LT_NAV_ESC      = LT(_NAVIGATION, KC_ESC),
    LT_MOUSE_TAB    = LT(_MOUSE, KC_TAB),
    LT_FUNCTION_DEL = LT(_FUNCTION, KC_DEL),
    LT_NUMBER_BSP   = LT(_NUMBER, KC_BSPC),
    LT_SYMBOL_ENT   = LT(_SYMBOL, KC_ENT),
    LT_FUNCTION_O   = LT(_FUNCTION, KC_O),
    LT_SERV_A       = LT(_SERVICE, KC_A),// todox: A is not necessary

    // for use in symbol layer to access numbers
    LT_NUMBER_QUES   = LT(_NUMBER, KC_QUES),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_alt_tab_active) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
    return state;
}

// todo: fix toggle mouse layer automatically after 10 seconds of inactivity
//  no rush i may not even like it
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

// todo: fix toggle mouse layer automatically after 10 seconds of inactivity
//  no rush i may not even like it
// Modify layer_state_set_user
//layer_state_t layer_state_set_user(layer_state_t state) {
//    // Handle alt-tab
//    if (is_alt_tab_active) {
//        unregister_code(KC_LALT);
//        is_alt_tab_active = false;
//    }
//
//    // Handle mouse layer timeout
//    if (IS_LAYER_ON_STATE(state, _MOUSE)) {
//        if (mouse_timer == 0) {
//            mouse_timer = timer_read32();
//        } else if (timer_elapsed32(mouse_timer) > MOUSE_TIMEOUT) {
//            state = layer_state_set(state & ~(1UL << _MOUSE));
//            mouse_timer = 0;
//        }
//    } else {
//        mouse_timer = 0;
//    }
//
//    return state;
//}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
        // ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
        LCTL_T(KC_Q),     KC_W,         KC_F,         KC_P,         KC_B,          KC_J,            KC_L,         KC_U,         KC_Y,         TG(_MOUSE),
        // ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        LT(3,KC_A),   LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T),     KC_G,          KC_M,        LSFT_T(KC_N), LGUI_T(KC_E), LALT_T(KC_I), LT_FUNCTION_O,
        // ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,          KC_K,         LT_MOUSE_H,   KC_COMM,      KC_DOT,       KC_SLSH,
        // ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                                         LT_NAV_ESC,   LT_ARROW_SP,  LT_MOUSE_TAB,    LT_NUMBER_BSP, LT_SYMBOL_ENT, KC_LCTL
        //                             ╰─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────┴─────────────╯
        //                         LT_NAV_ESC,   LT_ARROW_BSPC    /**/  LT_FUNCTION_DEL, LT_NUMBER_SPC, LT_SYMBOL_ENT
        ),

    [_MOUSE] = LAYOUT_split_3x5_3(
// TG(_MOUSE), again here for togling back from this layer in the left side too
        TG(_MOUSE), KC_BTN3, KC_BTN2, KC_BTN1,   G(KC_W),    /**/ KC_NO, KC_WH_U, KC_MS_U, KC_WH_D, _______,

        ALT_TAB,    KC_LALT, KC_LGUI, KC_LSFT  , ALT_TAB,    /**/ KC_NO, KC_MS_L, KC_MS_D,   KC_MS_R, KC_NO,

        KC_WH_L,    KC_WH_U, ALT_TAB, KC_WH_D,   KC_WH_R,    /**/ KC_NO, KC_WH_L, KC_BTN1,   KC_WH_R, KC_NO,

                          _______, _______,   KC_ENT,          KC_BTN3, KC_BTN1, KC_BTN2
        ),

    [_ARROW] = LAYOUT_split_3x5_3(

        KC_LCTL, KC_BTN3, KC_BTN2, KC_BTN1, G(KC_W),     KC_PGUP   , KC_HOME, KC_UP  , KC_END , KC_PGDN   ,
        ALT_TAB, KC_LALT, KC_LGUI, KC_LSFT, ALT_TAB,     KC_F11    , KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS   ,
        KC_WH_L, KC_WH_U, ALT_TAB, KC_WH_D, KC_WH_R,     KC_F6,      KC_F7  , KC_F8  , KC_F9  , KC_F12,

                          _______, _______, _______,     KC_DEL    , KC_BSPC, KC_PGDN

        ),

    /* DESKTOP NAVIGATION LAYER */
    [_NAVIGATION] = LAYOUT_split_3x5_3(
        LT_SERV_A, KC_BTN3,       KC_BTN2,     KC_BTN1,       G(KC_W),     LCAG(KC_1)  , LCAG(KC_2)  , LCAG(KC_3)  , LCAG(KC_4), LCAG(KC_5),
        ALT_TAB,   G(C(KC_LEFT)), G(C(KC_UP)), G(C(KC_RGHT)), ALT_TAB,     G(KC_PLUS)  , C(KC_LEFT)  , C(KC_RGHT)  , KC_VOLD   , KC_VOLU   ,
        KC_WH_L,   KC_WH_U,       ALT_TAB,     KC_WH_D,       KC_WH_R,     G(KC_MINS)  , RCS(KC_COMM), RCS( KC_DOT), KC_MPLY   , KC_MUTE   ,

                                  KC_BTN3    , KC_BTN1      , KC_BTN2,     LAG(KC_LEFT), RCS(KC_DEL) ,LAG(KC_RGHT)
        ),

    // try? LSFT_T(KC_?), LGUI_T(KC_?), LALT_T(KC_?),  LCTL_T(KC_?)
    [_SYMBOL] =
        LAYOUT_split_3x5_3(
            KC_QUOT, KC_LT  , KC_GT  , KC_DQT , KC_DOT ,    KC_AMPR, KC_LBRC, KC_RBRC, KC_SCLN, KC_PERC,
            KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,    KC_PIPE, KC_LPRN, KC_RPRN, KC_COLN, LT_NUMBER_QUES,
            KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_GRV ,    KC_TILD, KC_LCBR, KC_RCBR, KC_DLR , KC_AT,

                              KC_BSPC, KC_UNDS, KC_LGUI,    KC_LSFT, _______, KC_LCTL

            ),
// missing : , .
    /* number LAYER */
    [_NUMBER] =
        LAYOUT_split_3x5_3(
            _______, KC_7, KC_8, KC_9, _______,    _______, _______, _______, _______, KC_LCTL,
            KC_0   , KC_4, KC_5, KC_6, KC_COLN,    _______, KC_LSFT, KC_LGUI, KC_LALT, _______,
            _______, KC_1, KC_2, KC_3, _______,    _______, _______, _______, _______, _______,
                       KC_BSPC, KC_SPC, KC_DEL,    _______, _______, KC_NO

            ),

    /* func LAYER */
    [_FUNCTION] =
        LAYOUT_split_3x5_3(
            KC_F12, KC_F7, KC_F8, KC_F9, _______,      _______, _______, _______, KC_LCTL, _______,
            KC_F11, KC_F4, KC_F5, KC_F6, _______,      _______, KC_LSFT, KC_LGUI, KC_LALT, _______,
            KC_F10, KC_F1, KC_F2, KC_F3,  KC_TAB,      _______, _______, _______, _______, QK_BOOT,// todox remove later boot get from service
                          KC_ESC, KC_SPC, KC_TAB,      KC_BSPC, KC_ENT, KC_LCTL
            ),

    /* func LAYER */
    [_SERVICE] =
        LAYOUT_split_3x5_3(
            _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
            QK_BOOT, _______, _______, _______, _______,      _______, _______, _______, _______, QK_BOOT,
                              _______, _______, _______,      _______, _______, _______
            )
};
/*
 * test area
 *
 *
 * uullljjjjjlumneiooooo
 *
 *
 * */
