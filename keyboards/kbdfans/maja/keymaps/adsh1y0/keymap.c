#include QMK_KEYBOARD_H

#define _MAIN 0
#define _RGB 1
#define _LAYER2 2
#define _LAYER3 3

#define KC_S_SPC LSFT_T(KC_SPC)

enum custom_keycodes {
  KC_ESC_EN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_MAIN] = LAYOUT( /* Base */
			  KC_GESC,  KC_1,     KC_2,     KC_3,   KC_4,  KC_5,  KC_6,      KC_7,        KC_8,  KC_9,    KC_0,     KC_MINS,   KC_EQL,    KC_BSPC,               MO(_RGB),
		    KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,  KC_T,             KC_Y,        KC_U,  KC_I,    KC_O,     KC_P,      KC_LBRC,   KC_RBRC,  KC_BSLASH,   KC_PGUP,
			  KC_LCTL,  KC_A,     KC_S,     KC_D,   KC_F,  KC_G,             KC_H,        KC_J,  KC_K,    KC_L,     LT(_LAYER2,  KC_SCLN),  KC_QUOT,  KC_ENT,      KC_PGDN,
		    KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,  KC_B,             KC_LANG1,    KC_N,  KC_M,    KC_COMM,  KC_DOT,    KC_SLSH,   KC_ESC_EN,             KC_UP,
		    KC_LCTL,            KC_LGUI,  MO(_LAYER2),  KC_S_SPC,          MO(_LAYER3), ALT_T(KC_BSPC),                           KC_LEFT,  KC_DOWN,  KC_RIGHT),
		[_RGB] = LAYOUT( /* RGB */
			  KC_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  KC_F6,     KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   RESET,              KC_TRNS,
		    KC_TRNS,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,           RGB_SAD,  RGB_VAI,  RGB_VAD, KC_TRNS,  KC_PSCR,  KC_SLCK,  KC_PAUS,  RESET,    KC_PGUP,
			  KC_LCTL,  RGB_SPI,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  EEP_RST,            KC_PGDN,
		    KC_LSFT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLU,  KC_MUTE,
		    KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,                     KC_TRNS,  KC_TRNS,                               KC_MPRV,  KC_VOLD,  KC_MNXT),
		[_LAYER2] = LAYOUT( /* MOVE */
			  KC_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  KC_F6,     KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_TRNS,            KC_TRNS,
		    KC_TRNS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,              KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
			  KC_LCTL,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,              KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT, KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
		    KC_LSFT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
		    KC_TRNS,            KC_TRNS,  KC_LANG2,  KC_TRNS,                    KC_LANG1,  KC_TRNS,                               KC_TRNS,  KC_TRNS,  KC_TRNS),
		[_LAYER3] = LAYOUT( /* SYMBOL */
			  KC_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  KC_F6,     KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR, KC_LPRN,  KC_RPRN,  KC_MINS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,           KC_MINS,  KC_EQL,   KC_LCBR, KC_RCBR,  KC_PIPE,  KC_GRV,   KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,           KC_TRNS,  KC_UNDS,  KC_PLUS, KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_TILD,  KC_TRNS,
		    KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,                     KC_TRNS,  KC_TRNS,                               KC_TRNS,  KC_TRNS,  KC_TRNS),
 };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ESC_EN:
      if (record->event.pressed) {
        register_code(KC_ESC);
        register_code(KC_LANG2);
      } else {
        unregister_code(KC_ESC);
        unregister_code(KC_LANG2);
      }
      break;
  }
  return true;
}

