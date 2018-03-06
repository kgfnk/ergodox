#include QMK_KEYBOARD_CONFIG_H

#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped this number of times again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
