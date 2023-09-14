/* Copyright 2022 Andres Aravena based on Giorgio Campiotti
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

to compile
make handwired/istanbul_planck:default:flash
 */

#include QMK_KEYBOARD_H

#include "quantum.h"

#define LAYOUT( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311  \
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011}, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111}, \
	{ K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211}, \
	{ K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311}  \
}

//#include "keymap_italian.h"

#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS
// #define UNICODE_KEY_MAC  KC_RALT

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION,
  _NUM
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCTION,
  ADJUST,
  MEH,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT LT(_FUNCTION, KC_LBRC)
#define CTR_TAB CTL_T(KC_TAB)
#define LALTSPC LALT_T(KC_SPC)
#define RALTSPC RALT_T(KC_SPC)
#define LCMDBRC LCMD_T(KC_RBRC)
#define ____ _______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( // default layer
QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
CTR_TAB, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
FUNCT,   SC_LCPO, SC_RAPC, LCMDBRC, LOWER, LALTSPC,RALTSPC, RAISE,KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT),

[_LOWER] = LAYOUT( // lower level
  KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR, KC_LPRN, KC_RPRN, KC_DELETE,
  KC_DEL,  KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_MINS, KC_EQL,  KC_UNDS,   KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,  KC_BSLS, KC_SCLN,   KC_COLN, KC_LBRC, KC_RBRC, KC_ENT,
TG(_NUM), _______, _______, _______, _______, KC_SPC, KC_SPC, _______,   KC_HOME, KC_PGDN, KC_PGUP, KC_END),

[_RAISE] = LAYOUT( // raise level
  KC_GRV, KC_1,   KC_2,  KC_3,  KC_4,   KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_DEL, KC_F1,  KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
 TG(_NUM), _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

[_ADJUST] = LAYOUT( // activable with rasie+lower
  ____, QK_BOOT, DB_TOGG,  ____,   ____, BL_TOGG, BL_STEP, BL_BRTG, ____, ____, ____, KC_KB_POWER,
  ____,  AU_TOG,    ____, AU_ON, AU_OFF,  MU_TOG,  MU_MOD,    ____, ____, ____, ____, KC_SLEP,
  ____, CK_TOGG, CK_DOWN, CK_UP, CK_RST,    ____, _______, _______, ____, ____, ____, KC_PWR,
  QK_BOOT, QK_RBT,  ____,  ____,   ____, _______, _______, _______, ____, ____, ____, ____),

[_FUNCTION] = LAYOUT( // Function Key
  ____, KC_BRID, KC_BRIU, UC(0x000E8), ____, BL_DEC,  BL_INC, UC(0x000F9), UC(0x000EC), UC(0x000F2), KC_VOLD, KC_VOLU,
  ____, UC(0x000E0), UC(0x020AC), UC(0x000B0), ____, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_MUTE,
  KC_CAPS, ____, _______, UC(0x30C4), ____, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,
  ____, _______, _______, _______, TG(_NUM),____, _______, TG(_NUM), KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

[_NUM] = LAYOUT(
  TO(_QWERTY),_______, KC_UP,_______, _______, _______, _______, KC_P7, KC_P8, KC_P9, KC_PSLS, _______,
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_PAST, KC_PEQL,
  _______, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_PENT,
  TG(_NUM), _______,_______, _______, _______, _______, _______, _______, KC_P0, KC_PDOT, KC_PPLS, KC_COMM),
};

/*
áéíóúñ¡
çğıöüş
euro 0x020AC
copyright 0x000A9
registered 0x000AE
trademark 0x02122
agrave 0x000E0
egrave 0x000E8
igrave 0x000EC
ograve 0x000F2
ugrave 0x000F9
degree 0x000B0
katana 0x30C4
poop 0x1F4A9 // 💩
rofl  0x1F923 // 🤣
kiss 0x1F619 // 😙
*/

void matrix_init_user(){
  set_unicode_input_mode(UNICODE_MODE_MACOS);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


/*

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:

    case LOWER:
      return false;
    default:
      return true;
  }
}

*/
