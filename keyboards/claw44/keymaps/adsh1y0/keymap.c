#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
// #define _QWERTY 0
// #define _LOWER 1
// #define _RAISE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  KC_ESC_EN,
  KC_LANG_TGL,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
  UM_EMHL,
  UM_KHKR
};

// macro
#define KC_M_EMHL MACROTAP(UM_EMHL) // 「Lower」キー用のキーコード
#define KC_M_KHKR MACROTAP(UM_KHKR) // 「Raise」キー用のキーコード

// common
#define KC_ KC_TRNS
#define KC_XXXX KC_NO
#define KC_RST RESET
#define KC_VD KC__VOLDOWN
#define KC_VU KC__VOLUP

// layer
#define KC_L_LOWER LOWER
#define KC_L_RAISE RAISE
#define KC_L_S_JA LT(_LOWER, KC_S_JA)
#define KC_R_S_EN LT(_RAISE, KC_S_EN)
#define KC_R_SCLN LT(_RAISE, KC_SCLN) // tap: ;, 長押し: _RAISE
#define KC_M_A LT(_RAISE, KC_A) // tap: A, 長押し: _RAISE

// shift_t
#define KC_S_SPC LSFT_T(KC_SPC)
#define KC_S_ENT LSFT_T(KC_ENT)
#define KC_S_TAB LSFT_T(KC_TAB)
#define KC_S_ESC LSFT_T(KC_ESC)
#define KC_S_JA LSFT_T(KC_LANG1)
#define KC_S_EN LSFT_T(KC_LANG2)

// cmd_t
#define KC_M_F LCMD_T(KC_F)
#define KC_M_D LCMD_T(KC_D)
#define KC_M_J LCMD_T(KC_J)
#define KC_M_K LCMD_T(KC_K)

// ctl_t
#define KC_C_S LCTL_T(KC_S)
#define KC_C_L LCTL_T(KC_L)
#define KC_C_BS LCTL_T(KC_BSPC)

// alt_t
#define KC_A_D ALT_T(KC_D)
#define KC_A_K ALT_T(KC_K)
#define KC_A_Z ALT_T(KC_Z)
#define KC_A_SL ALT_T(KC_SLSH)
#define KC_A_DEL ALT_T(KC_DEL)
#define KC_A_BS ALT_T(KC_BSPC)

// cmd+shift_t
#define KC_MS_Q SCMD_T(KC_Q)
#define KC_MS_A SCMD_T(KC_A)
#define KC_MS_S SCMD_T(KC_S)
#define KC_MS_SC SCMD_T(KC_SCLN)
#define KC_MS_ESC SCMD_T(KC_ESC)

//
#define KC_MR RCMD(KC_R)
#define KC_MF RCMD(KC_F)
#define KC_MW RCMD(KC_W)
#define KC_MX RCMD(KC_X)
#define KC_MC RCMD(KC_C)
#define KC_MV RCMD(KC_V)
#define KC_MTAB RCMD(KC_TAB)
#define KC_MSF RCMD(RSFT(KC_F))
#define KC_MSR RCMD(RSFT(KC_R))
#define KC_MST RCMD(RSFT(KC_T))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // M_ = LCMD_T(
  // A_ = ALT_T(
  // C_ = LCTL_T(
  // MS_ = SMD_T(
  // R_ = LT(_RAISE
  // L_ = LT(_LOWER

  [_QWERTY] = LAYOUT_kc( \
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
     TAB,  Q  , W  , E  , R  , T  ,       Y  , U  , I  , O  , P  ,MINS,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LCTL, A ,  S ,  D  , F ,  G  ,       H  , J  , K ,  L  , R_SCLN, QUOT,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,       N  , M  ,COMM,DOT ,SLSH,ESC_EN,
  //`----+----+----+----+----+----/     \----+----+----+----+----+----'
            LCMD,L_RAISE,S_SPC,S_EN,      S_JA,S_ENT,L_LOWER,A_BS
  //          `----+----+----+----'     `----+----+----+---'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         , 6  , 7  , 8  , 9  , 0  ,          ,    ,    ,    , UP ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LCTL, 1  , 2  , 3  , 4  , 5  ,      LEFT,DOWN, UP, RGHT,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LSFT,    ,    ,    ,    ,    ,      DOWN,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----/     \----+----+----+----+----+----'
            LCMD,L_RAISE,S_SPC,S_EN,     S_JA,S_ENT,L_LOWER,A_BS
  //          `----+----+----+----'     `----+----+----+----'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,EXLM, AT ,HASH,DLR ,PERC,      CIRC,AMPR,ASTR,LPRN,RPRN,MINS,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LCTL,    ,    ,    ,    ,    ,      MINS,EQL ,LCBR,RCBR,PIPE,GRV ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LSFT,    ,    ,    ,    ,    ,      UNDS,PLUS,LBRC,RBRC,BSLS,TILD,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
            LCMD,L_RAISE,S_SPC,S_EN,     S_JA,S_ENT,L_LOWER,A_BS
  //          `----+----+----+----'     `----+----+----+----'
  ),

};

void matrix_init_user(void) {
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
  #ifdef SSD1306OLED
    iota_gfx_init(!has_usb());   // turns on the display
  #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
  iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    // matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
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
    case KC_LANG_TGL:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(" "));
      }
      return false;
  }
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case UM_EMHL: // タップで「英数」と「無変換」、ホールドで「Lower」
      return MACRO_TAP_HOLD_LAYER( record, MACRO(T(MHEN), T(LANG1), END), _LOWER );
    case UM_KHKR: // タップで「かな」と「変換」、ホールドで「Raise」
      return MACRO_TAP_HOLD_LAYER( record, MACRO(T(HENK), T(LANG2), END), _RAISE );
  };
  return MACRO_NONE;
}

