// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

#define KC_T1_SCLN LT(_T1, KC_SCLN)
#define ALT_BS ALT_T(KC_BSPC)
#define SFT_SPC SFT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define SFT_TAB SFT_T(KC_TAB)
#define CTL_TAB CTL_T(KC_TAB)
#define CTL_Z CTL_T(KC_Z)
#define CTL_SLSH CTL_T(KC_SLSH)
#define LT_SPC LT(_T1, KC_SPC)
#define LT_ENT LT(_T2, KC_ENT)

enum layer_names {
    _QW,
    _T1,
    _T2,
    _T3,
};

enum original_keycodes {
  QWERTY = SAFE_RANGE,
  KC_ESC_EN,
  YBI_WIN_FRONT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( 
    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_T1_SCLN, 
    KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_GRV,   KC_TILD,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_LCTL, KC_LCTL, KC_TAB,  KC_LGUI,  MO(_T1), SFT_SPC,  SFT_ENT,  MO(_T2), ALT_BS,  KC_QUOT, KC_ESC_EN, KC_LCTL),
   
  [_T1] = LAYOUT( 
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,
    _______, _______, _______, _______, _______,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_T3),  KC_TRNS, KC_TRNS,  MO(_T3), KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS),

  [_T2] = LAYOUT( 
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, 
    _______, KC_LCBR, KC_DQT,  KC_RCBR, _______,                     KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_LBRC, KC_QUOT, KC_RBRC, _______,  KC_TRNS, KC_TRNS,  KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_T3),  KC_TRNS, KC_TRNS,  MO(_T3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [_T3] = LAYOUT( 
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
    _______, _______, _______, KC_LNG2, YBI_WIN_FRONT,               _______, KC_LNG1, _______, _______,  _______,
    _______, _______, _______, _______, _______,  KC_F6,   KC_F7,    _______, _______, _______, _______,  _______,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, QK_BOOT, KC_TRNS,  KC_TRNS),

};


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
