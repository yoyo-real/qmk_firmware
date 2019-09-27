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
  RAISE = SAFE_RANGE,
  LOWER
};

enum layer_number {
    _BASE = 0,
    _RAISE,
    _LOWER,
    _NUMPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { 
    [_BASE] = LAYOUT( /* Base */ 
        KC_ESC,        KC_1,  KC_2,  KC_3,   KC_4,  KC_5  ,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,  KC_EQL,
        KC_TAB,        KC_Q,  KC_W,  KC_E,   KC_R,  KC_T  ,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC,  KC_RBRC,
        CTL_T(KC_TAB), KC_A,  KC_S,   KC_D,  KC_F,  KC_G  ,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,  KC_QUOT,  KC_NO,
        KC_LSFT,       KC_Z,  KC_X,  KC_C,   KC_V,  KC_B  ,  KC_N,  KC_M,  KC_COMM,KC_DOT,KC_SLSH, KC_BSLS,  KC_BSPC,
                                 KC_LWIN, KC_LALT, LOWER  ,  RAISE, KC_RSFT,  TT(_NUMPAD) 
        ),
    [_RAISE] = LAYOUT(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5    ,  KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        _______, _______, _______, _______, _______, _______  ,  _______, _______, _______, _______, _______, KC_PSCR, _______,
        _______, _______, _______, _______, KC_PGDN, _______  ,  KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______, KC_GRV, _______,
        _______, _______, _______, _______, _______, KC_PGUP  ,  _______, _______, _______, _______, _______, _______, KC_DEL,
                                   _______, _______, LALT(KC_GRV),  _______, _______, _______ 
        ),
    [_LOWER] = LAYOUT( /* With ctrl */
        _______, _______, _______, _______, _______, _______  ,  _______, _______, _______, _______, _______, _______, _______,
        LSFT(KC_TAB), _______, _______, _______, _______, _______  ,  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______  ,  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______  ,  _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______  ,  _______, _______, _______ 
        ),
    [_NUMPAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______  ,  KC_TAB , KC_PSLS, KC_PAST, KC_BSPC, KC_DEL, _______, _______,
        _______, _______, _______, _______, _______, _______  ,  KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______, _______, _______,
        _______, _______, _______, _______, _______, _______  ,  KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______, KC_UP, _______,
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

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        add_mods(MOD_BIT(KC_LCTL));
        break;
    default:
        del_mods(MOD_BIT(KC_LCTL));
        break;
    }
  return state;
}


static bool raise_pressed = false;
static bool lower_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
        if (raise_pressed) {
          register_code(KC_ENT); 
          unregister_code(KC_ENT);
        }
        raise_pressed = false;
      }
      return false; 
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
        if (lower_pressed) {
          register_code(KC_SPC); 
          unregister_code(KC_SPC);
        }
        lower_pressed = false;
      }
      return false; 
    default:
      if (record->event.pressed) {
        raise_pressed = false;
        lower_pressed = false;
      }
  }
  return true;
}
