#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _ENTHIUM,
    _NUM,
    _SYM,
    _FUN,
    _MEDIA,
};

// Tap Dance declarations
enum {
    TD_BRACKETS,         // [ and ]
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};

#define TD_RUHZ TD(TD_BRACKETS)

enum custom_keycodes {
    ENG_QWE = SAFE_RANGE,  // Switch to English QWERTY
    ENG_ENT,               // Switch to English Enthium
    RUS_QWE,               // Switch to Russian QWERTY-based
};

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

// #define S_UNDO S(UNDO)
// #define S_CUT S(CUT)
// #define S_COPY S(COPY)
// #define S_PASTE S(PASTE)

#define C_PSCR C(KC_PSCR)
#define OSL_MED OSL(_MEDIA)

// See config.h for TRI_LAYER_LOWER_LAYER and TRI_LAYER_UPPER_LAYER
#define TO_NUM TL_LOWR
#define TO_SYM TL_UPPR
#define R_SYM LT(_SYM, KC_R)
#define TAB_NUM LT(_NUM, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3_ex2(
     KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, QK_AREP,     OSL_MED,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, TD_RUHZ,
    XXXXXXX,    MQ_A,    MQ_S,    MQ_D,    MQ_F,    KC_G,  QK_REP,     HYP_OSM,    KC_H,    MQ_J,    MQ_K,    MQ_L, MQ_SCLN, KC_QUOT,
     KC_ENT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, QK_LLCK,
                                QK_REP, KC_BSPC, TAB_NUM,                        TO_SYM,  KC_SPC,  QK_REP
  ),

  [_ENTHIUM] = LAYOUT_split_3x6_3_ex2(
     KC_GRV,    KC_B,    KC_Y,    KC_O,    KC_U, KC_SCLN, QK_AREP,     OSL_MED,    KC_X,    KC_L,    KC_D,    KC_W,    KC_V, XXXXXXX,
       KC_Z,    ME_C,    ME_I,    ME_E,    ME_A, KC_COMM,  QK_REP,     HYP_OSM,    KC_K,    ME_H,    ME_T,    ME_N,    ME_S,    KC_Q,
     KC_ENT, KC_QUOT, KC_MINS,  KC_EQL,  KC_DOT, KC_SLSH,                          KC_J,    KC_M,    KC_G,    KC_P,    KC_F, QK_LLCK,
                                QK_REP, KC_BSPC, TAB_NUM,                         R_SYM,  KC_SPC,  QK_REP
  ),

  [_NUM] = LAYOUT_split_3x6_3_ex2(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,     _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, _______,     _______, KC_COMM,    KC_4,    KC_5,    KC_6, KC_ASTR,  KC_EQL,
    _______,    UNDO,     CUT,    COPY,   PASTE, XXXXXXX,                        KC_DOT,    KC_1,    KC_2,    KC_3, KC_SLSH, _______,
                               QK_AREP, _______, _______,                          KC_0, _______, QK_AREP
  ),

  [_SYM] = LAYOUT_split_3x6_3_ex2(
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______,     _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_SCLN, _______,     _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
    _______, KC_QUOT, KC_MINS,  KC_EQL,  KC_DOT, KC_SLSH,                       KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, _______,
                               QK_AREP, _______, _______,                       _______, _______, QK_AREP
  ),

  [_FUN] = LAYOUT_split_3x6_3_ex2(
    XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,     _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    QK_BOOT, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, CG_LNRM, XXXXXXX,  KC_F12,
    EE_CLR,  XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD,                       XXXXXXX, CG_LSWP, XXXXXXX, CM_TOGG, AS_TOGG, _______,
                               _______, _______, _______,                       _______, _______, _______
  ),

  [_MEDIA] = LAYOUT_split_3x6_3_ex2(
    XXXXXXX, XXXXXXX, XXXXXXX, ENG_QWE, RUS_QWE, ENG_ENT, _______,     _______, KC_VOLD, KC_VOLU, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  C_PSCR, _______,     _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX,    UNDO,     CUT,    COPY,   PASTE, KC_PSCR,                       KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, _______,
                               _______, _______, _______,                       _______, _______, _______
  ),

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

#include "g/keymap_combo.h"
