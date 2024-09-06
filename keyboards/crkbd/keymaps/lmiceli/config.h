#pragma once

#define COMBO_COUNT 2

#define USE_MATRIX_I2
// #define USE_SERIAL_PD2

/* Select hand configuration */
#define MASTER_LEFT
//#define MASTER_RIGHT
//#define EE_HANDS

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// This makes tap and hold keys (like Mod Tap) work better for fast typists, or for high TAPPING_TERM settings  
// #define PERMISSIVE_HOLD

#define TAPPING_TERM 170
// #define BILATERAL_COMBINATIONS

