#include QMK_KEYBOARD_H
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  KC_ESC_EN
};

#define KC_MV_SCLN LT(_LOWER, KC_SCLN)
#define ALT_BSPC ALT_T(KC_BSPC)
#define SPC_SFT SFT_T(KC_SPC)

#define LT_SPC LT(_LOWER, KC_SPC)
#define LT_ENT LT(_RAISE, KC_ENT)

// Underglow setup
#define RGBLIGHT_SLEEP
#define RGBLIGHT_ANIMATIONS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .----------------------------------------.     .-----------------------------------------.
 * | Esc |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |  -   |
 * |-----+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Tab |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |Enter |
 * |-----+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Caps|   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |-----+------+------+------+------+------|     |------+------+------+------+------+------|
 * |Lshft|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |  /   | Esc  |
 * |-----+------+------+------+------+------|     |------+------+------+------+------+------|
 * |     | LCtrl| LAlt | LGui |  Bspc |     |   Spc/Lower | RGui | RAlt | RCtrl| Del  |
 * `----------------------------------------'     '-----------------------------------------'
 */
[_QWERTY] = LAYOUT(
  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,          KC_6,    KC_7,    KC_8,     KC_9,    KC_0,       KC_MINS,
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,          KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,       KC_ENT,
  KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,          KC_H,    KC_J,    KC_K,     KC_L,    KC_MV_SCLN, KC_QUOT,
  KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,          KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,    KC_ESC_EN,
  KC_LANG2,  KC_LCTL, KC_LALT, KC_LGUI, LT_SPC, LT_SPC,        LT_ENT, LT_ENT,  ALT_BSPC, KC_RALT,  KC_RCTL, KC_LANG1
  ),

/* Lower
 * ,-----------------s-----------------------.     ,----------------------------------------.
 * |      |      |      |      |      |      |     |     |      |      |      |      |      |
 * |------+------+------+------+------+------|     |-----+------+------+------+------+------|
 * |      |      |      |      |      |      |     |     |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|     |-----+------+------+------+------+------|
 * |      |      |      |      |      |      |     |     | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|     |-----+------+------+------+------+------|
 * |      |      |      |      |      |      |     |     |      |      |      |      |      |
 * |------+------+------+------+------+------|     |-----+------+------+------+------+------|
 * |      |      |      | Gui  |             |     |            |      |      |      |      |
 * `-----------------------------------------'     `----------------------------------------'
 */
[_LOWER] = LAYOUT(
  KC_TRNS, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  KC_TRNS, KC_6,     KC_7,     KC_8,     KC_9,     KC_0,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  KC_TRNS, KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_TRNS, XXXXXXX,
  KC_TRNS, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  KC_TRNS, XXXXXXX,  XXXXXXX,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX,  XXXXXXX, XXXXXXX
),

/* Raise
 * ,-----------------------------------------.     ,----------------------------------------.
 * |      |      |      |      |      |      |     |     |      |      |      |      |      |
 * |------+------+------+------+------+------|     |-----+------+------+------+------+------|
 * |      |      |      |      |      |      |     |     |      |      |      |      |      |
 * |------+------+------+------+------+------|     |-----+------+------+------+------+------|
 * |      |      |      |      |      |      |     |     |      |      |      |      |      |
 * |------+------+------+------+------+------|     |-----+------+------+------+------+------|
 * |      |      |      |      |      |      |     |     |      |      |      |      |      |
 * |------+------+------+------+------+------|     |-----+------+------+------+------+------|
 * |      |      |      |      |             |     |            |      |      |      |      |
 * `-----------------------------------------'     `----------------------------------------'
 */
[_RAISE] = LAYOUT(
  KC_TRNS, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  KC_TRNS, KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_MINS,
  KC_TRNS, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR,  KC_PIPE, KC_GRV,
  KC_TRNS, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC,  KC_BSLS, KC_TILD,
  KC_TRNS, XXXXXXX,  XXXXXXX,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX,  XXXXXXX, XXXXXXX
),

/* ADJUST
 * ,-----------------------------------------.     ,----------------------------------------.
 * |      |      |      |      |      |      |     |     |      |      |      |      |      |
 * |------+------+------+------+------+------|     |-----+------+------+------+------+------|
 * |      |      |      |      |      |      |     |     |      |      |      |      |      |
 * |------+------+------+------+------+------|     |-----+------+------+------+------+------|
 * |      |      |      |      |      |      |     |     |      |      |      |      |      |
 * |------+------+------+------+------+------|     |-----+------+------+------+------+------|
 * |      |      |      |      |      |      |     |     |      |      |      |      |      |
 * |------+------+------+------+------+------|     |-----+------+------+------+------+------|
 * |      |      |      |      |             |     |            |      |      |      |      |
 * `-----------------------------------------'     `----------------------------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LANG2, XXXXXXX,     XXXXXXX, KC_LANG1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX,  XXXXXXX, RESET
),

};

//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}

// void persistent_default_layer_set(uint16_t default_layer) {
//   eeconfig_update_default_layer(default_layer);
//   default_layer_set(default_layer);
// }

/* Cases to switch default layer to QWERTY, COLEMAK or DVORAK
    and to access ADJUST layer to access the switch keys */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    // case LOWER:
    //   if (record->event.pressed) {
    //     layer_on(_LOWER);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_LOWER);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    //   break;
    // case RAISE:
    //   if (record->event.pressed) {
    //     layer_on(_RAISE);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_RAISE);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    //   break;
    // case ADJUST:
    //   if (record->event.pressed) {
    //     layer_on(_ADJUST);
    //   } else {
    //     layer_off(_ADJUST);
    //   }
    //   return false;
    //   break;
    case KC_ESC_EN:
      if (record->event.pressed) {
        register_code(KC_ESC);
        register_code(KC_LANG2);
      } else {
        unregister_code(KC_ESC);
        unregister_code(KC_LANG2);
      }
      return false;
      break;
  }
  return true;
}
