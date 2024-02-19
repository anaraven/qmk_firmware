/* Copyright 2022, 2023, 2024 Andres Aravena
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
make handwired/istanbul_preonic:default:flash
 */

#include QMK_KEYBOARD_H

#include "quantum.h"

#define LAYOUT( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411  \
) { \
	{ K000, K001, K002, K003, K004, K005}, \
	{ K100, K101, K102, K103, K104, K105}, \
	{ K200, K201, K202, K203, K204, K205}, \
	{ K300, K301, K302, K303, K304, K305}, \
	{ K400, K401, K402, K403, K404, K405}, \
    { K006, K007, K008, K009, K010, K011}, \
    { K106, K107, K108, K109, K110, K111}, \
    { K206, K207, K208, K209, K210, K211}, \
    { K306, K307, K308, K309, K310, K311}, \
    { K406, K407, K408, K409, K410, K411}  \
}

#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS
// #define UNICODE_KEY_MAC  KC_RALT

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION,
  _NUM
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCTION,
  ADJUST,
  MEH,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNCTION)
#define CTR_TAB CTL_T(KC_TAB)
#define LALTSPC LALT_T(KC_SPC)
#define RALTSPC RALT_T(KC_SPC)
#define LCMDBRC LCMD_T(KC_RBRC)
#define ____ _______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( // default layer
/* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │Bsp│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Tab│ q │ w │ e │ r │ t │ y │ u │ i │ o │ p │ \ │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Ctr│ a │ s │ d │ f │ g │ h │ j │ k │ l │ ; │ ' │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Shf│ z │ x │ c │ v │ b │ n │ m │ , │ . │ / │Ret│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Fn │Ctr│Alt│Cmd│Lwr│ space │Rai│Lft│Dnw│Up │Rgt│
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘ */
QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,
CTR_TAB, KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS,
KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, RALT_T(KC_ENT),
FUNCT,   KC_RCTL, KC_LOPT, KC_LCMD, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT),

[_LOWER] = LAYOUT( // lower level
/* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ ~ │ ! │ @ │ # │ $ │ % │ ^ │ & │ * │ [ │ ] │Del│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │ ~ │ ! │ @ │ # │ $ │ % │ ^ │ & │ * │ ( │ ) │ | │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Del│F1 │F2 │F3 │F4 │ - │ = │ _ │ + │ { │ } │ | │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Shf│F7 │F8 │F9 │F10│F11│ \ │ ; │ : │ [ │ ] │Ent│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Fn │Ctr│Alt│Cmd│Lwr│ space │Rai│Hom│Pdn│Pup│End│
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘ */
  KC_TILD, KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_BSPC,
  KC_TILD, KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  KC_DEL,  KC_LPRN, KC_RPRN,KC_LBRC,KC_RBRC, KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_SCLN, KC_COLN, KC_LBRC, KC_RBRC, KC_ENT,
TG(_NUM), _______, _______, _______, _______,LALTSPC, RALTSPC, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

[_RAISE] = LAYOUT( // raise level
/* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│Del│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ \ │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │del│ { │ } │F3 │F4 │ _ │ + │ - │ = │ [ │ ] │ \ │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Shf│F7 │F8 │F9 │F10│F11│F12│ \ │ § │Pup│Pdn│Ent│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Fn │Ctr│Alt│Cmd│Lwr│ space │Rai│Hom│Pdn│Pup│End│
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘ */
  KC_GRV, KC_F1,  KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_DELETE,
  KC_GRV, KC_1,   KC_2,   KC_3,  KC_4,  KC_5,   KC_6,    KC_7,    KC_8,   KC_9,    KC_0,    _______,
  KC_DEL,KC_LCBR,KC_RCBR,KC_LPRN,KC_RPRN,KC_UNDS,KC_PLUS,KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
 _______, KC_F7,  KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
 TG(_NUM), ____, ____, _______, ____, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

[_ADJUST] = LAYOUT( // activable with rasie+lower
/* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │   │USB│BT │AUT│   │Ltg│Lst│Lbr│   │   │   │Kpw│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │bot│dtg│   │   │Ltg│Lst│Lbr│   │   │   │Kpw│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │Atg│   │Aon│Aof│Mtg│Mmd│   │   │   │   │slp│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │ckt│ckd│cku│ckr│   │   │   │   │   │   │pwr│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │rbt│   │   │   │   │   │   │   │   │   │   │
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘ */
  ____, OU_USB,  OU_BT, OU_AUTO,   ____, BL_TOGG, BL_STEP, BL_BRTG, ____, ____, ____, KC_KB_POWER,
  ____, QK_BOOT, DB_TOGG,  ____,   ____, BL_TOGG, BL_STEP, BL_BRTG, ____, ____, ____, KC_KB_POWER,
  ____, AU_TOGG, _______, AU_ON, AU_OFF, MU_TOGG,  MI_MOD, _______, ____, ____, ____, KC_SLEP,
  ____, CK_TOGG, CK_DOWN, CK_UP, CK_RST, _______, _______, _______, ____, ____, ____, KC_PWR,
  ____, QK_RBT, _______,   ____,   ____, _______, _______, _______, ____, ____, ____, _______),

[_FUNCTION] = LAYOUT( // Function Key
/* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ ` │Bdw│Bup│F3 │   │dec│inc│prv│ply│nxt│Vdn│Vup│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │ ~ │   │   │   │   │   │Mut│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │F1 │F2 │F3 │F4 │F5 │lft│dwn│up │rgt│   │Mut│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Cps│F7 │F8 │F9 │F10│F11│F12│   │prv│ply│nxt│   │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Fn │Ctr│Alt│Cmd│num│ space │num│Hom│Pdn│Pup│End│
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘ */
  KC_GRV,  KC_BRID, KC_BRIU, KC_F3, ____, BL_DOWN,   BL_UP,  KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU,
  _______, _______, _______,  ____, ____, KC_TILDE, _______, _______, _______, _______, _______, KC_MUTE,
  _______,   KC_F1, KC_F2,   KC_F3, KC_F4,  KC_F5,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_MUTE,
  KC_CAPS,   KC_F7, KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12,  _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,
  _______, _______, _______,  ____, TG(_NUM),____,  _______, TG(_NUM), KC_HOME, KC_PGDN, KC_PGUP, KC_END),

[_NUM] = LAYOUT(
/* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │Qwr│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ / │   │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │Up │   │   │   │   │ 4 │ 5 │ 6 │ * │ = │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │lft│ ↓ │rgt│   │   │   │ 1 │ 2 │ 3 │ - │   │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │ 0 │ . │ + │ , │ret│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Num│Ctr│Alt│Cmd│Lwr│ space │Rai│Hom│Pdn│Pup│End│
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘ */
  TO(_QWERTY), KC_P1, KC_P2, KC_P3,  KC_P4, KC_P5, KC_P6,   KC_P7, KC_P8, KC_P9, KC_P0,   _______,
  _______, _______, KC_UP,   _______, ____,  ____, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PEQL,
  _______, KC_LEFT, KC_DOWN, KC_RGHT, ____,  ____, KC_PMNS, KC_P1, KC_P2, KC_P3, KC_PMNS, _______,
  _______, _______,_______, _______,  ____,  ____, ________,KC_P0, KC_COMM, KC_PDOT, KC_PPLS, KC_PENT,
  TG(_NUM), _______,_______, _______, _______, _______, _______, _______, ____, ____, ____, ____),
};

void matrix_init_user(){
  set_unicode_input_mode(UNICODE_MODE_MACOS);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
