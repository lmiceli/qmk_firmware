/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

//#ifdef OLED_DRIVER_ENABLE
//  #define OLED_DISPLAY_128X64
//#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

// build
// ❯ cd qmk_firmware/keyboards/kyria/keymaps/lmiceli
// ❯ qmk json2c -o keymap.c k14.json
// ❯ qmk flash -kb kyria -km lmiceli
// no funciona el ultimo xq?

// esto x alguna razon funciono
// ❯ qmk flash k14.json -bl avrdude
// pero algo no va del todo bien






/* Select hand configuration */
//#define MASTER_LEFT
#define MASTER_RIGHT
//#define EE_HANDS

/
    jp/ Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// This makes tap and hold keys (like Mod Tap) work better for fast typists, or for high TAPPING_TERM settings
#define PERMISSIVE_HOLD

#define TAPPING_TERM 200

/* Set 0 if debouncing isn't needed */
//#undef  DEBOUNCE
//#define DEBOUNCE 8

//#define PREVENT_STUCK_MODIFIERS


// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK
