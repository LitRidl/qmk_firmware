#include QMK_KEYBOARD_H

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

enum combos {
    JK_ESC,
    SD_ESC,
    GB_TAB,
    MCOMMA_ENT,
    COMMADOT_SENT,
    HN_MINUS,
    JM_EQUAL,
    DF_LPAR,
    FG_RPAR,
    CV_LCBR,
    VB_RCBR,
    ER_LBRC,
    RT_RBRC,
    SEMISLASH_BSLS,
    // OSL12_3,
    // BOSL2_MEH,
    COMBO_LENGTH
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM gb_combo[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM mcomma_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM commadot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM hn_combo[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM jm_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM semislash_combo[] = {KC_SCLN, KC_SLSH, COMBO_END};
// const uint16_t PROGMEM osl12_combo[] = {OSL(1), OSL(2), COMBO_END};
// const uint16_t PROGMEM bosl2_combo[] = {KC_B, OSL(2), COMBO_END};

combo_t key_combos[] = {
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
    [SD_ESC] = COMBO(sd_combo, KC_ESC),
    [GB_TAB] = COMBO(gb_combo, KC_TAB),
    [MCOMMA_ENT] = COMBO(mcomma_combo, KC_ENT),
    [COMMADOT_SENT] = COMBO(commadot_combo, S(KC_ENT)),
    [HN_MINUS] = COMBO(hn_combo, KC_MINS),
    [JM_EQUAL] = COMBO(jm_combo, KC_EQL),
    [DF_LPAR] = COMBO(df_combo, KC_LEFT_PAREN),     // (
    [FG_RPAR] = COMBO(fg_combo, KC_RIGHT_PAREN),     // )
    [CV_LCBR] = COMBO(cv_combo, KC_LEFT_CURLY_BRACE),  // {
    [VB_RCBR] = COMBO(vb_combo, KC_RIGHT_CURLY_BRACE),  // }
    [ER_LBRC] = COMBO(er_combo, KC_LBRC),     // [
    [RT_RBRC] = COMBO(rt_combo, KC_RBRC),     // ]
    [SEMISLASH_BSLS] = COMBO(semislash_combo, KC_BSLS),
    // [OSL12_3] = COMBO(osl12_combo, OSL(3)),
    // [BOSL2_MEH] = COMBO(bosl2_combo, OSM(MOD_MEH)),
};
