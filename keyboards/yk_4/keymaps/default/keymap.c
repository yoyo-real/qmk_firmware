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
#include "keymap_jp.h"

#define CW(kc) LCTL(LWIN(kc))

enum custom_keycodes {
  CL_TAB = SAFE_RANGE,
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
        KC_ESC        , JP_Q   , JP_W   , JP_E   , JP_R   , JP_T     ,  JP_Y   , JP_U   , JP_I   , JP_O   , JP_P   , JP_MINS,
        CTL_T(KC_TAB) , JP_A   , JP_S   , JP_D   , JP_F   , JP_G     ,  JP_H   , JP_J   , JP_K   , JP_L   , JP_SCLN, JP_QUOT,
        SFT_T(KC_BSPC), JP_Z   , JP_X   , JP_C   , JP_V   , JP_B     ,  JP_N   , JP_M   , JP_COMM, JP_DOT , JP_SLSH, JP_BSLS,
                                KC_LALT, KC_LCTL, LT(_LOWER,KC_SPC)  ,  LT(_RAISE, KC_ENT), JP_ZKHK, KC_RALT
        ),
    [_RAISE] = LAYOUT(
        JP_GRV , JP_1   , JP_2   , JP_3   , JP_4   , JP_5     ,  JP_6   ,  JP_7  , JP_8   , JP_9   , JP_0,    JP_PLUS,
        JP_TILD, JP_UNDS, JP_LABK, JP_LBRC, JP_LPRN, JP_LCBR  ,  JP_RCBR, JP_RPRN, JP_RBRC, JP_RABK, JP_COLN, JP_DQT ,
        KC_DEL , JP_EXLM, JP_AT  , JP_HASH, JP_DLR , JP_PERC  ,  JP_CIRC, JP_AMPR, JP_ASTR, JP_EQL , JP_QUES, JP_PIPE,
                                   _______, _______, _______  ,  _______, _______, _______
        ),
    [_LOWER] = LAYOUT(
        _______, _______, _______, AL_STAB, AL_TAB , KC_PGUP  ,  _______, _______, _______, _______,  KC_PSCR, _______,
        _______, _______, _______, CL_STAB, CL_TAB , KC_PGDN  ,  KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______, _______,
        KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5    ,  KC_F6  , KC_F7  , KC_F8  , KC_F9  ,  KC_F10 , KC_F11 ,
                                   _______, _______, _______  ,  _______, _______, _______
        ),
    [_UTIL] = LAYOUT(
        XXXXXXX,    LWIN(JP_1), LWIN(JP_2), LWIN(JP_3), LWIN(JP_4), LWIN(JP_5)  ,   LWIN(JP_6),  LWIN(JP_7), LWIN(JP_8),   LWIN(JP_9), LWIN(JP_0), XXXXXXX,
        LWIN(KC_TAB) , XXXXXXX,    XXXXXXX,   CW(JP_D),    XXXXXXX, XXXXXXX     ,   CW(KC_LEFT),    XXXXXXX,    XXXXXXX, CW(KC_RIGHT),    XXXXXXX, XXXXXXX,
        KC_LSFT,       XXXXXXX,    XXXXXXX,    XXXXXXX, LWIN(JP_V), XXXXXXX     ,   RGB_TOG,        RGB_MOD,    RGB_HUI,      RGB_SAI,    RGB_VAI, XXXXXXX,
                                               XXXXXXX,    XXXXXXX, _______     ,   _______,        XXXXXXX,    XXXXXXX
        ),
};

static bool lock_ctrl = false;
static bool lock_alt = false;


uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _RAISE, _LOWER, _UTIL);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
