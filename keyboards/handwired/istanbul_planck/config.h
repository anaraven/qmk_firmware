// Copyright 2022 Andres Aravena (@Andres Aravena)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#ifndef CONFIG_H
#define CONFIG_H

// #include "config_common.h"

/* USB Device descriptor parameter */
// #define VENDOR_ID       0xFEED
// #define PRODUCT_ID      0x6060
// #define DEVICE_VER      0x0001
// #define MANUFACTURER    Andres Aravena
// #define PRODUCT         IstanbulPlanck
// #define DESCRIPTION     Handwired Planck Keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12


/* COL2ROW or ROW2COL */
// #define DIODE_DIRECTION COL2ROW

// #undef AUDIO_PIN
// #define AUDIO_PIN C6
// #define AUDIO_PIN_ALT B7
#ifdef AUDIO_ENABLE
// #define STARTUP_SONG SONG(STARTUP_SOUND)
// #define AUDIO_ENABLE_TONE_MULTIPLEXING
// #define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
#define AUDIO_CLICKY
#endif

/* number of backlight levels */
/*
#define BACKLIGHT_PIN B7
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 5
// #define BACKLIGHT_CAPS_LOCK
#define BACKLIGHT_BREATHING
#endif
*/

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
// #define PREVENT_STUCK_MODIFIERS

// The pin connected to the data pin of the LEDs (WS2812)
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_DEFAULT_SAT 100
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RGB_TEST
#define RGBLIGHT_DEFAULT_HUE 180
#define RGBLIGHT_DEFAULT_VAL 1
#endif //CONFIG_H
