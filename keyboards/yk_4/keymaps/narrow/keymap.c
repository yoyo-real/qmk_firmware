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
#include QMK_KEYBOARD_H
 
enum custom_keycodes {
  SFT_IME = SAFE_RANGE,
};

enum layer_number {
    _BASE = 0,
    _RAISE,
    _NUMPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { 
    [_BASE] = LAYOUT( /* Base */ 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  ,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_ESC, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T ,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC,  KC_RBRC,
        CTL_T(KC_TAB), KC_A,  KC_S,  KC_D, KC_F,  KC_G ,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,  KC_QUOT,  KC_NO,
        SFT_T(KC_BSPC), KC_Z,  KC_X,  KC_C,  KC_V,  KC_B ,  KC_N,  KC_M,  KC_COMM,KC_DOT,KC_SLSH, KC_BSLS,  KC_BSPC,
                     KC_LWIN, KC_LALT, CTL_T(KC_SPC)  ,  LT(_RAISE, KC_ENT),  KC_RSFT,  TT(_NUMPAD) 
        ),
    [_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______  ,  _______, _______, _______, _______, _______, _______, _______,
        KC_ESC, KC_1,  KC_2,  KC_3,  KC_4,  KC_5 ,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,  KC_EQL,
        _______, _______, _______, _______, KC_PGDN, KC_PGUP  ,  KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______, KC_GRV, _______,
        KC_DEL, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5    ,  KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
                                   KC_PSCR, _______, SFT_IME,  _______, _______, _______ 
        ),
    [_NUMPAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______  ,  KC_TAB , KC_PSLS, KC_PAST, KC_BSPC, KC_DEL, _______, _______,
        _______, _______, _______, _______, _______, _______  ,  KC_P7  , KC_P8  , KC_P9  , KC_PMNS, KC_PSLS, KC_BSPC, _______,
        _______, _______, _______, _______, _______, _______  ,  KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PAST, KC_UP, _______,
        _______, _______, _______, _______, _______, _______  ,  KC_P1  , KC_P2  , KC_P3  , KC_PENT, KC_LEFT, KC_DOWN, KC_RIGHT,
                                   _______, _______, _______  ,  KC_P0  , KC_PDOT, _______  
        ),
};

bool is_keyboard_master(void) {
    setPinInput(SPLIT_HAND_PIN);
#if defined(MASTER_RIGHT)
    return !readPin(SPLIT_HAND_PIN);
#else
    return readPin(SPLIT_HAND_PIN);
#endif
}
 
static bool sft_ime_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SFT_IME:
      if (record->event.pressed) {
        sft_ime_pressed = true; 
        register_code(KC_LSFT);
      } else {
        unregister_code(KC_LSFT);
        if (sft_ime_pressed) { // (4)
            register_code(KC_LALT); 
            register_code(KC_GRV); 
            unregister_code(KC_GRV);
            unregister_code(KC_LALT);
        }
        sft_ime_pressed = false;
      }
      return false;
    default:
      if (record->event.pressed) {
        sft_ime_pressed = false;
      }
  }
  return true;
}
