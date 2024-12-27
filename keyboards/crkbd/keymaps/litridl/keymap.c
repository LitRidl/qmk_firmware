#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define CTL_OSM OSM(MOD_LCTL)  // One Shot Control
#define ALT_OSM OSM(MOD_LALT)  // One Shot Alt
#define GUI_OSM OSM(MOD_LGUI)  // One Shot GUI
#define SFT_OSM OSM(MOD_LSFT)  // One Shot Shift
#define HYP_OSM OSM(MOD_HYPR)  // One Shot Hyper

#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)

#define S_UNDO S(UNDO)
#define S_CUT S(CUT)
#define S_COPY S(COPY)
#define S_PASTE S(PASTE)

#define C_PSCR C(KC_PSCR)

// layer names enum
enum {
    _QWERTY,
    _NUM,
    _SYM,
    _FUN,
    _ENTHIUM,
};

// Tap Dance declarations
enum {
    TD_COPY_PASTE,       // Ctrl+C, Ctrl+V
    // TD_COPY_PASTE_MAC,   // Cmd+C, Cmd+V
    TD_BRACKETS,         // [ and ]
    TD_R_BKSP,           // R, Backspace
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_COPY_PASTE] = ACTION_TAP_DANCE_DOUBLE(COPY, PASTE),
    // [TD_COPY_PASTE_MAC] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_C), LGUI(KC_V)),
    [TD_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_R_BKSP] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_BSPC),
};


#define TD_RUHZ TD(TD_BRACKETS)
#define TD_CV TD(TD_COPY_PASTE)
#define TD_RBKS TD(TD_R_BKSP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3_ex2(
       KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, ALT_OSM,     SFT_OSM,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  TD_RUHZ,
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, CTL_OSM,     GUI_OSM,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
        TD_CV,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, TG(_NUM),
                                 HYP_OSM, TL_UPPR, TL_LOWR,                       KC_BSPC,  KC_SPC, KC_RSFT
  ),

  [_NUM] = LAYOUT_split_3x6_3_ex2(
     KC_EQL,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  _______,     _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
    XXXXXXX,  CTL_OSM, ALT_OSM, GUI_OSM, SFT_OSM, HYP_OSM,  _______,     _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_COMM,  KC_DOT,
    XXXXXXX,     UNDO,     CUT,    COPY,   PASTE, XXXXXXX,                        KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______, _______,
                                _______, _______, _______,                        _______, _______,  KC_DEL
  ),

  [_SYM] = LAYOUT_split_3x6_3_ex2(
     KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,  _______,     _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    XXXXXXX, CTL_OSM, ALT_OSM, GUI_OSM, SFT_OSM, HYP_OSM,  _______,     _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
    XXXXXXX,  S_UNDO,   S_CUT,  S_COPY, S_PASTE, XXXXXXX,                        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                               _______, _______, _______,                        _______, _______, _______
  ),

  [_FUN] = LAYOUT_split_3x6_3_ex2(
      QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
      XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, KC_VOLU,  C_PSCR,  _______,     _______, KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_VOLD, KC_PSCR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CM_TOGG, AS_TOGG,
                                 _______, _______, _______,                      _______, _______, _______
  ),

  [_ENTHIUM] = LAYOUT_split_3x6_3_ex2(
       KC_GRV,    KC_B,    KC_Y,    KC_O,    KC_U, KC_SLSH, ALT_OSM,     SFT_OSM,    KC_X,    KC_L,    KC_D,    KC_W,    KC_V,  XXXXXXX,
         KC_Z,    KC_C,    KC_I,    KC_E,    KC_A, KC_COMM, CTL_OSM,     GUI_OSM,    KC_K,    KC_H,    KC_T,    KC_N,    KC_S,     KC_Q,
      XXXXXXX, KC_QUOT, KC_MINS,  KC_EQL,  KC_DOT, KC_SCLN,                          KC_J,    KC_M,    KC_G,    KC_P,    KC_F,    TG(1),
                                 HYP_OSM, TL_UPPR, TL_LOWR,                       TD_RBKS,  KC_SPC, KC_RSFT
  ),

};
