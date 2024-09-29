/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

//user defined macros for better keymap readability
#define LT_LWSP	LT(_LOWER,KC_SPC)
#define LT_LBSP LT(_LOWER,KC_BSPC)
#define LT_HBSP LT(_HIGHER,KC_BSPC)
#define TD_HOEN TD(TD_HEND)

//base layer switchers
#define DF_BAS1 DF(_BASE1)
#define DF_BAS2 DF(_BASE2)
#define DF_BAS3 DF(_BASE3)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// home right-alt on the F and J to enter polish letters
// additionally neighbor key D and K work as shift if needed for faster uppercase polish letter 
#define HO_FALT RALT_T(KC_F)
#define HO_JALT RALT_T(KC_J)
#define HO_DSFT LSFT_T(KC_D)
#define HO_KSFT LSFT_T(KC_K)
// right alt also available as right space
// and backspace as right space single tap
#define HO_BSPCALT RALT_T(KC_BSPC)

// access to lower layer for numbers in home row
// and shift_numbers in qwerty row
#define HO_LOWV LT(_LOWER,KC_V)
#define HO_LOWN LT(_LOWER,KC_N)

// aliases for momentary later switch
#define	MO_LO	MO(_LOWER)
#define MO_HI	MO(_HIGHER)




enum layers{
    _BASE1,
    _FN1,
    _BASE2,
    _FN2,
	_LOWER,
	_HIGHER,
	_BASE3, // home row mods experimnent
	_FN3,
};

// Tap Dance declarations
enum {
    TD_HEND,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_HEND] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
};

// custome key codes to programe more complex keypresses
enum custom_keycodes {
    CC_AACU = SAFE_RANGE,
	CC_CACU,
	CC_EACU,
	CC_LACU,
	CC_NACU,
	CC_OACU,
	CC_SACU,
	CC_XACU,
	CC_ZACU
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE1] = LAYOUT_ansi_90(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,
        MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP,
        MC_3,     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,
        MC_4,     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_BSPC,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,
        MC_5,     KC_LCTL,  KC_LWIN,  KC_LALT,  KC_SPC,             MO(_FN1),           KC_SPC,             KC_RALT,  KC_RCTL,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_FN1] = LAYOUT_ansi_90(
        BL_TOGG,  _______,  BL_DOWN,  BL_UP,    KC_TASK,  KC_FILE,  RGB_VAD,            RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,
        _______,  _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,            _______,  _______,  DF_BAS1,  DF_BAS2,  DF_BAS3,  _______,  _______,  _______,  KC_END,
        _______,  BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  BL_DOWN,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,            _______,                      _______,            _______,  _______,            _______,  _______,  _______),

    [_BASE2] = LAYOUT_ansi_90(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,
        KC_PAUS,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  TD_HOEN,
        KC_CALC,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP,
        DM_PLY1,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,
        DM_PLY2,  SC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     MO_LO,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SC_RSPC,            KC_UP,
        MC_5,     KC_LCTL,  KC_LWIN,  KC_LALT,  KC_SPC,             MO_LO,                        LT_HBSP,            MO(_FN2), KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_FN2] = LAYOUT_ansi_90(
        BL_TOGG,  _______,  BL_DOWN,  BL_UP,    KC_TASK,  KC_FILE,  RGB_VAD,            RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,
        _______,  _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,            _______,  _______,  DF_BAS1,  DF_BAS2,  DF_BAS3,  DT_DOWN,  DT_UP,    DT_PRNT,  KC_END,
        _______,  BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,            _______,  _______,  KC_UP,    _______,  _______,  _______,  _______,  _______,  _______,
        DM_REC1,  _______,  _______,  BL_DOWN,  DB_TOGG,  _______,  _______,            _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,            _______,  _______,
        DM_REC2,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,            _______,                      _______,            _______,  _______,            _______,  _______,  _______),

    [_LOWER] = LAYOUT_ansi_90(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_UNDS,  KC_PLUS,  _______,  _______,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,            KC_EQL,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,            _______,                      KC_SPC,             _______,  _______,            _______,  _______,  _______),

    [_HIGHER] = LAYOUT_ansi_90(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  CC_EACU,  _______,  _______,            _______,  _______,  _______,  CC_OACU,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  CC_AACU,  CC_SACU,  _______,  _______,  _______,            _______,  _______,  _______,  CC_LACU,  _______,  _______,            _______,  _______,
        _______,  _______,  CC_ZACU,  CC_XACU,  CC_CACU,  _______,  _______,  _______,  CC_NACU,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  KC_SPC,             _______,                      _______,            _______,  _______,            _______,  _______,  _______),

    [_BASE3] = LAYOUT_ansi_90(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,
        KC_MUTE,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_PAUS,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP,
        KC_CALC,  KC_CAPS,  HOME_A,   HOME_S,   HOME_D,   HOME_F,   KC_G,               KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN,KC_QUOT,            KC_ENT,   KC_PGDN,
        KC_CUT ,  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_BSPC,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,
        KC_COPY,  KC_LCTL,  KC_LWIN,  KC_LALT,  KC_SPC,             MO(_FN3),                     KC_RALT,            KC_RALT,  KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_FN3] = LAYOUT_ansi_90(
        BL_TOGG,  _______,  BL_DOWN,  BL_UP,    KC_TASK,  KC_FILE,  RGB_VAD,            RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,
        MC_1,     _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,            _______,  _______,  DF_BAS1,  DF_BAS2,  DF_BAS3,  DT_DOWN,  DT_UP,    DT_PRNT,  TD_HOEN,
        MC_2,     BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        MC_3,     _______,  _______,  BL_DOWN,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        MC_4,     _______,  _______,  _______,  _______,  _______,  BAT_LVL,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,            _______,
        MC_5,     _______,  _______,  _______,  _______,            _______,                      _______,            _______,  _______,            _______,  _______,  _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE1]  = { ENCODER_CCW_CW( KC_VOLD, KC_VOLU )},
    [_FN1]    = { ENCODER_CCW_CW( BL_DOWN, BL_UP   )},
    [_BASE2]  = { ENCODER_CCW_CW( KC_VOLD, KC_VOLU )},
    [_FN2]    = { ENCODER_CCW_CW( BL_DOWN, BL_UP   )},
    [_LOWER]  = { ENCODER_CCW_CW( BL_DOWN, BL_UP   )},
    [_HIGHER] = { ENCODER_CCW_CW( BL_DOWN, BL_UP   )},
    [_BASE3]  = { ENCODER_CCW_CW( KC_VOLD, KC_VOLU )},
    [_FN3]    = { ENCODER_CCW_CW( BL_DOWN, BL_UP   )}
};
#endif // ENCODER_MAP_ENABLE



// send down RALT before a polish letter is pressed
// and relese the RALT after
void polish_codes(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		register_code(KC_RALT);
		register_code(keycode);
	} else {
		unregister_code(keycode);
		unregister_code(KC_RALT);
	}
}


// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
	switch (keycode) {
		case DT_DOWN:
			if (record->event.pressed) {
				if (g_tapping_term >= DYNAMIC_TAPPING_TERM_INCREMENT) {
					g_tapping_term -= DYNAMIC_TAPPING_TERM_INCREMENT;
				}
			}
			break;
		case CC_AACU:
			polish_codes(KC_A, record);
			break;
		case CC_CACU:
			polish_codes(KC_C, record);
			break;
		case CC_EACU:
			polish_codes(KC_E, record);
			break;
		case CC_LACU:
			polish_codes(KC_L, record);
			break;
		case CC_NACU:
			polish_codes(KC_N, record);
			break;
		case CC_OACU:
			polish_codes(KC_O, record);
			break;
		case CC_SACU:
			polish_codes(KC_S, record);
			break;
		case CC_XACU:
			polish_codes(KC_X, record);
			break;
		case CC_ZACU:
			polish_codes(KC_Z, record);
			break;
	}
		
    return true;
}


// For more granular control of tapping term
// require TAPPING_TERM_PER_KEY to be defined in rules.mk
// see https://docs.qmk.fm/tap_hold#tapping_term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD_HOEN:
            return 175;
		case HO_BSPCALT:
			return 175;
        default:
            return g_tapping_term;
    }
}

