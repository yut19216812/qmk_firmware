/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

#define LT3_SCLN LT(_L3, KC_SCLN)
#define SFT_SPC SFT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define SFT_TAB SFT_T(KC_TAB)
#define CTL_TAB CTL_T(KC_TAB)
#define CTL_Z CTL_T(KC_Z)
#define CTL_SLSH CLL_T(KC_SLSH)
// #define LT_SPC LT(_L1, KC_SPC)
// #define LT_ENT LT(_T2, KC_ENT)
#define LT1_BSPC LT(_L1, KC_BSPC)

enum layer_names {
    _QW,
    _L1,
    _L2,
    _L3,
    _L4,
};

enum original_keycodes {
  KC_ESC_EN = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QW] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                                       KC_H, KC_J, KC_K, KC_L, LT3_SCLN, KC_RCTL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC_EN,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, MO(_L1), SFT_SPC,      SFT_ENT,  LT1_BSPC, KC_RALT
        //`--------------------------'  `--------------------------'
        ),

    [_L1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                           KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LGUI, MO(_L3), SFT_SPC,      SFT_ENT,  MO(_L3), KC_RALT
        //`--------------------------'  `--------------------------'
        ),

    [_L2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TRNS, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TRNS, _______, _______, _______, _______, _______,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TRNS, _______, _______, _______, _______, _______,                          _______, _______, _______, _______,  _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, MO(_L3), SFT_SPC,      SFT_ENT,  MO(_L3), KC_RALT
        //`--------------------------'  `-------------------------'
        ),


    [_L3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TRNS, _______, _______, _______, KC_LNG2, _______,                          _______, KC_LNG1, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TRNS, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, MO(_L4)
        //`--------------------------'  `--------------------------'
        ),

    [_L4] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, KC_SPC, _______,        _______, KC_ENT, KC_RALT
        //`--------------------------'  `--------------------------'
        )};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ESC_EN:
      if (record->event.pressed) {
        register_code(KC_ESC);
        register_code(KC_LNG2);
      } else {
        unregister_code(KC_ESC);
        unregister_code(KC_LNG2);
      }
      return false;
      break;
  }
  return true;
}
