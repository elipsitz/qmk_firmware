#include QMK_KEYBOARD_H

#include "print.h"

#define LAYER_BASE 0
#define LAYER_FN 1
#define LAYER_PROGM 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_BASE] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, MO(LAYER_FN), KC_A, KC_S, KC_D, KC_F, KC_G, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESC, KC_GRV, KC_INS, KC_LEFT, KC_RGHT, KC_LGUI, KC_LALT, KC_HOME, KC_BSPC, KC_DEL, KC_END, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS, KC_NO, MO(LAYER_PROGM), KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, MO(LAYER_FN), KC_RCTL, KC_RGUI, KC_PGUP, KC_PGDN, KC_ENT, KC_SPC),
	[LAYER_FN] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[LAYER_PROGM] = LAYOUT(QK_BOOT, KC_1, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};


// Key overrides for window management.
// (left shift + left command) => (ctrl+option+command) + key
#define WINDOW_OVERRIDE(key_in, key_out) \
  ko_make_basic(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LGUI), key_in, LCAG(key_out))
const key_override_t window_top    = WINDOW_OVERRIDE(KC_I, KC_UP);
const key_override_t window_bottom = WINDOW_OVERRIDE(KC_K, KC_DOWN);
const key_override_t window_left   = WINDOW_OVERRIDE(KC_J, KC_LEFT);
const key_override_t window_right  = WINDOW_OVERRIDE(KC_L, KC_RIGHT);
const key_override_t window_max    = WINDOW_OVERRIDE(KC_M, KC_M);
const key_override_t **key_overrides = (const key_override_t *[]){
    &window_top,
    &window_bottom,
    &window_left,
    &window_right,
    &window_max,
    NULL
};

// RGB lighting layers
const rgblight_segment_t PROGMEM my_rgb_layer_fn[] = RGBLIGHT_LAYER_SEGMENTS(
    // Light 1 LED starting at 3
    {3, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_rgb_layer_prog[] = RGBLIGHT_LAYER_SEGMENTS(
    // Light 1 LED starting at 3
    {3, 1, HSV_ORANGE}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_rgb_layer_fn,
    my_rgb_layer_prog
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    // Boot lights
    rgblight_disable_noeeprom();
}

// Called when layer state changes.
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, LAYER_FN));
    rgblight_set_layer_state(1, layer_state_cmp(state, LAYER_PROGM));
    return state;
}