// Copyright 2022 Andres Aravena (@Andres Aravena)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

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

/* key matrix pins */
#define MATRIX_ROW_PINS { D1, D0, F5, F4 }
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5, F6, F7, B1, B3, B2, B6 }
// #define UNUSED_PINS { D2, D3 }

#undef AUDIO_PIN
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

#define RAPC_KEYS KC_LEFT_ALT, KC_RIGHT_SHIFT, KC_0

#endif //CONFIG_H
