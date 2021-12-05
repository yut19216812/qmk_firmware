#include QMK_KEYBOARD_H

#define _MAIN 0
#define _MGR 1
#define _MOVE 2
#define _SYMBOL 3
#define _GAME 4

enum custom_keycodes {
    KC_ESC_EN = SAFE_RANGE,
};

#define KC_MV_SCLN LT(_MOVE,  KC_SCLN)
#define SYMBOL_L_SPC LT(_SYMBOL, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_60_tsangan_hhkb(
        KC_ESC_EN, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRAVE, KC_BSPC,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_PIPE,
        KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_MV_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_MGR),
        _______,   KC_LANG2, KC_LGUI,                        SYMBOL_L_SPC,                           ALT_T(KC_BSPC), TG(_GAME), _______
    ),
    [_MOVE] = LAYOUT_60_tsangan_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, _______,  _______, _______, _______, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_TRNS,
        _______, KC_TRNS, KC_TRNS,                            KC_TRNS,                                      KC_TRNS, KC_TRNS, _______
    ),
    [_SYMBOL] = LAYOUT_60_tsangan_hhkb(
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, _______, _______,
        _______,  _______, _______, _______, _______, _______, KC_MINS,  KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,  _______,
        _______,           _______, _______, _______, _______, _______,  KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD, KC_TRNS,
        _______,  KC_TRNS, KC_TRNS,                            KC_TRNS,                                      KC_TRNS, KC_TRNS, _______
    ),
    [_MGR] = LAYOUT_60_tsangan_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS,
        _______, KC_TRNS, KC_TRNS,                            KC_TRNS,                                      KC_TRNS, KC_TRNS, _______
    ),
    [_GAME] = LAYOUT_60_tsangan_hhkb(
        KC_ESC_EN,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRAVE, KC_BSPC,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_PIPE,
        KC_LCTL,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_MV_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_MGR),
        _______,        KC_LANG2, KC_LGUI,                           KC_SPC,                                      ALT_T(KC_BSPC), KC_TRNS, _______
    )
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
