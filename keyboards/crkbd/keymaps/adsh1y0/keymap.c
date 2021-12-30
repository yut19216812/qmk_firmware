/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <stdio.h>

// #define _QWERTY 0
// #define _L1 1
// #define _L2 2
// #define _L3 3

enum layers {
    _QW,
    _L1,
    _L2,
    _L3,
    _L4,
};

enum custom_keycodes {
  KC_ESC_EN = SAFE_RANGE,
  YBI_WIN_FRONT,
};

// #define KC_S_SPC LSFT_T(KC_SPC)
// #define KC_A_BS ALT_T(KC_BSPC)
// #define KC_R_SCLN LT(_L1, KC_SCLN)

#define KC_L1_SCLN LT(_L1, KC_SCLN)
#define ALT_BS ALT_T(KC_BSPC)
#define SFT_SPC SFT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define SFT_TAB SFT_T(KC_TAB)
#define CTL_TAB CTL_T(KC_TAB)
#define CTL_Z CTL_T(KC_Z)
#define CTL_SLSH CTL_T(KC_SLSH)
#define LT_SPC LT(_L1, KC_SPC)
#define LT_ENT LT(_L2, KC_ENT)
 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,       KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,   KC_L1_SCLN, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-------|
      KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,    KC_ESC_EN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI,  MO(_L1), SFT_SPC,     SFT_ENT, MO(_L2), ALT_BS
                                      //`--------------------------'  `--------------------------'

  ),

  [_L1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI, MO(_L3), SFT_SPC,     SFT_ENT, MO(_L3), ALT_BS
                                      //`--------------------------'  `--------------------------'
  ),

  [_L2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, _______, KC_LCBR, KC_DQT,  KC_RCBR, _______,                      KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, _______, KC_LBRC, KC_QUOT, KC_RBRC, _______,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(_L3), SFT_SPC,    SFT_ENT, MO(_L3), ALT_BS
                                      //`--------------------------'  `--------------------------'
  ),

  [_L3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, _______, _______, _______, KC_LNG2, YBI_WIN_FRONT,                _______, KC_LNG1, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, MO(_L4)
                                      //`--------------------------'  `--------------------------'
  ),

  [_L4] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                        _______, _______, _______, _______, _______, _______,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,                        _______, _______, _______, _______, _______, _______,
                                        _______, KC_LGUI, KC_SPC,       KC_ENT,  KC_RALT, _______
  ) 
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

// #define L_BASE 0
// #define L_LOWER 2
// #define L_RAISE 4
// #define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _QW:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case _L1:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _L2:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _L3:
        // case _L3|_L1:
        // case _L3|_L2:
        // case _L3|_L1|_L2:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  switch (keycode) {
    // case QWERTY:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_QWERTY);
    //   }
    //   return false;
    //   break;
    case _L1:
      if (record->event.pressed) {
        layer_on(_L1);
        update_tri_layer(_L1, _L2, _L3);
      } else {
        layer_off(_L1);
        update_tri_layer(_L1, _L2, _L3);
      }
      return false;
      break;
    case _L2:
      if (record->event.pressed) {
        layer_on(_L2);
        update_tri_layer(_L1, _L2, _L3);
      } else {
        layer_off(_L2);
        update_tri_layer(_L1, _L2, _L3);
      }
      return false;
      break;
    case _L3:
      if (record->event.pressed) {
        layer_on(_L3);
      } else {
        layer_off(_L3);
      }
      return false;
      break;
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
    case YBI_WIN_FRONT:
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_LALT);
        register_code(KC_SPACE);
      } else {
        unregister_code(KC_LSFT);
        unregister_code(KC_LALT);
        unregister_code(KC_SPACE);
      }
      return false;
      break;
  }
  return true;
}

#endif // OLED_ENABLE
