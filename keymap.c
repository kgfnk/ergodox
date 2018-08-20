#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include <sendstring_colemak.h>

#define EUCALYN 0 // eucalyn
#define QWERTY 1 // qwerty layer
#define VIM 2 // vim
#define SYMB 3 // symbols
#define MOUS 4 // mouse
#define FUNC1 5 // function1
#define FUNC2 6 // function2

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum {
    M_RSFT,
    M_00,
    M_000,
    M_0000,
    M_DBQUOT,
    M_BKQUOT,
    M_QUOT,
    M_CBR,
    M_PRN,
    M_BRC,
    M_TAG,
    M_MINS
};

enum custom_keycodes {
    M_ESC = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Eucalyn layer
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | VIM    | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |      |           |      | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |  \ |   |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | TAB    | ? /  | < ,  | > .  |   F  |   Q  |  ~   |           |      |   M  |   R  |   D  |   Y  |   P  |  + =   |
 * |--------+------+------+------+------+------|  `   |           |      |------+------+------+------+------+--------|
 * | ⌃      |   A  |   O  |   E  |   I  |   U  |------|           |------|   G  |   T  |   K  |   S  |   N  |  " '   |
 * |--------+------+------+------+------+------|  {   |           |  }   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   W  |  [   |           |  ]   |   B  |   H  |   J  |   L  | : ;  |  - _   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L2  | ~FN1 |GuiAlt| Alt  |  Gui |                                       |  Gui | ESC  |      |      |  FN0 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | F12  |       |Qwerty| PrtSc  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Space/| Tab/ |------|       |------|  Back  |Enter |
 *                                 | VIM  | SYMB | End  |       | PgDn |  Space |      |
 *                                 `--------------------'       `----------------------'
 */
[EUCALYN] = LAYOUT_ergodox(  // layer 4 : eucalyn
        // left hand
        DF(VIM),      KC_1,    KC_2,        KC_3,       KC_4,              KC_5,    XXXXXXX,
        KC_TAB,       KC_SLSH, KC_COMM,     KC_DOT,     KC_F,              KC_Q,    KC_GRV,
        CTL_T(KC_NO), KC_A,    KC_O,        KC_E,       KC_I,              KC_U,
        KC_LSFT,      KC_Z,    KC_X,        KC_C,       KC_V,              KC_W,    KC_LBRC,
        MO(MOUS),     KC_FN1,  LGUI(KC_LALT),KC_LALT,    GUI_T(KC_LANG2),
// -----
                                                        KC_APP,            KC_F12,
                                                                           KC_HOME,
                                     LT(VIM, KC_SPC),   LT(SYMB, KC_TAB),  KC_END,
// -----
        // right hand
        XXXXXXX,      KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSLS,
        XXXXXXX,      KC_M,    KC_R,    KC_D,     KC_Y,    KC_P,     KC_EQL,
                      KC_G,    KC_T,    KC_K,     KC_S,    KC_N,     KC_QUOT,
        KC_RBRC,      KC_B,    KC_H,    KC_J,     KC_L,    KC_SCLN,  KC_MINS,
                               GUI_T(KC_LANG1),   M_ESC,   XXXXXXX,  XXXXXXX,  KC_FN0,
// -----
        DF(QWERTY),   KC_PSCREEN,
        KC_PGUP,
        KC_PGDN,      LT(FUNC1, KC_BSPC),  LT(FUNC2, KC_ENT)
),
/* Keymap qwerty layer
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  VIM   | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |      |           |      | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |  \ |   |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | ~ `  |           |      |   Y  |   U  |   I  |   O  |   P  |  = +   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctl    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ; :  |  " '   |
 * |--------+------+------+------+------+------| - _  |           | = +  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  | , <  |  . > |  / ? |  - _   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L2  | ~FN1 |      | Alt  |  Gui |                                       |  Gui | Esc  |  [ { |  ] } |  FN0 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  |  F12 |       |Eucaly| PrtSc  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Space/| Tab/ |------|       |------|  Back  |Enter |
 *                                 |VIM   | SYMB | End  |       | PgDn |  Space |      |
 *                                 `--------------------'       `----------------------'
 */
[QWERTY] = LAYOUT_ergodox(
        // left hand
        DF(VIM),      KC_1,    KC_2,        KC_3,       KC_4,              KC_5,    ALL_T(KC_NO),
        KC_TAB,       KC_Q,    KC_W,        KC_E,       KC_R,              KC_T,    KC_GRV,
        CTL_T(KC_NO), KC_A,    KC_S,        KC_D,       KC_F,              KC_G,
        KC_LSFT,      KC_Z,    KC_X,        KC_C,       KC_V,              KC_B,    KC_MINS,
        MO(MOUS),     KC_FN1,  XXXXXXX,     KC_LALT,    GUI_T(KC_LANG2),
// -----
                                                  KC_APP,            KC_F12,
                                                                     KC_HOME,
                               LT(VIM, KC_SPC),   LT(SYMB, KC_TAB),  KC_END,
// -----
        // right hand
        XXXXXXX,      KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSLS,
        XXXXXXX,      KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_EQL,
                      KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_EQL,       KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_MINS,
                               GUI_T(KC_LANG1),   M_ESC,   KC_LBRC,  KC_RBRC,  KC_FN0,
// -----
        DF(EUCALYN),  XXXXXXX,
        KC_PGUP,
        KC_PGDN,      LT(FUNC1, KC_BSPC),  LT(FUNC2, KC_ENT)
    ),
/* Keymap 1: Vim Nomal Mode
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |      |      |      |  $   |      |      |           |      |  ^   |      |      |      |  0   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Word | End  | Redo |NTab  |      |           |      | Copy | Undo | L0   | L0   |Paste |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | L0   |Search| Cut  | PgDn | Home |------|           |------| Left | Down | Up   |Right |Alfred|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Del  |      |Select| PgUp |      |           |      |      | Menu |      |      | Find |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|Del   |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Vim Mode
[VIM] = LAYOUT_ergodox(
       KC_ESC,   XXXXXXX,   XXXXXXX,           XXXXXXX,     LCTL(KC_E),            XXXXXXX,    XXXXXXX,
       _______,  XXXXXXX,   LALT(KC_RIGHT),    KC_END,      LGUI(LSFT(KC_Z)),      LGUI(KC_T), _______,
       _______,  DF(QWERTY),LGUI(LALT(KC_F)),  LGUI(KC_X),  KC_PGDN,               KC_HOME,
       _______,  _______,   KC_DELT,           _______,     LALT(LSFT(KC_RIGHT)),  KC_PGUP,    _______,
       _______,  _______,   _______,           _______,     _______,
// -----
                                               _______,     _______,
                                                            _______,
                                   _______,    _______,     _______,
// -----
    // right hand
       XXXXXXX,  LCTL(KC_A), XXXXXXX,    XXXXXXX,    XXXXXXX,    LCTL(KC_A),    _______,
       _______,  LGUI(KC_C), LGUI(KC_Z), DF(QWERTY), DF(QWERTY), LGUI(KC_V),    _______,
                 KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   LALT(KC_SPC),  _______,
       _______,  _______,    LCTL(KC_F2),_______,    _______,    LGUI(KC_F),    _______,
                             _______,    _______,    _______,    _______,       KC_FN2,
// -----
       _______,  OSL(QWERTY),
       _______,
       _______,  KC_DELT, _______
),
/* Keymap 2: 10key Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |   *    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | ```  |  ''  |  {}  |      |      |           |  -   | 0000 |   7  |   8  |   9  |  -   |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | ---  |  ""  |  ()  |  <>  |------|           |------| 000  |   4  |   5  |   6  |  +   |   +    |
 * |--------+------+------+------+------+------|      |           |  +   |------+------+------+------+------+--------|
 * |        |      |      |      |  []  |      |      |           |      | 00   |   1  |   2  |   3  |  /   |   /    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   ,  |   .  |  =   |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| BS   |  =   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       _______,  KC_F1,    KC_F2,       KC_F3,       KC_F4,    KC_F5,    KC_F11,
       _______,  XXXXXXX,  M(M_BKQUOT), M(M_QUOT),   M(M_CBR), XXXXXXX,  XXXXXXX,
       _______,  XXXXXXX,  M(M_MINS),   M(M_DBQUOT), M(M_PRN), M(M_TAG),
       _______,  XXXXXXX,  XXXXXXX,     XXXXXXX,     M(M_BRC), XXXXXXX,  XXXXXXX,
       _______,  _______,  _______,     _______,     _______,
                                                               _______,  _______,
                                                                         _______,
                                                     _______,  _______,  _______,
       // right hand
       KC_F12,   KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_ASTR,
       KC_MINS,  M(M_0000), KC_7,     KC_8,     KC_9,     KC_MINS,   KC_MINS,
                 M(M_000),  KC_4,     KC_5,     KC_6,     KC_PLUS,   KC_PLUS,
       KC_PLUS,  M(M_00),   KC_1,     KC_2,     KC_3,     KC_SLSH,   KC_SLSH,
                            KC_0,     KC_COMM,  KC_DOT,   KC_EQL,    _______,
       _______,  _______,
       _______,
       _______,  KC_BSPC,   KC_EQL
),
/* Keymap 3: mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Power  |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | RESET  |  F6  |  F7  |  F8  |  F9  |  F10 |      |           |      |      |      | MsUp |      |      | Play   |
 * |--------+------+------+------+------+------|MsWhU |           |MsWhD |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|      |MsLeft|MsDown|MsRght|      | Next   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | ACL2 | ACL1 | ACL0 |      |MsWhL |           |MsWhR |      |      |      |      |      | Prev   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Lclk | Rclk | BTN3 | BTN4 | BTN5 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Mute |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |VolUp |      |      |
 *                                 |MsWhU |MsWhL |------|       |------|MsWhR |MsWhD |
 *                                 |      |      |      |       |VolDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Mouse
[MOUS] = LAYOUT_ergodox(
       KC_POWER,KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F11,
       RESET,   KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_WH_U,
       _______, KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,
       _______, XXXXXXX, KC_ACL2,  KC_ACL1,  KC_ACL0,  XXXXXXX, KC_WH_L,
       _______, _______, _______,  _______,  _______,
                                             _______,  _______,
                                                       _______,
                                   KC_WH_U,  KC_WH_L,  _______,
    // right handa
       _______,  _______, _______, _______, _______, _______, XXXXXXX,
       KC_WH_D,  XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, KC_MPLY,
                 XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_MNXT,
       KC_WH_R,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,
                          KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5,
       KC_MUTE,  _______,
       KC_VOLU,
       KC_VOLD,  KC_WH_R, KC_WH_D
),
/* Keymap 5: function
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |  6   |  7   |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+------|  F11 |           |  F13 |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|      |      |      |      |      |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |           |  F14 |      |      |      |      |      |   '    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// function1
[FUNC1] = LAYOUT_ergodox(
       _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
       _______, KC_1,    KC_2,     KC_3,     KC_4,     KC_5,    KC_F11,
       _______, KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,
       _______, KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F12,
       _______, _______, _______,  _______,  _______,
                                             _______,  _______,
                                                       _______,
                                   _______,  _______,  _______,
    // right handa
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS,
       KC_F13,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,
       KC_F14,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT,
                          _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,
       _______,  _______,
       _______,
       _______,  _______, _______
),
/* Keymap 6: function2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |   <  |   >  |   |    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |------|           |------|   ^  |   &  |   *  |   (  |   )  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |   {  |   }  |   +    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |   [  |   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// function2
[FUNC2] = LAYOUT_ergodox(
       _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
       _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
       _______, KC_EXLM, KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,
       _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
       _______, _______, _______,  _______,  _______,
                                             _______,  _______,
                                                       _______,
                                   _______,  _______,  _______,
    // right handa
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_PIPE,
                 KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_QUOT,
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_PLUS,
                          _______, _______, KC_LBRC, KC_RBRC, XXXXXXX,
       _______,  _______,
       _______,
       _______,  _______, _______
),
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(QWERTY),
    [1] = ACTION_LAYER_TAP_TOGGLE(MOUS),                // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_MOMENTARY(QWERTY)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case M_ESC:
                SEND_STRING(SS_TAP(X_ESCAPE));
                SEND_STRING(SS_TAP(X_LANG2));
                return false;
                break;
        }
    }
    return true;
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case M_RSFT:
            if (record->event.pressed) {
              register_code(KC_RSFT);
            } else {
              unregister_code(KC_RSFT);
            }
            break;
        case M_00:
            if (record->event.pressed) {
                return MACRO( I(25), T(P0), T(P0), END );
            }
            break;
        case M_000:
            if (record->event.pressed) {
                return MACRO( I(25), T(P0), T(P0), T(P0), END );
            }
            break;
        case M_0000:
            if (record->event.pressed) {
                return MACRO( I(25), T(P0), T(P0), T(P0), T(P0), END );
            }
            break;
        case M_DBQUOT:
            if (record->event.pressed) {
                SEND_STRING("\"\"");
                register_code(KC_LEFT);
                unregister_code(KC_LEFT);
            }
            break;
        case M_QUOT:
            if (record->event.pressed) {
                SEND_STRING("''");
                register_code(KC_LEFT);
                unregister_code(KC_LEFT);
            }
            break;
        case M_CBR:
            if (record->event.pressed) {
                SEND_STRING("{}");
                register_code(KC_LEFT);
                unregister_code(KC_LEFT);
            }
            break;
        case M_PRN:
            if (record->event.pressed) {
                SEND_STRING("()");
                register_code(KC_LEFT);
                unregister_code(KC_LEFT);
            }
            break;
        case M_BRC:
            if (record->event.pressed) {
                SEND_STRING("[]");
                register_code(KC_LEFT);
                unregister_code(KC_LEFT);
            }
            break;
        case M_TAG:
            if (record->event.pressed) {
                SEND_STRING("<>");
                register_code(KC_LEFT);
                unregister_code(KC_LEFT);
            }
            break;
        case M_BKQUOT:
            if (record->event.pressed) {
                SEND_STRING("```");
            }
            break;
        case M_MINS:
            if (record->event.pressed) {
                SEND_STRING("---");
            }
            break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
