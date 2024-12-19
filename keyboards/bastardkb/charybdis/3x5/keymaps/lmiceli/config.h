/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

// the delay when reading the value of the pin (5 is default)
#define DEBOUNCE 7

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// did not see improvements (tested lightly)
// but seems I have V3's so I will leave it
#define SPLIT_USB_DETECT
//#define NO_USB_STARTUP_CHECK

#define SPLIT_USB_TIMEOUT 30000

// trying many ways to get the keyboard to wake after mac sleep
//#undef SPLIT_USB_DETECT
#define USB_SUSPEND_WAKEUP_DELAY 200

// mod tap
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD

// additional for home row mods
#define TAPPING_TERM 190

//#define QUICK_TAP_TERM 0

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

// UPDATE 16/12/2024 disabled auto mouse as it sucks or is hard to configure
//#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
//#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
//#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 4

// Flip horizontal direction for drag-scroll.
//#define CHARYBDIS_DRAGSCROLL_REVERSE_X
//#define CHARYBDIS_DRAGSCROLL_REVERSE_Y
#endif // POINTING_DEVICE_ENABLE

#define CHARYBDIS_MINIMUM_DEFAULT_DPI 1200
#define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 400
#define CHARYBDIS_MINIMUM_SNIPING_DPI 200
#define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100

// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#define MOUSEKEY_DELAY 100
// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 100
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100
/*
 *
  Drag-scroll

Use the DRAGSCROLL_MODE keycode to enable drag-scroll on hold. Use the DRAGSCROLL_TOGGLE keycode to enable/disable drag-scroll on key press.

Sniping

   Use the SNIPING_MODE keycode to enable sniping mode on hold. Use the SNIPING_MODE_TOGGLE (aliased as SNP_TOG) keycode to enable/disable sniping mode on key press.

 Change the value of CHARYBDIS_AUTO_SNIPING_ON_LAYER to automatically enable sniping mode on layer change. By default, sniping mode is enabled on the pointer layer:

#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER
  Auto pointer layer

  The pointer layer can be automatically enabled when moving the trackball. To enable or disable this behavior, add or remove the following define:

#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
  By default, the layer is turned off 1 second after the last registered trackball movement:

#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
  The trigger sensibility can also be tuned. The lower the value, the more sensible the trigger:

#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8

    *
 *
 * */
/* RGB Matrix. */

//#ifdef RGB_MATRIX_ENABLE
// Disable control of RGB matrix by keycodes (must use firmware implementation
// to control the feature).
/* #    define RGB_MATRIX_DISABLE_KEYCODES */

// Limit maximum brightness to keep power consumption reasonable, and avoid
// disconnects.
//#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
//#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 64

// Rainbow swirl as startup mode.
/* #    define ENABLE_RGB_MATRIX_TYPING_HEATMAP */

// Slow swirl at startup.
//#    define RGB_MATRIX_STARTUP_SPD 32

// Startup values.
//#    define RGB_MATRIX_STARTUP_HUE 0
//#    define RGB_MATRIX_STARTUP_SAT 255
//#    define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
//#    define RGB_MATRIX_STARTUP_HSV RGB_MATRIX_STARTUP_HUE, RGB_MATRIX_STARTUP_SAT, RGB_MATRIX_STARTUP_VAL
//#endif  // RGB_MATRIX_ENABLE
