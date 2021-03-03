/* Copyright 2020
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

#define _MAIN 0
#define _MOVE 1
#define _SYMBOL 3
#define _ADJUST 4

enum custom_keycodes {
    KC_ESC_EN = SAFE_RANGE,
};

enum user_macro {
    UM_SPC,
    UM_ENT,
};

#define M_SPC  MACROTAP(UM_SPC)
#define M_ENT  MACROTAP(UM_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │TAB│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │BS │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │Ctrl│ A │ S │ D │ F │ G │ H │ J │ K │ L │ SCLN │
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
     * │Shift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │  / │
     * ├────┬─┴─┬─┴──┬┴───┴───┼───┴───┴──┬┴───┼───┼────┤
     * │Sft │Alt│CMD │ Space  │ Enter    │Alt │ESC│Sft │
     * └────┴───┴────┴────────┴──────────┴────┴───┴────┘
     */
    [_MAIN] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,             KC_SCLN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_LSFT, KC_LALT, KC_LGUI,                   M_SPC,  M_ENT,                      KC_RALT,   KC_GESC, KC_RSFT
    ),

    /* Function Layer 1 (Move)
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │   │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │Ctrl│   │   │   │   │   │   │   │   │SCN│QUOT  │
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
     * │Shift │   │   │   │   │   │   │   │   │ ▴ │    │
     * ├────┬─└───┴───┴───┘───┌──────────┐┴───┼───┼────┤
     * │    │   │    │ -----  │ -------  │  ◂ │ ▾ │ ▸  │
     * └────┴───┴────┴────────└──────────┘────┴───┴────┘
     */
    [_MOVE] = LAYOUT(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN,          KC_QUOT,
        KC_TRNS,          _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,
        _______, _______, _______,                   KC_TRNS, KC_TRNS,                   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Function Layer 2 (SYMBOL)
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │ ! │ @ │ # │ $ │ % │ ^ │ & │ * │ ( │ ) │ - │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │Ctrl│   │   │   │   │ - │ = │ { │ } │ | │  `   │
     * ├────└─┬─┴─┬─┴─┬───┐─┴─┬─└───┴───┴───┴───┘─┬────┤
     * │Shift │   │   │   │   │ _ │ + │ [ │ ] │ \ │ ~  │
     * ├────┬─┴─┬─┴──┬┴───┴───┼───┴───┴──┬┴───┼───┼────┤
     * │    │   │    │ -----  │ -------  │    │   │    │
     * └────┴───┴────┴────────└──────────┘────┴───┴────┘
     */
    [_SYMBOL] = LAYOUT(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
        KC_TRNS, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE,           KC_GRV,
        KC_TRNS,          _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
        _______, _______, _______,                   KC_TRNS, KC_TRNS,                   _______, _______, _______
    ),

    /* Function Layer 3 (ADJUST)
     * ┌───┬───┬───┬───┬───┬───┬───┐───┌───┬───┐───┬───┐
     * │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│
     * └───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐──└┬──┴┬──┴┐──┴───┤
     * │    │   │   │   │LG1│   │   │LG2│   │   │      │
     * ├────└─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴───┴───┴───┴─┐────┤
     * │      │   │   │   │   │   │   │   │   │   │Rset│
     * ├────┬─└───┴───┴───┴───┴───┴───┴───┴───┴───┘────┤
     * │    │   │    │ -----  │ -------  │    │   │    │
     * └────┴───┴────┴────────┴──────────┴────┴───┴────┘
     */
    [_ADJUST] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, KC_LANG2, _______, _______, KC_LANG1, _______, _______,          _______,
        _______,          _______, _______, _______,  _______, _______, _______,  _______, _______, _______, RESET,
        _______, _______, _______,                    KC_TRNS, KC_TRNS,                    _______, _______, _______
    ),
};

uint32_t layer_state_set_user(uint32_t state) {
    state = update_tri_layer_state(state, _MOVE, _SYMBOL, _ADJUST);
    return state;
}

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

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
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
