/** @file mcrown.h
 *  @brief mcrown header thant incluedes key layout and some definintions. *
 */

#pragma once

#include QMK_KEYBOARD_H

#define K_XXX KC_NO
// #define KC_LOWER LOWER
// #define KC_COLEMAK COLEMAK
// #define KC_CTLTB CTL_T(KC_TAB)
// #define KC_GUIEI GUI_T(KC_LANG2)
#define SGUI_TAB SGUI(KC_TAB)
#define LGUI_TAB LGUI(KC_TAB)

#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define CTL_S LCTL_T(KC_S)
#define SHFT_T LSFT_T(KC_T)

#define SFT_N LSFT_T(KC_N)
#define CTL_E LCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O LGUI_T(KC_O)

#define T1_ESC LT(1,KC_ESC)
#define T2_BSPC LT(2,KC_BSPC)
#define T3_TAB LT(3,KC_TAB)      
#define T4_ENT LT(4,KC_ENT)
#define T5_SPC LT(5,KC_SPC)
#define T6_DEL LT(6,KC_DEL)
#define BACK LALT(KC_LEFT)
#define FWD LALT(KC_RGHT)

#define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)

/* Each layer gets a name for readability */
enum layers {
  _COLEMAK = 0,
  _NAVMEDIA,
  _ARROW,
  _MOUSE,
  _SYMBOL,
  _NUMBER,
  _FUNCTION
};

/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
                              /*|---------+---------+---------|     |---------+---------+---------|*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] =  LAYOUT_wrapper(
          
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
   SGUI_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,           KC_CAPS,  KC_L,     KC_U,     KC_Y,    KC_J,     KC_WH_U,
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
    KC_F11,    GUI_A,    ALT_R,    CTL_S,   SHFT_T,    KC_G,           KC_M,     SFT_N,    CTL_E,    ALT_I,    GUI_O,   KC_QUOT,
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
   LGUI_TAB,    KC_Z,    KC_X,     KC_C,     KC_D,     KC_V,           KC_K,     KC_H,    KC_COMM,   KC_DOT,  KC_SLSH,  KC_WH_D,
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
                                  T1_ESC,   T2_BSPC,  T3_TAB,         T4_ENT,   T5_SPC,    T6_DEL
                              /*|---------+---------+---------|     |---------+---------+---------|*/
  ),
        
  [_NAVMEDIA] =  LAYOUT_wrapper(

/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
/*|                      MOU 2     MOU 3     MOU 1                              - PANE    + PANE    SGUI Y     PREV      NEXT   |*/
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
/*| |*/
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
/*| |*/
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
/*| |*/
                              /*|---------+---------+---------|     |---------+---------+---------|*/

/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
    KC_TRNS,   K_XXX,   KC_BTN2,  KC_BTN3,  KC_BTN1,   K_XXX,         K_XXX,  SGUI(KC_L),SGUI(KC_U),SGUI(KC_Y), KC_MPRV, KC_MNXT, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
KC_TRNS,  MEH(KC_SPC), MEH(KC_LEFT), MEH(KC_UP), MEH(KC_RGHT), K_XXX, K_XXX, SGUI(KC_N), SGUI(KC_E), SGUI(KC_I),KC_VOLD, KC_VOLU, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
    KC_TRNS,   K_XXX,    K_XXX,    K_XXX,    K_XXX,   K_XXX,     KC_MSTP,  SGUI(KC_H), SGUI(KC_COMM), SGUI(KC_DOT), KC_MPLY, KC_MUTE,
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
                                   K_XXX,    K_XXX,   K_XXX,      SGUI(KC_ENT), SGUI(KC_SPC), SGUI(KC_DEL)
                              /*|---------+---------+---------|     |---------+---------+---------|*/
  ),

  [_ARROW] =  LAYOUT_wrapper(

/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
     K_XXX,    K_XXX,   KC_BTN2,  KC_BTN3,  KC_BTN1,   K_XXX,         KC_INS,   KC_HOME,   KC_UP,    KC_END,  KC_PGUP,   K_XXX, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
     BACK,   KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,     FWD,       LCA(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, LCA(KC_RGHT),  K_XXX, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
     K_XXX,    K_XXX,    K_XXX,    K_XXX,    K_XXX,    K_XXX,          K_XXX,    K_XXX,    K_XXX,    K_XXX,   KC_PGDN,  K_XXX, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
                                   K_XXX,    K_XXX,    K_XXX,          KC_ENT,   KC_SPC,   KC_DEL
                              /*|---------+---------+---------|     |---------+---------+---------|*/
  ),


  [_MOUSE] =  LAYOUT_wrapper(
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  K_XXX,     K_XXX,          K_XXX,   KC_WH_D,  KC_MS_U,  KC_WH_U,   K_XXX,    K_XXX, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
     K_XXX,   KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,   K_XXX,          K_XXX,   KC_MS_L,  KC_MS_D,  KC_MS_R,   K_XXX,    K_XXX, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,   K_XXX,    K_XXX,          K_XXX,   KC_WH_L,   K_XXX,   KC_WH_R,   K_XXX,    K_XXX,
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
                                   K_XXX,    K_XXX,    K_XXX,         KC_BTN3,  KC_BTN1,  KC_BTN2
                              /*|---------+---------+---------|     |---------+---------+---------|*/
  ), 

  [_SYMBOL] =  LAYOUT_wrapper(
          
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
              K_XXX,    KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR,         K_XXX,    K_XXX,    K_XXX,    K_XXX,    K_XXX,    K_XXX, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
              K_XXX,    KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PLUS,         K_XXX,   KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,   K_XXX, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
              K_XXX,    KC_TILD,  KC_EXLM,   KC_AT,   KC_HASH,  KC_PIPE,         K_XXX,    K_XXX,    K_XXX,    K_XXX,    K_XXX,    K_XXX, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
                                             KC_GT,   KC_RPRN,  KC_UNDS,         K_XXX,    K_XXX,    K_XXX
                              /*|---------+---------+---------|     |---------+---------+---------|*/
  ),


  [_NUMBER] =  LAYOUT_wrapper(
          
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
     K_XXX,   KC_LBRC,   KC_7,     KC_8,     KC_9,    KC_RBRC,      MEH(KC_LEFT), SGUI(KC_L), SGUI(KC_U), SGUI(KC_Y), K_XXX, K_XXX, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
     K_XXX,   KC_SCLN,   KC_4,     KC_5,     KC_6,    KC_EQL,       MEH(KC_UP), KC_LSFT,  KC_LCTL,  KC_LALT, KC_LGUI,  K_XXX,
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
     K_XXX,   KC_GRV,    KC_1,     KC_2,     KC_3,    KC_BSLS,   MEH(KC_RGHT), SGUI(KC_H), SGUI(KC_COMM), SGUI(KC_DOT), K_XXX, K_XXX, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
                                   KC_DOT,   KC_0,    KC_MINS,         K_XXX,    K_XXX,    K_XXX
                              /*|---------+---------+---------|     |---------+---------+---------|*/

  ),

  [_FUNCTION] =  LAYOUT_wrapper(
          
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
    K_XXX,    KC_F12,    KC_F7,    KC_F8,    KC_F9,    K_XXX,          K_XXX,    K_XXX,    K_XXX,    K_XXX,   K_XXX,     K_XXX,  
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
    K_XXX,    KC_F11,    KC_F4,    KC_F5,    KC_F6,    K_XXX,          K_XXX,    KC_LSFT,  KC_LCTL,  KC_LALT, KC_LGUI,   K_XXX, 
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
    K_XXX,    KC_F10,    KC_F1,    KC_F2,    KC_F3,    K_XXX,          K_XXX,    K_XXX,    K_XXX,    K_XXX,    K_XXX,    K_XXX,
/*|---------+---------+---------+---------+---------+---------|     |---------+---------+---------+---------+---------+---------|*/
                                  KC_ESC,   KC_BSPC,  KC_TAB,          K_XXX,    K_XXX,    K_XXX
                              /*|---------+---------+---------|     |---------+---------+---------|*/    
  ),

};