#include QMK_KEYBOARD_H

#define CTL_OSM OSM(MOD_LCTL)
#define ALT_OSM OSM(MOD_LALT)
#define GUI_OSM OSM(MOD_LGUI)
#define SFT_OSM OSM(MOD_LSFT)
#define HYP_OSM OSM(MOD_HYPR)

// Left-hand home row mods
#define MQ_A LGUI_T(KC_A)
#define MQ_S LALT_T(KC_S)
#define MQ_D LCTL_T(KC_D)
#define MQ_F LSFT_T(KC_F)
// #define MQ_G HYPR_T(KC_G)

// Right-hand home row mods
// #define MQ_H HYPR_T(KC_H)
#define MQ_J RSFT_T(KC_J)
#define MQ_K RCTL_T(KC_K)
#define MQ_L RALT_T(KC_L)
#define MQ_SCLN RGUI_T(KC_SCLN)

// for enthium CIEA and HTNS
#define ME_C LGUI_T(KC_C)
#define ME_I LALT_T(KC_I)
#define ME_E LCTL_T(KC_E)
#define ME_A LSFT_T(KC_A)

#define ME_H RSFT_T(KC_H)
#define ME_T RCTL_T(KC_T)
#define ME_N RALT_T(KC_N)
#define ME_S RGUI_T(KC_S)

#define UNDO C(KC_Z)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)

#define S_UNDO S(UNDO)
#define S_CUT S(CUT)
#define S_COPY S(COPY)
#define S_PASTE S(PASTE)

#define C_PSCR C(KC_PSCR)

enum layer_names {
    _QWERTY,
    _ENTHIUM,
    _NUM,
    _SYM,
    _FUN,
};

// Tap Dance declarations
enum {
    TD_BRACKETS,         // [ and ]
    TD_R_BKSP,           // R, Backspace
};

enum custom_keycodes {
    ENG_QWE = SAFE_RANGE,  // Switch to English QWERTY
    ENG_ENT,               // Switch to English Enthium
    RUS_QWE,               // Switch to Russian QWERTY-based
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENG_QWE:
            if (record->event.pressed) {
                set_single_default_layer(_QWERTY);
                tap_code16(LAG(KC_E));
            }
            return false;
        case ENG_ENT:
            if (record->event.pressed) {
                set_single_default_layer(_ENTHIUM);
                tap_code16(LAG(KC_E));
            }
            return false;
        case RUS_QWE:
            if (record->event.pressed) {
                set_single_default_layer(_QWERTY);
                tap_code16(LAG(KC_R));
            }
            return false;
    }
    return true;
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};

#define TD_RUHZ TD(TD_BRACKETS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3_ex2(
     KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_RGHT,       KC_UP,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  TD_RUHZ,
     KC_TAB,    MQ_A,    MQ_S,    MQ_D,    MQ_F,    KC_G, KC_LEFT,     KC_DOWN,    KC_H,    MQ_J,    MQ_K,    MQ_L, MQ_SCLN,  KC_QUOT,
     KC_ENT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, TG(_NUM),
                               HYP_OSM, TL_UPPR, TL_LOWR,                       KC_BSPC,  KC_SPC, KC_RSFT
  ),

  [_ENTHIUM] = LAYOUT_split_3x6_3_ex2(
     KC_GRV,    KC_B,    KC_Y,    KC_O,    KC_U, KC_SLSH, KC_RGHT,       KC_UP,    KC_X,    KC_L,    KC_D,    KC_W,    KC_V,  XXXXXXX,
       KC_Z,    ME_C,    ME_I,    ME_E,    ME_A, KC_COMM, KC_LEFT,     KC_DOWN,    KC_K,    ME_H,    ME_T,    ME_N,    ME_S,     KC_Q,
     KC_ENT, KC_QUOT, KC_MINS,  KC_EQL,  KC_DOT, KC_SCLN,                          KC_J,    KC_M,    KC_G,    KC_P,    KC_F, TG(_NUM),
                               HYP_OSM, TL_UPPR, TL_LOWR,                          KC_R,  KC_SPC, KC_RSFT
  ),

  [_NUM] = LAYOUT_split_3x6_3_ex2(
     KC_EQL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,     _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
    XXXXXXX, CTL_OSM, ALT_OSM, GUI_OSM, SFT_OSM, HYP_OSM, _______,     _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_COMM,   KC_DOT,
    XXXXXXX,    UNDO,     CUT,    COPY,   PASTE, XXXXXXX,                       KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,  _______,
                               _______, _______, _______,                       _______, _______,  KC_DEL
  ),

  [_SYM] = LAYOUT_split_3x6_3_ex2(
     KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______,     _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_BSPC,
    XXXXXXX, CTL_OSM, ALT_OSM, GUI_OSM, SFT_OSM, HYP_OSM, _______,     _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,   KC_GRV,
    XXXXXXX,  S_UNDO,   S_CUT,  S_COPY, S_PASTE, XXXXXXX,                       KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,  KC_TILD,
                               _______, _______, _______,                       _______, _______, _______
  ),

  [_FUN] = LAYOUT_split_3x6_3_ex2(
    QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,     _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,
     EE_CLR, RGB_HUI, RGB_SAI, RGB_VAI, KC_VOLU,  C_PSCR, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, CG_LNRM, XXXXXXX,   KC_F12,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_VOLD, KC_PSCR,                       XXXXXXX, CG_LSWP, XXXXXXX, XXXXXXX, CM_TOGG,  AS_TOGG,
                               _______, _______, _______,                       _______, _______, _______
  ),

};

#include "g/keymap_combo.h"
