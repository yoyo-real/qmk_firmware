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

#define CW(kc) LCTL(LWIN(kc))

enum custom_keycodes {
  SFT_IME = SAFE_RANGE,
  CL_TAB,
  CL_STAB,
  AL_TAB,
  AL_STAB,
};

enum layer_number {
    _BASE = 0,
    _RAISE,
    _LOWER,
    _UTIL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT( /* Base */
        XXXXXXX       , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  ,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_ESC        , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T     ,  KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS, XXXXXXX,
        CTL_T(KC_TAB) , KC_A   , KC_S   , KC_D   , KC_F   , KC_G     ,  KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, XXXXXXX,
        SFT_T(KC_BSPC), KC_Z   , KC_X   , KC_C   , KC_V   , KC_B     ,  KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_BSLS, XXXXXXX,
                                KC_LALT, KC_LCTL, LT(_LOWER,KC_SPC)  ,  LT(_RAISE, KC_ENT), SFT_IME, KC_RALT
        ),
    [_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______  ,  _______, _______, _______, _______, _______, _______, _______,
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5     ,  KC_6   ,  KC_7  , KC_8   , KC_9   , KC_0,    KC_PLUS, _______,
        KC_TILD, KC_UNDS, KC_LABK, KC_LBRC, KC_LPRN, KC_LCBR  ,  KC_RCBR, KC_RPRN, KC_RBRC, KC_RABK, KC_COLN, KC_DQT , _______,
        KC_DEL , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC  ,  KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL , KC_QUES, KC_PIPE, _______,
                                   _______, _______, _______  ,  _______, _______, _______
        ),
    [_LOWER] = LAYOUT(
        _______, _______, _______, _______, _______, _______  ,  _______, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, AL_STAB, AL_TAB , KC_PGUP  ,  _______, _______, _______, _______,  KC_PSCR, _______, _______,
        _______, _______, _______, CL_STAB, CL_TAB , KC_PGDN  ,  KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______, _______, _______,
        KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5    ,  KC_F6  , KC_F7  , KC_F8  , KC_F9  ,  KC_F10 , KC_F11 , _______,
                                   _______, _______, _______  ,  _______, _______, _______
        ),
    [_UTIL] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  ,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  ,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        LWIN(KC_TAB) , XXXXXXX, XXXXXXX, CW(KC_D), XXXXXXX, XXXXXXX  ,  CW(KC_LEFT), XXXXXXX, XXXXXXX, CW(KC_RIGHT), XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CW(KC_F4), XXXXXXX  ,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX  ,  XXXXXXX, XXXXXXX, XXXXXXX
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
static bool lock_ctrl = false;
static bool lock_alt = false;


uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _RAISE, _LOWER, _UTIL);
  return state;
}

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
    case CL_TAB:
      if (record->event.pressed) {
        if (lock_alt) {
          lock_alt = false;
            unregister_code(KC_LALT);
        }
        if (!lock_ctrl) {
          lock_ctrl = true;
          register_code(KC_LCTL);
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;
    case CL_STAB:
      if (record->event.pressed) {
        if (lock_alt) {
          lock_alt = false;
            unregister_code(KC_LALT);
        }
        if (!lock_ctrl) {
          lock_ctrl = true;
          register_code(KC_LCTL);
        }
        register_code(KC_LSFT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_LSFT);
        unregister_code(KC_TAB);
      }
      return false;

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
    case AL_TAB:
      if (record->event.pressed) {
        if (lock_ctrl) {
          lock_ctrl = false;
          unregister_code(KC_LCTL);
        }
        if (!lock_alt) {
          lock_alt = true;
            register_code(KC_LALT);
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;
    case AL_STAB:
      if (record->event.pressed) {
        if (lock_ctrl) {
          lock_ctrl = false;
          unregister_code(KC_LCTL);
        }
        if (!lock_alt) {
          lock_alt = true;
            register_code(KC_LALT);
        }
        register_code(KC_LSFT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_LSFT);
        unregister_code(KC_TAB);
      }
      return false;
    default:
      if (record->event.pressed) {
        sft_ime_pressed = false;
      }
      if (lock_ctrl) {
        lock_ctrl = false;
          unregister_code(KC_LCTL);
      }
      if (lock_alt) {
        lock_alt = false;
          unregister_code(KC_LALT);
      }
  }
  return true;
}
