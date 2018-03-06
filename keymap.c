#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include <sendstring_colemak.h>

#define BASE 0 // default layer
#define VIM 1 // vim
#define SYMB 2 // symbols
#define MOUS 3 // mouse

#define _______ KC_TRNS

enum {
    M_RSFT,
    M_00,
    M_000,
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
/* Keymap 0: base layer
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  L1    | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |      |           |      | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  | PrtSc  |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  ~`  |           |      |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctl    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ; :  |  " '   |
 * |--------+------+------+------+------+------| - _  |           | = +  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  | , <  |  . > |  / ? | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L2  | ~FN1 |      | Alt  |  Gui |                                       |  Gui | Esc  |  [ { |  ] } |  FN0 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Space/| Tab/ |------|       |------|  Back  |Enter |
 *                                 |L1    | L2   | End  |       | PgDn |  Space |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        DF(VIM),      KC_1,    KC_2,        KC_3,       KC_4,              KC_5,    ALL_T(KC_NO),
        KC_TAB,       KC_Q,    KC_W,        KC_E,       KC_R,              KC_T,    KC_GRV,
        CTL_T(KC_NO), KC_A,    KC_S,        KC_D,       KC_F,              KC_G,
        KC_LSFT,      KC_Z,    KC_X,        KC_C,       KC_V,              KC_B,    KC_MINS,
        MO(MOUS),     KC_FN1,  KC_NO,       KC_LALT,    GUI_T(KC_LANG2),
// -----
                                                  ALT_T(KC_APP),     KC_NO,
                                                                     KC_HOME,
                               LT(VIM, KC_SPC),   LT(SYMB, KC_TAB),  KC_END,
// -----
        // right hand
        KC_NO,        KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_PSCREEN,
        KC_NO,        KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_BSLS,
                      KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_EQL,       KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
                               GUI_T(KC_LANG1),   M_ESC,   KC_LBRC,  KC_RBRC,  KC_FN0,
// -----
        KC_NO,        KC_NO,
        KC_PGUP,
        KC_PGDN,      KC_BSPC,  KC_ENT
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
 *   | ~L2  |      |      |      |      |                                       |      |      |      |      |      |
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
       KC_ESC,   KC_NO,     KC_NO,             KC_NO,       LCTL(KC_E),            KC_NO,      KC_NO,
       _______,  _______,   LALT(KC_RIGHT),    KC_END,      LGUI(LSFT(KC_Z)),      LGUI(KC_T), _______,
       _______,  DF(BASE),  LGUI(LALT(KC_F)),  LGUI(KC_X),  KC_PGDN,               KC_HOME,
       _______,  _______,   KC_DELT,           _______,     LALT(LSFT(KC_RIGHT)),  KC_PGUP,    _______,
       MO(VIM),  _______,   _______,           _______,     _______,
// -----
                                               _______,     _______,
                                                            _______,
                                   _______,    _______,     _______,
// -----
    // right hand
       KC_NO,    LCTL(KC_A), KC_NO,      KC_NO,    KC_NO,     LCTL(KC_A),  _______,
       _______,  LGUI(KC_C), LGUI(KC_Z), DF(BASE), DF(BASE),  LGUI(KC_V),  _______,
                 KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,  LALT(KC_SPC),_______,
       _______,  _______,    LCTL(KC_F2),_______,  _______,   LGUI(KC_F),  _______,
                             _______,    _______,  _______,   _______,     KC_FN2,
// -----
       _______,  OSL(BASE),
       _______,
       _______,  KC_DELT, _______
),
/* Keymap 2: 10key Symbol Layer
 * 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |   /    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | ```  |  ''  |  {}  |      |  /   |           |  -   |      |   7  |   8  |   9  |      |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | ---  |  ""  |  ()  |  <>  |------|           |------| 000  |   4  |   5  |   6  |      |   +    |
 * |--------+------+------+------+------+------|  *   |           |  +   |------+------+------+------+------+--------|
 * |        |      |      |      |  []  |      |      |           |      | 00   |   1  |   2  |   3  |  /   |   *    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |      |   .  |  ,   |      |
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
       _______,  _______,  M(M_BKQUOT), M(M_QUOT),   M(M_CBR), _______,  _______,
       _______,  _______,  M(M_MINS),   M(M_DBQUOT), M(M_PRN), M(M_TAG),
       _______,  _______,  _______,     _______,     M(M_BRC), _______,  _______,
       _______,  _______,  _______,     _______,     _______,
                                                               _______,  _______,
                                                                         _______,
                                                     _______,  _______,  _______,
       // right hand
       KC_F12,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_SLSH,
       _______,  _______,  KC_7,     KC_8,     KC_9,     _______,   KC_MINS,
                 M(M_000), KC_4,     KC_5,     KC_6,     _______,   KC_PLUS,
       _______,  M(M_00),  KC_1,     KC_2,     KC_3,     _______,   KC_ASTR,
                           KC_0,     KC_NO,    KC_DOT,   KC_COMM,   _______,
       _______,  _______,
       _______,
       _______,  KC_BSPC,  KC_EQL
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
       _______, KC_NO,   KC_ACL2,  KC_ACL1,  KC_ACL0,  KC_NO,   KC_WH_L,
       _______, _______, _______,  _______,  _______,
                                             _______,  _______,
                                                       _______,
                                   KC_WH_U,  KC_WH_L,  _______,
    // right handa
       _______,  _______, _______, _______, _______, _______, _______,
       KC_WH_D,  _______, _______, KC_MS_U, _______, _______, KC_MPLY,
                 _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_MNXT,
       KC_WH_R,  _______, _______, _______, _______, _______, KC_MPRV,
                          KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5,
       KC_MUTE,  _______,
       KC_VOLU,
       KC_VOLD,  KC_WH_R, KC_WH_D
),
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(BASE),
    [1] = ACTION_LAYER_TAP_TOGGLE(MOUS),                // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_MOMENTARY(BASE)
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
