#include QMK_KEYBOARD_H

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

/*
 * make bastardkb/charybdis/3x5/v1/elitec:lmiceli:flash
 * */

// #define SLH_MOU LT(_MOU, KC_SLSH)

enum layers {
    _BASE = 0,
    _NAVIGATION,
    _ARROW,
    _MOUSE,
    _SYMBOL,
    _NUMBER,
    _FUNCTION,
    _MISC,
};

// Automatically enable sniping-mode on the pointer layer.
// #define CHARYBDIS_AUTO_SNIPING_ON_LAYER _MOUSE

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

/* ALT TAB */
bool is_alt_tab_active = false;

enum custom_keycodes { // Make sure have the awesome keycode ready
    ALT_TAB         = SAFE_RANGE,

    K_DPI           ,
    K_DPI_SNIP      ,
    K_ENIE          ,

    SCL_DRG         ,

    LT_NAV_ESC      = LT(_NAVIGATION, KC_ESC),
    LT_MISC_ESC     = LT(_MISC, KC_ESC),
    LT_ARROW_SPC    = LT(_ARROW, KC_SPC),
    LT_MOUSE_TAB    = LT(_MOUSE, KC_TAB),
    LT_FUNCTION_DEL = LT(_FUNCTION, KC_DEL),
    LT_FUNCTION_O   = LT(_FUNCTION, KC_O),
    LT_NUMBER_BSPC  = LT(_NUMBER, KC_BSPC),
    LT_SYMBOL_ENT   = LT(_SYMBOL, KC_ENT),
    LT_MOUSE_H      = LT(_MOUSE, KC_H),
    LT_MOUSE_SLSH   = LT(_MOUSE, KC_SLSH),
    LT_NAV_A        = LT(_NAVIGATION, KC_A),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_alt_tab_active) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t my_hash_timer;
    switch (keycode) {
            // todo todox is this working? should I let it fall through to default keymap? is that how this works?
        case SCL_DRG:
            if (record->event.pressed) {
                my_hash_timer = timer_read();
                charybdis_set_pointer_dragscroll_enabled(!charybdis_get_pointer_dragscroll_enabled());
            } else {
                charybdis_set_pointer_dragscroll_enabled(!charybdis_get_pointer_dragscroll_enabled());
                if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
                    SEND_STRING(";"); // Change the character(s) to be sent on tap here
                }
            }
            return false; // We handled this keypress
        case ALT_TAB:     // super alt tab macro
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;

        case K_DPI:
            if (record->event.pressed) {
                uint16_t dpi = charybdis_get_pointer_default_dpi();
                // no consigo pasarlo a string y q send_string lo procese
                if (dpi == 1200){
                    SEND_STRING(" 1200");
                } else if (dpi == 1600){
                    SEND_STRING(" 1600");
                } else if (dpi == 800){
                    SEND_STRING(" 800");
                } else if (dpi == 400){
                    SEND_STRING(" 400");
                } else if (dpi == 2000){
                    SEND_STRING(" 2000");
                } else if (dpi == 2400){
                    SEND_STRING(" 2400");
                } else if (dpi == 2800){
                    SEND_STRING(" 2800");
                } else if (dpi == 3200){
                    SEND_STRING(" 3200");
                } else if (dpi == 3600){
                    SEND_STRING(" 3600");
                } else if (dpi == 4000){
                    SEND_STRING(" 4000");
                } else if (dpi == 4400){
                    SEND_STRING(" 4400");
                } else if (dpi == 4800){
                    SEND_STRING(" 4800");
                } else if (dpi == 5200){
                    SEND_STRING(" 5200");
                } else if (dpi == 5600){
                    SEND_STRING(" 5600");
                } else if (dpi >= 6000){
                    SEND_STRING(" >6000");
                } else if (dpi <= 1200){
                    SEND_STRING(" <1200");
                } else if (dpi == 6800){
                    SEND_STRING(" 6800");
                } else if (dpi == 7200){
                    SEND_STRING(" 7200");
                } else {
                    SEND_STRING(" ?");
                }
            } else { }
            return false;

        case K_DPI_SNIP:
            if (record->event.pressed) {
                uint16_t dpi = charybdis_get_pointer_sniping_dpi();
                if (dpi == 200){
                    SEND_STRING(" s 200");
                } else if (dpi == 300){
                    SEND_STRING(" s 300");
                } else if (dpi == 400){
                    SEND_STRING(" s 400");
                } else if (dpi == 500){
                    SEND_STRING(" s 500");
                } else if (dpi <= 200){
                    SEND_STRING(" s <200");
                } else {
                    SEND_STRING(" s ?");
                }
            } else { }
            return false;

//            en principio esto no va sin hacer toda la configuracinon de https://docs.qmk.fm/features/unicode
//        case K_ENIE:
//            if (record->event.pressed) {
////                send_unicode_string("ñ");
//            } else { }
//            return false;

    }
    return true; // We didn't handle other keypresses
}

/* // clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_charybdis_3x5(
LCTL_T(KC_Q), KC_W         , KC_F        , KC_P        , KC_B,          KC_J          , KC_L        , KC_U        , KC_Y        , LCTL_T(KC_BSPC)      ,
KC_A        , LALT_T(KC_R) , LGUI_T(KC_S), LSFT_T(KC_T), KC_G,          KC_M          , LSFT_T(KC_N), LGUI_T(KC_E), LALT_T(KC_I), LT_FUNCTION_O        ,
KC_Z        , KC_X         , KC_C        , KC_D        , KC_V,          KC_K          , LT_MOUSE_H  , KC_COMM     , KC_DOT      , LT_MOUSE_SLSH        ,
                      LT_NAV_ESC , LT_ARROW_SPC, LT_MOUSE_TAB,          LT_NUMBER_BSPC, LT_SYMBOL_ENT
),
    /* DESKTOP NAVIGATION LAYER */
    [_NAVIGATION] = LAYOUT_charybdis_3x5(
_______, KC_BTN3      , KC_BTN2    , KC_BTN1      , _______,     LCAG(KC_1)  , LCAG(KC_2)  , LCAG(KC_3)  , LCAG(KC_4), LCAG(KC_5),
SNIPING, G(C(KC_LEFT)), G(C(KC_UP)), G(C(KC_RGHT)), ALT_TAB,     G(KC_PLUS)  , C(KC_LEFT)  , C(KC_RGHT)  , KC_VOLD   , KC_VOLU   ,
_______, _______      , _______    , SCL_DRG      , _______,     G(KC_MINS)  , RCS(KC_COMM), RCS( KC_DOT), KC_MPLY   , KC_MUTE   ,
                        KC_BTN3    , KC_BTN1      , KC_BTN2,     LAG(KC_LEFT), RCS(KC_DEL) /*,LAG(KC_RGHT)*/
),
[_ARROW] = LAYOUT_charybdis_3x5(
KC_LCTL         , KC_BTN3, KC_BTN2, KC_BTN1, _______      ,     KC_PGUP   , KC_HOME, KC_UP  , KC_END , KC_PGDN   ,
SNIPING         , KC_LALT, KC_LGUI, KC_LSFT, ALT_TAB      ,     KC_F11    , KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS   ,
A(G(KC_LEFT))   , _______, _______, SCL_DRG, A(G(KC_RGHT)),     G(KC_PGUP), KC_F7  , KC_F8  , KC_F9  , G(KC_PGDN),
                           _______, _______, _______      ,     KC_DEL    , KC_BSPC
),
    [_MOUSE] = LAYOUT_charybdis_3x5(                                                            /*MOUSE*/
QK_RBT , KC_WH_D, SCL_DRG   , KC_BTN1, KC_WH_U,    KC_WH_D, DPI_RMOD, DPI_MOD, S_D_RMOD, S_D_MOD,
SNIPING, KC_LALT, KC_LGUI   , KC_LSFT, KC_LCTL,    KC_WH_U, KC_BTN1 , KC_BTN3, KC_BTN2 , KC_BTN6,
QK_BOOT, K_DPI  , K_DPI_SNIP, KC_BTN3, _______,    SCL_DRG, KC_BTN1 , KC_BTN3, KC_BTN2 , _______,
                  KC_BTN2   , KC_BTN1, _______,    KC_WH_L, KC_WH_R
),
    [_SYMBOL] = LAYOUT_charybdis_3x5(
KC_QUOT, KC_LT  , KC_GT  , KC_DQT , KC_DOT ,    KC_AMPR, KC_LBRC, KC_RBRC, KC_SCLN, KC_PERC,
KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,    KC_PIPE, KC_LPRN, KC_RPRN, KC_COLN, KC_QUES,
KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_GRV ,    KC_TILD, KC_LCBR, KC_RCBR, KC_DLR , KC_AT,
                  KC_BSPC, KC_UNDS, KC_LGUI,    KC_LSFT, _______
),
    /* number LAYER */
    [_NUMBER] =LAYOUT_charybdis_3x5(
_______, KC_7, KC_8, KC_9, _______,    _______, _______, _______, _______, KC_LCTL,
KC_0   , KC_4, KC_5, KC_6, _______,    _______, KC_LSFT, KC_LGUI, KC_LALT, _______,
_______, KC_1, KC_2, KC_3, _______,    _______, _______, _______, _______, _______,
           KC_BSPC, KC_SPC, KC_DEL,    _______, _______
),
    /* func LAYER */
    [_FUNCTION] =LAYOUT_charybdis_3x5(
KC_F12, KC_F7, KC_F8, KC_F9, _______,      _______, _______, _______, KC_LCTL, _______,
KC_F11, KC_F4, KC_F5, KC_F6, _______,      _______, KC_LSFT, KC_LGUI, KC_LALT, _______,
KC_F10, KC_F1, KC_F2, KC_F3, KC_TAB,       _______, _______, _______, _______, _______,
              KC_ESC, KC_SPC, KC_TAB,      KC_BSPC, KC_ENT
),
    [_MISC] = LAYOUT_charybdis_3x5(
LCTL_T(KC_Q), KC_W         , KC_F        , KC_P        , KC_B,          KC_J          , KC_L        , KC_U        , KC_Y        , LCTL_T(LALT(KC_BSPC)),
LT_NAV_A    , KC_LALT      , KC_LGUI     , KC_LSFT     , KC_G,          KC_M          , K_ENIE      , LGUI_T(KC_E), LALT_T(KC_I), LT_FUNCTION_O        ,
KC_Z        , KC_X         , KC_C        , KC_D        , KC_V,          KC_K          , LT_MOUSE_H  , KC_COMM     , KC_DOT      , KC_SLSH              ,
        KC_C, KC_C, KC_C,  KC_C, KC_C
)

};

// AUTO MOUSE LAYER (disabled in config.h atm)
// copied from via keymap (not sure what I am doing)

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(_MOUSE);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(_MOUSE);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

/*


                          // Mouse.
#define LAYOUT_LAYER_MOUSE                                                                    \
S_D_MOD, USR_PST, USR_CPY, USR_CUT, USR_UND, USR_RDO, USR_PST, USR_CPY, USR_CUT, USR_UND, \
DPI_MOD, DRGSCRL, KC_LSFT, KC_LCTL, _______,    U_NU,    MS_L,    MS_D,    MS_U,    MS_R, \
USR_RDO, USR_PST, USR_CPY, USR_CUT, USR_UND,    U_NU,    WH_L,    WH_D,    WH_U,    WH_R, \
KC_BTN2, KC_BTN1, KC_BTN3, KC_BTN1, KC_BTN3
*/

/* // clang-format on */
/* #ifdef RGB_MATRIX_ENABLE */
/* // Forward-declare this helper function since it is defined in rgb_matrix.c. */
/* void rgb_matrix_update_pwm_buffers(void); */
/* #endif */

/* void shutdown_user(void) { */
/* #ifdef RGBLIGHT_ENABLE */
/*     rgblight_enable_noeeprom(); */
/*     rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); */
/*     rgblight_setrgb_red(); */
/* #endif  // RGBLIGHT_ENABLE */
/* #ifdef RGB_MATRIX_ENABLE */
/*     rgb_matrix_set_color_all(RGB_RED); */
/*     rgb_matrix_update_pwm_buffers(); */
/* #endif  // RGB_MATRIX_ENABLE */
/* } */
