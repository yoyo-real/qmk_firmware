/*
Copyright 2021 yoyo

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

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 7

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { F0, F7, C7, C6 }
#define MATRIX_COL_PINS { F6, F4, F1, B2, B6, B3, D3 }

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
//#define SOFT_SERIAL_PIN D0  // or D1, D2, D3, E6;
#define USE_I2C

#define SPLIT_HAND_PIN E6
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_USB_DETECT
#define SPLIT_WATCHDOG_ENABLE

//#define LED_NUM_LOCK_PIN B0
//#define LED_CAPS_LOCK_PIN B1
//#define LED_SCROLL_LOCK_PIN B2
//#define LED_COMPOSE_PIN B3
//#define LED_KANA_PIN B4

//#define BACKLIGHT_PIN B7
//#define BACKLIGHT_LEVELS 3
//#define BACKLIGHT_BREATHING

#define RGB_DI_PIN F5

#define RGB_MATRIX_LED_COUNT 42
#define RGB_MATRIX_SPLIT { 21, 21 }
#define RGB_MATRIX_CENTER {112, 36}
#define RGB_DISABLE_WHEN_USB_SUSPENDED false // turn off effects when suspended

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 76
// #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

#define RGB_MATRIX_HUE_STEP 17 // number of steps to cycle through the hue by
#define RGB_MATRIX_SAT_STEP 17 // number of steps to increment the saturation by
#define RGB_MATRIX_VAL_STEP 9 // number of steps to increment the brightness by

// Normal animations
// #define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN      //上下方向のグラデーション
// #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT   //左右方向のグラデーション
// #define ENABLE_RGB_MATRIX_BREATHING             //単色明滅
// #define ENABLE_RGB_MATRIX_BAND_SAT              //白バックに単色帯が左から右
// #define ENABLE_RGB_MATRIX_BAND_VAL              //黒バックに単色帯が左から右
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT     //白バックに左右で単色渦巻き
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL     //黒バックに左右で単色渦巻き
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT       //白バックに中央で単色渦巻き
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL       //黒バックに中央で単色渦巻き
#define ENABLE_RGB_MATRIX_CYCLE_ALL             //色変化全キー同時
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT      //色変化左から右
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN         //色変化上から下
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON//色変化左から右、>型
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN          //色変化左右から中央
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL     //?
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL        //色変化左右で渦巻き
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL          //色変化中央で渦巻き
#define ENABLE_RGB_MATRIX_DUAL_BEACON           //色変化互い違いで放射状
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #define ENABLE_RGB_MATRIX_RAINDROPS
// #define ENABLE_RGB_MATRIX_JELLYBEA
// #define ENABLE_RGB_MATRIX_HUE_PENDULUM
// #define ENABLE_RGB_MATRIX_HUE_WAVE
// #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// #define ENABLE_RGB_MATRIX_PIXEL_FLOW
// #define ENABLE_RGB_MATRIX_PIXEL_RAIN
// Framebuffer animations
// #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// Reactive animations
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE     //背景黒押したキーだけ単色
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE            //背景単色押したキーカラフル
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       //押したキーの周り単色
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  //同上重複
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      //押したキーの十字方向単色
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS //同上重複
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      //押したキーの十次方向に走る単色
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS //同上重複
// #define ENABLE_RGB_MATRIX_SPLASH                  //カラフルスプラッシュ
#define ENABLE_RGB_MATRIX_MULTISPLASH               //同上重複
// #define ENABLE_RGB_MATRIX_SOLID_SPLASH            //単色スプラッシュ
// #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH         //同上重複

//#ifdef RGB_DI_PIN
//#    define RGBLED_NUM 16
//#    define RGBLIGHT_HUE_STEP 8
//#    define RGBLIGHT_SAT_STEP 8
//#    define RGBLIGHT_VAL_STEP 8
//#    define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
//#    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
//#    define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
//#    define RGBLIGHT_EFFECT_BREATHING
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#    define RGBLIGHT_EFFECT_SNAKE
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
//#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
/*== customize breathing effect ==*/
/*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//#    define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
/*==== use exp() and sin() ====*/
//#    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
//#    define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
//#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

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
#define NO_ACTION_ONESHOT

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0

#define PERMISSIVE_HOLD
