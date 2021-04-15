/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
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

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _BASE 0
#define _MOVE 1
#define _SYMBOL 2
#define _ADJUST 3

#define KC_MV_SCLN LT(_MOVE,  KC_SCLN)

enum user_macro {
  UM_SPC,
  UM_ENT,
};

enum custom_keycodes {
  KC_ESC_EN = SAFE_RANGE,
};

#define M_SPC  MACROTAP(UM_SPC)
#define M_ENT  MACROTAP(UM_ENT)
#define ALT_BS ALT_T(KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT( \
  //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    KC_MV_SCLN, KC_QUOT,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_ESC,
  //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                        KC_LGUI, M_SPC, KC_LSFT, KC_LANG2,        KC_LANG1, KC_RSFT, M_ENT,  ALT_BS
  //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
  ),
  [_MOVE] = LAYOUT( \
    //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
      KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
      KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
    //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
  //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
  //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
  ),

  [_SYMBOL] = LAYOUT( \
  //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
  //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
  //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
  ),

  [_ADJUST] = LAYOUT( \
  //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LANG2, KC_TRNS, KC_TRNS, KC_LANG1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
  //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _MOVE, _SYMBOL, _ADJUST);
}

static bool ctrl_pressed = false;
static bool exceptionaly_ctrl_layer_pressed = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LCTL:
      if (record->event.pressed) {
        ctrl_pressed = true;
      } else {
        ctrl_pressed = false;
      }
      break;
    case KC_ESC_EN:
      if (record->event.pressed) {
        register_code(KC_ESC);
        register_code(KC_LANG2);
      } else {
        unregister_code(KC_ESC);
        unregister_code(KC_LANG2);
      }
      return false;
    default:
      if (ctrl_pressed || exceptionaly_ctrl_layer_pressed) {
        switch (keycode) {
          case KC_H:
            if (record->event.pressed) {
              unregister_code(KC_LCTL);
              register_code(KC_BSPC);
              exceptionaly_ctrl_layer_pressed = true;
            } else {
              if (ctrl_pressed) {
                register_code(KC_LCTL);
              } else {
                unregister_code(KC_LCTL);
              }
              unregister_code(KC_BSPC);
              exceptionaly_ctrl_layer_pressed = false;
            }
            return false;
            break;
        }
      }
  }
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    case UM_SPC: {
      return MACRO_TAP_HOLD_LAYER( record, MACRO(TYPE(KC_SPC), END), _MOVE );
    } break;

    case UM_ENT: {
      return MACRO_TAP_HOLD_LAYER( record, MACRO(TYPE(KC_ENT), END), _SYMBOL );
    } break;
  }
  return MACRO_NONE;
};
