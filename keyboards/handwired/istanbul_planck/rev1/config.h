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
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
// #define VENDOR_ID       0xFEED
// #define PRODUCT_ID      0x6060
// #define DEVICE_VER      0x0001

/* key matrix pins */
#define MATRIX_ROW_PINS { B3, B7, F5, F4 }
#define MATRIX_COL_PINS { D0, D1, D2, D3, C6, C7, F6, F7, B6, B5, B4, D7 }
// #define UNUSED_PINS { B0, B1, B2, F0, F1, E6, D6 }

/* COL2ROW or ROW2COL */
// #define DIODE_DIRECTION COL2ROW

#undef AUDIO_PIN
// #define AUDIO_PIN D4
// #define AUDIO_PIN_ALT B7
#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(STARTUP_SOUND)
#define AUDIO_ENABLE_TONE_MULTIPLEXING
#define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
#define AUDIO_CLICKY
#endif

/* number of backlight levels */
#undef BACKLIGHT_PIN
// #define BACKLIGHT_PIN D6
#ifdef BACKLIGHT_PIN
// #define BACKLIGHT_LEVELS 5
// #define BACKLIGHT_CAPS_LOCK
// #define BACKLIGHT_BREATHING
#endif

// The pin connected to the data pin of the LEDs (WS2812)
#define WS2812_DI_PIN D4
#define WS2812_LED_COUNT 8
#define RGBLIGHT_LED_COUNT 8
#endif //CONFIG_H
