// @sdk66, @iamdanielv & @irfanjmdn
// ^ original firmware authors ^
// Royal Kludge R65 Wired version -- Plug N Play functionality for Croatian layout PCs
// Author: Ljupko Kolak
// Based on the VIA keymap by @irfanjmdn from https://github.com/irfanjmdn/r65

// Allows you to use the Royal Kludge R65 Wired keyboard with a US QWERTY layout on a computer with a Croatian QWERTZ layout,
// and still output US QWERTY characters using the standard keys.

#include QMK_KEYBOARD_H
#include "layoutmap_us_to_hr.h" // includes the Layout Map to convert the custom keycodes used on the PNP layer (0) to Croatian QWERTZ keys/ key cominations.

#define LED_REGULAR_PIN LED_MAC_PIN // renames the old Mac Mode pin to improve code clarity. The LED functions the same, but now indicates that the regular, non-PNP layer (2) is used.

enum layer_names {
    _PNP,           // 0 Plug N Play layer. Hold the FN key to access the PNP Functions layer (1).
    _PNP_FN,        // 1 Plug N play Functions layer. Default functions + ability to use S, D, Z, X, or C to get Š, Đ, Ž, Č, and Ć. Press the rotary encoder wheel to switch to the Regular layer (2).
    _REGULAR,       // 2 Regular layer (repurposed _MAC layer). Always outputs Croatian QWERTZ characters. Hold the FN key to access the Regular Functions layer (3).
    _REGULAR_FN,    // 3 Regular Functions layer. Default functions. Press the rotary encoder wheel to switch to the Plug N Play layer (1).
    _ALT_A,         // 4 ... other layers and functionality unchanged.
    _ALT_A_FN,      // 5
    _ALT_B,         // 6
    _ALT_B_FN,      // 7
    _BOOT           // 8
};

enum custom_keycodes {
    SWITCH_FN = SAFE_RANGE
};

bool fn_mode = false;

const uint16_t number_to_function[] PROGMEM = {
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool is_shifted = get_mods() & MOD_MASK_SHIFT;
    bool is_pressed = record->event.pressed;

    // Handle SWITCH_FN
    if (keycode == SWITCH_FN && is_pressed) {
        fn_mode = !fn_mode;
        return false;
    }

    // Handle shifted keycodes for Croatian layout, only on _PNP layer (0)
    if (IS_LAYER_ON(_PNP) && is_shifted && is_pressed) {
        uint8_t saved_mods = get_mods(); // stores the current modifier keys (like the Shift keys) so they can be disabled and re-enabled when sending custom keypresses.
        switch (keycode) {
            case US2HR_2: // Shift+2 = @
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)); // disables the Left and Right Shift keys.
                tap_code16(US2HR_AT); // sends the custom keycode mapping the user's Shift+2 keypress to AltGr+V, resulting in a @ on a Croatian QWERTZ layout.
                set_mods(saved_mods); // restores the Shift keys previous state.
                return false;
            case US2HR_6: // Shift+6 = ^
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_CIRC);
                set_mods(saved_mods);
                return false;
            case US2HR_7: // Shift+7 = &
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_AMPR);
                set_mods(saved_mods);
                return false;
            case US2HR_8: // Shift+8 = *
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_ASTR);
                set_mods(saved_mods);
                return false;
            case US2HR_9: // Shift+9 = (
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_LPRN);
                set_mods(saved_mods);
                return false;
            case US2HR_0: // Shift+0 = )
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_RPRN);
                set_mods(saved_mods);
                return false;
            case US2HR_EQL: // Shift+= = +
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_PLUS);
                set_mods(saved_mods);
                return false;
            case US2HR_LBRC: // Shift+[ = {
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_LCBR);
                set_mods(saved_mods);
                return false;
            case US2HR_RBRC: // Shift+] = }
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_RCBR);
                set_mods(saved_mods);
                return false;
            case US2HR_BSLS: // Shift+\ = |
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_PIPE);
                set_mods(saved_mods);
                return false;
            case US2HR_SCLN: // Shift+; = :
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_COLN);
                set_mods(saved_mods);
                return false;
            case US2HR_QUOT: // Shift+' = "
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_DQUO);
                set_mods(saved_mods);
                return false;
            case US2HR_COMM: // Shift+, = <
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_LABK);
                set_mods(saved_mods);
                return false;
            case US2HR_DOT: // Shift+. = >
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_RABK);
                set_mods(saved_mods);
                return false;
            case US2HR_SLSH: // Shift+'/ = ?
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US2HR_QUES);
                set_mods(saved_mods);
                return false;
        }
    }

    // Handle fn_mode for number row to function keys
    if (fn_mode) {
        if ((keycode >= KC_1 && keycode <= KC_0) || keycode == KC_MINS || keycode == KC_EQL) {
            uint8_t index = keycode - KC_1;
            if (keycode == KC_MINS) { index = 10; }
            else if (keycode == KC_EQL) { index = 11; }
            if (is_pressed) {
                register_code(pgm_read_word(&number_to_function[index]));
            } else {
                unregister_code(pgm_read_word(&number_to_function[index]));
            }
            return false;
        }
    }

    return true;
}

void housekeeping_task_user(void) {
    if (IS_LAYER_ON(_REGULAR) || IS_LAYER_ON(_REGULAR_FN)) {
        gpio_write_pin_low(LED_REGULAR_PIN);
    } else {
        gpio_write_pin_high(LED_REGULAR_PIN);
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_PNP] = LAYOUT(
    KC_ESC,  US2HR_1, US2HR_2, US2HR_3, US2HR_4, US2HR_5, US2HR_6, US2HR_7, US2HR_8, US2HR_9, US2HR_0, US2HR_MINS, US2HR_EQL, KC_BSPC, KC_MUTE,
    KC_TAB,  US2HR_Q, US2HR_W, US2HR_E, US2HR_R, US2HR_T, US2HR_Y, US2HR_U, US2HR_I, US2HR_O, US2HR_P, US2HR_LBRC, US2HR_RBRC, US2HR_BSLS, KC_DEL,
    KC_CAPS, US2HR_A, US2HR_S, US2HR_D, US2HR_F, US2HR_G, US2HR_H, US2HR_J, US2HR_K, US2HR_L, US2HR_SCLN, US2HR_QUOT,          KC_ENT,  KC_PGUP,
    KC_LSFT, US2HR_Z, US2HR_X, US2HR_C, US2HR_V, US2HR_B, US2HR_N, US2HR_M, US2HR_COMM, US2HR_DOT, US2HR_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(1),            KC_LEFT, KC_DOWN, KC_RGHT
),

[_PNP_FN] = LAYOUT(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, TO(2),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(8), _______, KC_HOME, KC_SCRL, RGB_MOD, KC_INS,
    _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, MO(8), _______, KC_PSCR, _______, KC_PAUSE,
    _______, KC_BSLS, KC_SCLN, KC_QUOT, _______, NK_TOGG, _______, _______, RGB_HUI, _______, _______, MO(8), RGB_VAI, KC_END,
    SWITCH_FN, GU_TOGG, _______, EE_CLR, _______, _______, RGB_SPD, RGB_VAD, RGB_SPI
),

[_REGULAR] = LAYOUT(
 KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MUTE,
 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
 KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, 
 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
 KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(3), KC_LEFT, KC_DOWN, KC_RGHT
 ),

[_REGULAR_FN] = LAYOUT(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, TO(0),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(8), _______, KC_HOME, KC_SCRL, RGB_MOD, KC_INS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(8), _______, KC_PSCR, _______, KC_PAUSE,
    _______, _______, _______, _______, _______, NK_TOGG, _______, _______, RGB_HUI, _______, _______, MO(8), RGB_VAI, KC_END,
    SWITCH_FN, _______, _______, EE_CLR, _______, _______, RGB_SPD, RGB_VAD, RGB_SPI
),

[_ALT_A] = LAYOUT(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MUTE,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(5), KC_LEFT, KC_DOWN, KC_RGHT
),

[_ALT_A_FN] = LAYOUT(
    KC_GRV, KC_MYCM, KC_HOME, KC_MAIL, KC_CALC, KC_SLCT, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(8), _______, KC_HOME, KC_SCRL, RGB_MOD, KC_INS,
    _______, TO(4), TO(6), _______, _______, _______, _______, _______, _______, MO(8), _______, KC_PSCR, _______, KC_PAUSE,
    _______, _______, _______, _______, _______, NK_TOGG, _______, _______, RGB_HUI, _______, _______, MO(8), RGB_VAI, KC_END,
    SWITCH_FN, GU_TOGG, _______, EE_CLR, _______, _______, RGB_SPD, RGB_VAD, RGB_SPI
),

[_ALT_B] = LAYOUT(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MUTE,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(7), KC_LEFT, KC_DOWN, KC_RGHT
),

[_ALT_B_FN] = LAYOUT(
    KC_GRV, KC_BRMD, KC_BRMU, KC_F3, KC_F4, KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(8), _______, KC_HOME, KC_SCRL, RGB_MOD, KC_INS,
    _______, TO(4), TO(6), _______, _______, _______, _______, _______, _______, MO(8), _______, KC_PSCR, _______, KC_PAUSE,
    _______, _______, _______, _______, _______, NK_TOGG, _______, _______, RGB_HUI, _______, _______, MO(8), RGB_VAI, KC_END,
    SWITCH_FN, _______, _______, EE_CLR, _______, _______, RGB_SPD, RGB_VAD, RGB_SPI
),

[_BOOT] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_PNP]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_PNP_FN]  = {ENCODER_CCW_CW(_______, _______)},
    [_REGULAR]      = {ENCODER_CCW_CW(_______, _______)},
    [_REGULAR_FN]   = {ENCODER_CCW_CW(_______, _______)},
    [_ALT_A]    = {ENCODER_CCW_CW(_______, _______)},
    [_ALT_A_FN] = {ENCODER_CCW_CW(_______, _______)},
    [_ALT_B]    = {ENCODER_CCW_CW(_______, _______)},
    [_ALT_B_FN] = {ENCODER_CCW_CW(_______, _______)},
    [_BOOT]     = {ENCODER_CCW_CW(_______, _______)}
};
#endif
