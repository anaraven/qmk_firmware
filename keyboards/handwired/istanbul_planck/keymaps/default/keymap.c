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
make PlankGiorgio:default:flash


 */ 

#include QMK_KEYBOARD_H

#include "quantum.h"

#define LAYOUT_planck_grid( \
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
#define UNICODE_SELECTED_MODES UC_MAC
// #define UNICODE_KEY_MAC  KC_RALT

//extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION,
  _ESC,
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

// L = .-.. 
// R = .-. 
// F = ..-. 

#define LO E__NOTE(_C5), Q__NOTE(_C5),E__NOTE(_C5),E__NOTE(_C5)//, B__NOTE(_C3), W__NOTE(_C3), Q__NOTE(_C3)
#define RA E__NOTE(_C5), Q__NOTE(_C5),E__NOTE(_C5)//, B__NOTE(_C3), W__NOTE(_C3), Q__NOTE(_C3)
#define FUN E__NOTE(_C5),E__NOTE(_C5), Q__NOTE(_C5),E__NOTE(_C5)//, B__NOTE(_C3), W__NOTE(_C3), Q__NOTE(_C3)


// #ifdef AUDIO_ENABLE
//   float plover_song[][2]     = SONG(PLOVER_SOUND);
//   float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
//   float s1[][2]              = SONG(LO);
//   float s2[][2]              = SONG(RA);
//   float s3[][2]              = SONG(FUN);
//   float s4[][2]              = SONG(LO);
//   float s5[][2]              = SONG(IMPERIAL_MARCH);
//   float s6[][2]              = SONG(E1M1_DOOM);
//   float s7[][2]              = SONG(COIN_SOUND);
//   float s8[][2]              = SONG(ONE_UP_SOUND);
//   float s9[][2]              = SONG(SONIC_RING);
// #endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid( // default layer
  QK_GESC,    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
  LT(_ESC, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
  MO(_FUNCTION), KC_LCTRL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT),

// [_QWERTY] = LAYOUT_planck_grid(
//   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
//   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
//   THK,     KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
// ),


[_LOWER] = LAYOUT_planck_grid( // lower level
  KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DELETE,
  KC_DEL,  KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_UNDS,  KC_PLUS,  KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11, KC_F12, KC_SCOLON, KC_COLN, KC_HOME, KC_END,  RSFT_T(KC_ENT),
  MO(_NUM), _______, _______, _______, _______, LALT(KC_SPC), LALT(KC_SPC), _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

// [_LOWER] = LAYOUT_planck_grid(
//   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
//   KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
//   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
//   _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
// ),


[_RAISE] = LAYOUT_planck_grid( // raise level
  KC_GRV, KC_1,   KC_2,  KC_3,  KC_4,  KC_5,    KC_6, KC_7, KC_8, KC_9, KC_0, _______, 
  KC_DEL, KC_F1,  KC_F2, KC_F3, KC_F4, KC_F5,   KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, 
  TG(_NUM), _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

// [_RAISE] = LAYOUT_planck_grid(
//   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
//   KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
//   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
// ),

[_ADJUST] = LAYOUT_planck_grid( // mouse and other functions level, also activable with rasie+lower
  _______, QK_BOOT, DB_TOGG, TERM_ON, TERM_OFF, _______, _______, _______, _______, _______, _______, KC_KB_POWER, 
  _______, AU_TOG,  _______, AU_ON, AU_OFF,  MU_TOG,   MU_MOD, _______, _______, _______, _______, KC_SLEP,
  _______, CK_TOGG, CK_DOWN, CK_UP, CK_RST,  _______, _______, _______, _______, _______, _______, KC_PWR,
  QK_BOOT, RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

[_FUNCTION] = LAYOUT_planck_grid( // Function Key
  _______, KC_BRID, KC_BRIU,   KC_F3, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLU,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_VOLD,
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

[_ESC] = LAYOUT_planck_grid( // ESC Key used for accent and some special key/functions
  _______, UC_MOD, _______, UC(0x000E8), _______, KC_TILDE, _______, UC(0x000F9), UC(0x000EC), UC(0x000F2), _______, _______,
  _______, UC(0x000E0), UC(0x020AC), UC(0x000B0), _______, _______, _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, UC(0x30C4), _______, _______, _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

[_NUM] = LAYOUT_planck_grid( 
  TO(_QWERTY), _______,   KC_UP, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, KC_PSLS, _______, 
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_PAST, KC_PEQL,
  _______, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_PENT,
  TG(_NUM), _______, _______, _______, _______, _______, _______, KC_COMM, KC_P0, KC_PDOT, KC_PPLS, _______),
};

  /* 
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
  meh ¯\_(ツ)_/¯
  eicar X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*
  */

  // KC_ASTG autoshit toggle

  uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  }

  // etc..

  // Now define the array of layers. Later layers take precedence
  // const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  //     my_capslock_layer,
  //     my_layer1_layer,    // Overrides caps lock layer
  //     my_layer2_layer,    // Overrides other layers
  //     my_layer3_layer,    // Overrides other layers
  //     my_layer4_layer,     // Overrides other layers
  //     my_layer5_layer     // Overrides other layers

  // );

  // void keyboard_post_init_user(void) {
  //     // Enable the LED layers
  //     rgblight_layers = my_rgb_layers;
  // }

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
