/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum planck_layer {
  _DEFALUT,
  _LOWER,
  _RAISE,
  _T1,
  _MGR,
  _T2,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  KC_ESC_EN,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOVE MO(_T1)
#define SYMBOL MO(_T2)
#define MGR MO(_MGR)
#define KC_MV_SCLN LT(_T1, KC_SCLN)
#define ALT_BS ALT_T(KC_BSPC)
#define SFT_SPC SFT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define LT_SPC LT(_T1, KC_SPC)
#define LT_ENT LT(_T2, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Default
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Esc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down | MGR  |Raise |
 * `-----------------------------------------------------------------------------------'
 */
[_DEFALUT] = LAYOUT_planck_grid(
    KC_TAB,   KC_Q,     KC_W,    KC_E,     KC_R,      KC_T,     KC_Y,      KC_U,    KC_I,     KC_O,       KC_P,        KC_BSPC,
    KC_LCTL,  KC_A,     KC_S,    KC_D,     KC_F,      KC_G,     KC_H,      KC_J,    KC_K,     KC_L,       KC_MV_SCLN,  KC_ENT,
    KC_LSFT,  KC_Z,     KC_X,    KC_C,     KC_V,      KC_B,     KC_N,      KC_M,    KC_COMM,  KC_DOT,     KC_SLSH,     KC_ESC_EN,
    _______,  KC_LCTL,  KC_TAB,  KC_LGUI,  LT_SPC,    SFT_SPC,  SFT_SPC,   LT_ENT,  ALT_BS,   KC_ESC_EN,  KC_RCTL,     _______
),

/* Move
* ,-----------------------------------------------------------------------------------.
* |   ~  |  6   |  7   |  8   |  9   |  0   |      |   &  |   *  |   (  |   )  | Bksp |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |  1   |  2   |  3   |  4   |  5   |      |   _  |   +  |   {  |   }  |  |   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
* `-----------------------------------------------------------------------------------'
*/
[_T1] = LAYOUT_planck_grid(
    KC_TRNS,  _______,  KC_7,     KC_8,     KC_9,      KC_0,     _______,   _______,  _______,  _______,   _______,  KC_TRNS,
    KC_TRNS,  _______,  KC_4,     KC_5,     KC_6,      _______,  KC_LEFT,   KC_DOWN,  KC_UP,    KC_RIGHT,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  _______,  KC_1,     KC_2,     KC_3,      _______,  _______,   _______,  _______,  _______,   _______,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS
),

/* Symbol
* ,-----------------------------------------------------------------------------------.
* |   ~  |  6   |  7   |  8   |  9   |  0   |      |   &  |   *  |   (  |   )  | Bksp |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |  1   |  2   |  3   |  4   |  5   |      |   _  |   +  |   {  |   }  |  |   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
* `-----------------------------------------------------------------------------------'
*/
[_T2] = LAYOUT_planck_grid(
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_MINS,
    KC_TRNS,  KC_TRNS,  KC_LCBR,  KC_DQT,   KC_RCBR,  KC_TRNS,  KC_MINS,  KC_EQL,   KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_GRV,
    KC_TRNS,  KC_TRNS,  KC_LBRC,  KC_QUOT,  KC_RBRC,  KC_TRNS,  KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_TILD,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_HOME, KC_END, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,    KC_8,   KC_9,    KC_0,    KC_BSPC,
    KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
    _______,KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
* ,-----------------------------------------------------------------------------------.
* |   ~  |  6   |  7   |  8   |  9   |  0   |      |   &  |   *  |   (  |   )  | Bksp |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |  1   |  2   |  3   |  4   |  5   |      |   _  |   +  |   {  |   }  |  |   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ | ISO  | Home | End  |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
* `-----------------------------------------------------------------------------------'
*/
[_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LNG2, KC_TRNS, KC_TRNS, KC_LNG1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MGR,     KC_TRNS
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MGR] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______,  _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _T1, _T2, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_DEFALUT);
      }
      return false;
      break;
     // case BACKLIT:
      //   if (record->event.pressed) {
      //     register_code(KC_RSFT);
      //     #ifdef BACKLIGHT_ENABLE
      //       backlight_step();
      //     #endif
      //     #ifdef KEYBOARD_planck_rev5
      //       writePinLow(E6);
      //     #endif
      //   } else {
      //     unregister_code(KC_RSFT);
      //     #ifdef KEYBOARD_planck_rev5
      //       writePinHigh(E6);
      //     #endif
      //   }
      //   return false;
      //   break;
      // case EXT_PLV:
      //   if (record->event.pressed) {
      //     #ifdef AUDIO_ENABLE
      //       PLAY_SONG(plover_gb_song);
      //     #endif
      //     // layer_off(_PLOVER);
      //   }
      //   return false;
      //   break;
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

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
