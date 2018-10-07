#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

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
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------  ------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------  -------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------  -------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------  +------+------+------+------+------+------|
 * | Esc  | GUI  | Adjs | Alt  |Lower |Space | |Enter |Raise | Alt  | Ins  | Caps | GUI  |
 * `-----------------------------------------  ------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
   KC_ESC,   KC_LGUI, ADJUST,  KC_LALT, LOWER,  KC_SPC,  KC_ENT,  RAISE,  KC_RALT, KC_INS,  KC_CAPS, KC_RGUI  \
),

/* Lower
 * ,-----------------------------------------  ------------------------------------------.
 * |      |      | Home |  Up  | End  | PgUp | |      |  7   |  8   |  9   |      | Del  |
 * |------+------+------+------+------+------  -------+------+------+------+------+------|
 * |      |      | Left | Down |Right | PgDn | |  0   |  4   |  5   |  6   |      |      |
 * |------+------+------+------+------+------  -------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |  1   |  2   |  3   |      |      |
 * |------+------+------+------+------+------  +------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------  ------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, KC_7,    KC_8,    KC_9,    _______, KC_DEL,  \
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_0,    KC_4,    KC_5,    KC_6,    _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Raise
 * ,-----------------------------------------  ------------------------------------------.
 * |      |      |   -  |   <  |   >  |  =   | | PgUp | Home |  Up  | End  |      | Del  |
 * |------+------+------+------+------+------  -------+------+------+------+------+------|
 * |      |      |      |  [   |   ]  |  \   | | PgDn | Left | Down |Right |      |      |
 * |------+------+------+------+------+------  -------+------+------+------+------+------|
 * |      |      |      |  (   |   )  |  `   | |      |      |      |      |      |      |
 * |------+------+------+------+------+------  +------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------  ------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  _______, _______, KC_MINS, KC_LT,   KC_GT,   KC_EQL,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_DEL,  \
  _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, _______, KC_LPRN, KC_RPRN, KC_GRV,  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Adjust
 * ,-----------------------------------------  ------------------------------------------.
 * |      | Vol+ |      |      |      |      | |  F12 |  F7  |  F8  |  F9  |      |      |
 * |------+------+------+------+------+------  -------+------+------+------+------+------|
 * |      | Vol- |      |      |      |      | |  F10 |  F4  |  F5  |  F6  |      |      |
 * |------+------+------+------+------+------  -------+------+------+------+------+------|
 * |      | Mute |      |      |      |      | |  F11 |  F1  |  F2  |  F3  |      |      |
 * |------+------+------+------+------+------  +------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |Reset |
 * `-----------------------------------------  ------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, KC_VOLU, _______, _______, _______, _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______, _______, \
  _______, KC_VOLD, _______, _______, _______, _______, KC_F10,  KC_F4,   KC_F5,   KC_F6,   _______, _______, \
  _______, KC_MUTE, _______, _______, _______, _______, KC_F11,  KC_F1,   KC_F2,   KC_F3,   _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET    \
)

};

void layer_toggle(int layer, bool is_on) {
  if (is_on) {
    layer_on(layer);
  } else {
    layer_off(layer);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      layer_toggle(_LOWER, record->event.pressed);
      return false;

    case RAISE:
      layer_toggle(_RAISE, record->event.pressed);
      return false;

    case ADJUST:
      layer_toggle(_ADJUST, record->event.pressed);
      return false;
  }
  return true;
}
