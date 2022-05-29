/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2021 @dlford
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS // ./util/docker_build.sh crkbd:dlford:dfu-split-[left|right] (or avrdude-split[left|right])

#define TAPPING_TOGGLE 2 // number of taps to toggle TT
#define TAPPING_TERM_PER_KEY // milliseconds from tap to hold for mod tap per key
#define IGNORE_MOD_TAP_INTERRUPT // ignore hold mod if another tap occurs within tapping term
#define PERMISSIVE_HOLD_PER_KEY // activate mod top hold earlier if another key is pressed AND released per key
#define TAPPING_FORCE_HOLD_PER_KEY // disable double tap hold key repeat per key
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_WHEEL_DELAY

//#define MK_KINETIC_SPEED

//#define MOUSEKEY_DELAY              100
//#define MOUSEKEY_INTERVAL           35
//#define MOUSEKEY_MOVE_DELTA         5
//#define MOUSEKEY_INITIAL_SPEED      1
//#define MOUSEKEY_DECELERATED_SPEED  10
//#define MOUSEKEY_BASE_SPEED         1200
//#define MOUSEKEY_ACCELERATED_SPEED  4800


// Features I don't want, remove to save space
#define NO_ACTION_ONESHOT // Used by caps word
#define NO_ACTION_FUNCTION
#define NO_ACTION_MACRO
#define NO_USB_STARTUP_CHECK



// pruebas ya no se que quitar
//#define DISABLE_LEADER

//#ifndef NO_DEBUG
//#define NO_DEBUG
//#endif // !NO_DEBUG
//#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
//#define NO_PRINT
//#endif // !NO_PRINT

//COMMAND_ENABLE   = no // Commands for debug and configuration
//UNICODE_ENABLE   = no // Unicode
//MOUSEKEY_ENABLE  = no // Mouse keys(+4700)
