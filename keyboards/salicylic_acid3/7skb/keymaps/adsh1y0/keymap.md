#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _MAIN,
  _MGR,
  _MOVE,
  _SYMBOL,
  _ADJUST
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  KC_ESC_EN
};

#define KC_MV_SCLN LT(_MOVE,  KC_SCLN)

enum user_macro {
  UM_SPC,
  UM_ENT
};

#define M_SPC  MACROTAP(UM_SPC)
#define M_ENT  MACROTAP(UM_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, MO(_MGR),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               KC_LALT, KC_LGUI,  KC_SPC,  KC_SPC,               KC_SPC,  KC_SPC, KC_RGUI, KC_RALT
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_MOVE] = LAYOUT(
    //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS,  KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //|-------+--------+--------+--------+--------+---------|   |--------+--------+--------+--------+--------+--------+--------|
                KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
              //`-------------------------------------------|   |--------------------------------------------'
  ),

  [_SYMBOL] = LAYOUT(
    //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      KC_TRNS,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,  KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD, KC_TRNS,
    //|-------+--------+--------+--------+--------+---------|   |--------+--------+--------+--------+--------+--------+--------|
                KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
              //`-------------------------------------------|   |--------------------------------------------'
  ),

  [_MGR] = LAYOUT(
    //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, RGB_TOG, _______, RGB_HUI, RGB_HUD, RGB_SAI,       RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, _______, RESET,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,        _______, _______, RGB_SPI, RGB_SPD, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
    //|-------+--------+--------+--------+---------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
            //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_ADJUST] = LAYOUT( /* Base */
    //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_LANG2, KC_TRNS,    KC_TRNS, KC_LANG1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
            //`---------------------------------------------|   |--------------------------------------------'
  )
};

//A description for expressing the layer position in LED mode.
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
      break;
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

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case UM_SPC:
      return MACRO_TAP_HOLD_LAYER(record, MACRO(TYPE(KC_SPC), END), _MOVE);
    case UM_ENT:
      return MACRO_TAP_HOLD_LAYER(record, MACRO(TYPE(KC_ENT), END), _SYMBOL);
  };
  return MACRO_NONE;
};
