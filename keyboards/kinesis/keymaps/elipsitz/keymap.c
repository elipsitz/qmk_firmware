#include QMK_KEYBOARD_H

#include "print.h"

#define LAYER_BASE 0
#define LAYER_FN 1
#define LAYER_PROGM 2

enum my_keycodes {
  MY_BOOTLOADER = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_BASE] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, MO(LAYER_FN), KC_A, KC_S, KC_D, KC_F, KC_G, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESC, KC_GRV, KC_INS, KC_LEFT, KC_RGHT, KC_LGUI, KC_LALT, KC_HOME, KC_BSPC, KC_DEL, KC_END, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS, KC_NO, MO(LAYER_PROGM), KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, MO(LAYER_FN), KC_RCTL, KC_RGUI, KC_PGUP, KC_PGDN, KC_ENT, KC_SPC),
	[LAYER_FN] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[LAYER_PROGM] = LAYOUT(MY_BOOTLOADER, QK_REBOOT, QK_AUDIO_TOGGLE, QK_MUSIC_TOGGLE, QK_MUSIC_MODE_NEXT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

const uint8_t music_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(48, 49, 50, 51, 52, 53, 54, 55, 56, 36, 37, 38, 39, 40, 41, 24, 25, 26, 27, 28, 29, 12, 13, 14, 15, 16, 17, 0, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57, 58, 59, 60, 61, 62, 63, 64, 65, 42, 43, 44, 45, 46, 47, 30, 31, 32, 33, 34, 35, 18, 19, 20, 21, 22, 23, 6, 7, 8, 9, 10, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

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
const rgblight_segment_t PROGMEM my_rgb_layer_startup[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},
    {1, 1, HSV_ORANGE},
    {2, 1, HSV_YELLOW},
    {3, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_rgb_layer_fn[] = RGBLIGHT_LAYER_SEGMENTS(
    // Light 1 LED starting at 3
    {3, 1, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_rgb_layer_prog[] = RGBLIGHT_LAYER_SEGMENTS(
    // Light 1 LED starting at 3
    {3, 1, HSV_PURPLE}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_rgb_layer_startup,
    my_rgb_layer_fn,
    my_rgb_layer_prog
);

void enter_bootloader(void) {
    // Disable RGB layers, enable effects, and set everything to red.
    for (int i = 0; i < RGBLIGHT_MAX_LAYERS; i++) {
      rgblight_set_layer_state(i, false);
    }
    rgblight_enable_noeeprom();
    rgblight_sethsv_range(HSV_RED, 0, RGBLED_NUM);
    // And then enter the bootloader.
    reset_keyboard();
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    // Boot lights -- blink layer 0 for 500ms
    rgblight_disable_noeeprom();
    rgblight_blink_layer(0, 500);

    audio_off();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_BOOTLOADER:
      enter_bootloader();
      // Not reached.
      return false;
    default:
      return true;
  }
}

// Called when layer state changes.
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, LAYER_FN));
    rgblight_set_layer_state(2, layer_state_cmp(state, LAYER_PROGM));
    return state;
}