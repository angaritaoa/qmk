#include QMK_KEYBOARD_H

// Symbolic names for macro IDs.
#define _QWERTY  0 // QUERTY layer
#define _COLEMAK 1 // COLEMAK layer
#define _DVORAK  2 // DVORAK layer
#define _LOWER   3 // LOWER layer
#define _RAISE   4 // RAISE layer
#define _NUMPAD  5 // NUMPAD layer
#define _ADJUST  6 // ADJUST layer (LOWER + RAISE)

// Macro shortcuts.
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NUMPAD LT(_NUMPAD, KC_ESC)
#define ADJUST MO(_ADJUST)
#define KC_TIL LALT(KC_E)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define UNDO LGUI(KC_Z)
#define AGAIN LSFT(LGUI(KC_Z))
#define SAVES LCTL(KC_S)
#define SAVEG LCTL(KC_G)
#define FIND LCTL(KC_F)
#define CLOSE LCTL(KC_W)
#define CAPSLOCK KC_CAPS_LOCK
#define MOOM LCTL(LCMD(KC_M))

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_planck_grid(
  //,-----------------------------------------------------------------------------------------------------------------------.
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_BSPC,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
        NUMPAD,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_QUOT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LCTL,  KC_LCTL,  KC_LCMD,  KC_LALT,    LOWER,   KC_ENT,   KC_SPC,    RAISE,  KC_LEFT,  KC_DOWN,    KC_UP, KC_RIGHT
  //`-----------------------------------------------------------------------------------------------------------------------'
  ),
  [_COLEMAK] = LAYOUT_planck_grid(
  //,-----------------------------------------------------------------------------------------------------------------------.
        NUMPAD,     KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,  KC_SCLN,  KC_BSPC,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
        KC_ESC,     KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,  KC_QUOT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_K,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LCTL,  KC_LGUI,  KC_LALT,  XXXXXXX,    LOWER,   KC_ENT,   KC_SPC,    RAISE,  KC_LEFT,  KC_DOWN,    KC_UP, KC_RIGHT
  //`-----------------------------------------------------------------------------------------------------------------------'
  ),
  [_DVORAK] = LAYOUT_planck_grid(
  //,-----------------------------------------------------------------------------------------------------------------------.
        NUMPAD,  KC_QUOT,  KC_COMM,   KC_DOT,     KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,  KC_BSPC,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
        KC_ESC,     KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,  KC_SLSH,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,  KC_SCLN,     KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,  KC_RSFT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LCTL,  KC_LGUI,  KC_LALT,  XXXXXXX,    LOWER,   KC_ENT,   KC_SPC,    RAISE,  KC_LEFT,  KC_DOWN,    KC_UP, KC_RIGHT
  //`-----------------------------------------------------------------------------------------------------------------------'
  ),
  [_LOWER] = LAYOUT_planck_grid(
  //,-----------------------------------------------------------------------------------------------------------------------.
       XXXXXXX,  XXXXXXX,   KC_APP,     MOOM,  XXXXXXX,  XXXXXXX,   KC_DEL,  KC_HOME,    KC_UP,   KC_END,  KC_PGUP,  KC_BSPC,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  KC_LCTL,  KC_LCMD,  KC_LSFT,  KC_LALT,  XXXXXXX,   KC_INS,  KC_LEFT,  KC_DOWN, KC_RIGHT,  KC_PGDN,  KC_PSCR,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     KC_V,  XXXXXXX,   KC_TAB,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_VOLD,  KC_VOLU,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,   KC_ENT,   KC_SPC,   ADJUST,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  //`-----------------------------------------------------------------------------------------------------------------------'
  ),
  [_RAISE] = LAYOUT_planck_grid(
  //,-----------------------------------------------------------------------------------------------------------------------.
       KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,   KC_DLR,  XXXXXXX,  XXXXXXX,  KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  KC_LCBR,  KC_RCBR,  KC_LPRN,  KC_RPRN,  XXXXXXX,  XXXXXXX,  KC_MINS,   KC_EQL,  KC_PIPE,  KC_BSLS,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,  KC_RBRC,  XXXXXXX,  XXXXXXX,  KC_UNDS,  KC_PLUS,   KC_GRV,  XXXXXXX,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   ADJUST,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  //`-----------------------------------------------------------------------------------------------------------------------'
  ),
  [_NUMPAD] = LAYOUT_planck_grid(
  //,-----------------------------------------------------------------------------------------------------------------------.
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     KC_7,     KC_8,     KC_9,  XXXXXXX,  KC_BSPC,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_COMM,     KC_4,     KC_5,     KC_6,     KC_0,   KC_DOT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     KC_1,     KC_2,     KC_3,  XXXXXXX,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  //`-----------------------------------------------------------------------------------------------------------------------'
  ),
  [_ADJUST] = LAYOUT_planck_grid(
  //,-----------------------------------------------------------------------------------------------------------------------.
         CLOSE,  XXXXXXX,  XXXXXXX, CAPSLOCK,    KC_F8,  XXXXXXX,  XXXXXXX,  XXXXXXX,    SAVEG,    SAVES,  XXXXXXX,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,    KC_F1,    KC_F2,    KC_F3,    KC_F5,  XXXXXXX,  XXXXXXX,      CUT,     COPY,    PASTE,     UNDO,    AGAIN,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_F10,  XXXXXXX,  XXXXXXX,     FIND,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   QWERTY,  COLEMAK,   DVORAK,    RESET
  //`-----------------------------------------------------------------------------------------------------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
    }
    return true;
}
