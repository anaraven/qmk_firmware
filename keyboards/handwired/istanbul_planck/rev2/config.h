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
#define VENDOR_ID       0x1b4f
#define PRODUCT_ID      0x9206
#define DEVICE_VER      0x0002

/* key matrix pins */
#define MATRIX_ROW_PINS { B2, B6, B5, B4 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, D1, D0, D4, C6, D7, E6 }
#define UNUSED_PINS { D2, D3 }

/* COL2ROW or ROW2COL */
// #define DIODE_DIRECTION COL2ROW

#undef AUDIO_PIN
// #define AUDIO_PIN C6
// #define AUDIO_PIN_ALT B7

/* number of backlight levels */
// #define BACKLIGHT_PIN B7


#endif //CONFIG_H
