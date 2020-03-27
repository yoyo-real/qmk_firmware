/* Copyright 2019 yoyo
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
#include "yk_4.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

bool is_keyboard_left(void) {
    setPinInput(SPLIT_HAND_PIN);
    return readPin(SPLIT_HAND_PIN);
}

bool is_keyboard_master(void) {
#if defined(MASTER_RIGHT)
    return !is_keyboard_left();
#else
    return is_keyboard_left();
#endif
}

#define NOL NO_LED

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {
        // Key matrix to LED index
        {  0,   1,   2,   3, NOL,   4,   5},
        { 11,  10,   9, NOL,   8,   7,   6},
        { 12,  13,  14, NOL,  15,  16,  17},
        {NOL, NOL, NOL, NOL,  20, 19,  18},

        { 21,  22,  23,  24, NOL,  25,  26},
        { 32,  31,  30, NOL,  29,  28,  27},
        { 33,  34,  35, NOL,  36,  37,  38},
        { 41,  40,  39, NOL, NOL, NOL, NOL},
    }, {
        // LED index to Physical position
        {0, 0},{20, 0},{41, 0},{61, 0},{81, 0},{102, 0},{102, 21},{81, 21},{61, 21},{41, 21},{20, 21},{0, 21},{0, 43},
        {20, 43},{41, 43},{61, 43},{81, 43},{102, 43},{102, 64},{81, 64},{61, 64},

        {122, 0},{143, 0},{163, 0},{183, 0},
        {204, 0},{224, 0},{224, 21},{204, 21},{183, 21},{163, 21},{143, 21},{122, 21},{122, 43},{143, 43},{163, 43},
        {183, 43},{204, 43},{224, 43},{163, 64},{143, 64},{122, 64}
    }, {
        // LED index to flags
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4,

        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4
    }
};
#endif

void matrix_init_kb(void) {
#ifdef RGB_MATRIX_ENABLE
    if (!is_keyboard_left()) {
        g_led_config = (led_config_t){
            {
                // Key matrix to LED index
                { 21,  22,  23,  24, NOL,  25,  26},
                { 32,  31,  30, NOL,  29,  28,  27},
                { 33,  34,  35, NOL,  36,  37,  38},
                { 41,  40,  39, NOL, NOL, NOL, NOL},

                {  0,   1,   2,   3, NOL,   4,   5},
                { 11,  10,   9, NOL,   8,   7,   6},
                { 12,  13,  14, NOL,  15,  16,  17},
                {NOL, NOL, NOL, NOL,  20, 19,  18},
            }, {
                // LED index to Physical position
                {122, 0},{143, 0},{163, 0},{183, 0},
                {204, 0},{224, 0},{224, 21},{204, 21},{183, 21},{163, 21},{143, 21},{122, 21},{122, 43},{143, 43},{163, 43},
                {183, 43},{204, 43},{224, 43},{163, 64},{143, 64},{122, 64},

                {0, 0},{20, 0},{41, 0},{61, 0},{81, 0},{102, 0},{102, 21},{81, 21},{61, 21},{41, 21},{20, 21},{0, 21},{0, 43},
                {20, 43},{41, 43},{61, 43},{81, 43},{102, 43},{102, 64},{81, 64},{61, 64},
            }, {
                // LED index to flags
                4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                4, 4, 4, 4, 4, 4, 4, 4, 4,

                4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                4, 4, 4, 4, 4, 4, 4, 4, 4
            }
        };
    }
#endif

    matrix_init_user();
}

/*

void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up

  matrix_init_user();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  led_set_user(usb_led);
}

*/
