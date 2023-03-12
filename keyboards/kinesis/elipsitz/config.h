// Copyright 2023 Eli Lipsitz (@Eli Lipsitz)
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

// Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U

// RGB LED config
#define RGB_DI_PIN GP9
#define RGBLED_NUM 4
#define RGBLIGHT_LIMIT_VAL 64
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
// (bug? rgblight_task won't be called, so layers won't work, unless this is set)
#define RGBLIGHT_USE_TIMER