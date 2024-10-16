/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
		KC_LGUI, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                   KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_QUOT,
											KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 6
    keyball_set_scroll_mode(get_highest_layer(state) == 6);

	#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
	keyball_handle_auto_mouse_layer_change(state);
	
    // switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
    //     case 1:
    //         state = remove_auto_mouse_layer(state, false);
    //         set_auto_mouse_enable(false);
    //         break;
    //     default:
    //         set_auto_mouse_enable(true);
    //         break;
    // }
    #endif

    return state;
}

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}
#endif

#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"
void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
