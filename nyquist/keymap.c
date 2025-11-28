#include QMK_KEYBOARD_H

enum planck_keycodes {
  ST_MACRO_0 = SAFE_RANGE,
  ST_MACRO_1,
};

#define KC_SCR_SHOT LCTL(LSFT(KC_PSCR))

enum planck_layers {
  _BASE,
  _SYMBOL,
  _NUMPAD,
  _CONTROL,
  _GAME,
  _ARROW,
  _MOUSE,
  _FUNCTION,
  _WINDOW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x12(
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOTE,       KC_BSPC,
    KC_MINUS,       KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_SCLN,
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       MO(_ARROW),
    KC_ESCAPE,      TO(_GAME),      KC_LEFT_ALT,    KC_LEFT_CTRL,   OSL(_SYMBOL),   KC_SPACE,       KC_SPACE,       OSL(_NUMPAD),   KC_LEFT_GUI,    ST_MACRO_0,     ST_MACRO_1,     KC_ENTER
  ),

  [_SYMBOL] = LAYOUT_ortho_4x12(
    KC_SCR_SHOT,    KC_GRAVE,       KC_TRANSPARENT, KC_PIPE,        KC_ASTR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLS,        KC_CIRC,        KC_TRANSPARENT, KC_DQUO,        KC_TRANSPARENT,
    KC_UNDS,        KC_AT,          KC_AMPR,        KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        KC_LPRN,        KC_RPRN,        KC_EQUAL,       KC_PLUS,        KC_COLN,
    KC_TRANSPARENT, KC_TILD,        KC_EXLM,        KC_PERC,        KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_HASH,        KC_LABK,        KC_RABK,        KC_QUES,        KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(_CONTROL),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_NUMPAD] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_DOT,         MO(_FUNCTION),
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, MO(_CONTROL),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_CONTROL] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,      KC_AUDIO_VOL_UP,   KC_MEDIA_PLAY_PAUSE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT,      KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_GAME] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_TILD,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_P,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSL(_FUNCTION), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_ARROW] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_PLUS,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MINUS,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, MO(_WINDOW),    KC_TRANSPARENT, KC_TRANSPARENT, MO(_MOUSE),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_MOUSE] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, QK_MOUSE_WHEEL_UP,   QK_MOUSE_BUTTON_2,    QK_MOUSE_CURSOR_UP,   QK_MOUSE_BUTTON_1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, QK_MOUSE_WHEEL_DOWN, QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_DOWN, QK_MOUSE_CURSOR_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,       KC_TRANSPARENT,       KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),           KC_TRANSPARENT,       KC_TRANSPARENT,       KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_FUNCTION] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F12,         KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_WINDOW] = LAYOUT_ortho_4x12(
    KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(KC_UP)), LGUI(KC_UP),    LALT(LCTL(KC_DOWN)), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_LEFT),     LGUI(KC_DOWN),  LGUI(KC_RIGHT),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_LEFT))));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_RIGHT))));
    }
    break;
  }
  static int one_shot_layer = -1;
  if ((keycode & QK_ONE_SHOT_LAYER) == QK_ONE_SHOT_LAYER) {
    if (record->event.pressed) {
      one_shot_layer = QK_ONE_SHOT_LAYER_GET_LAYER(keycode);
    }
  } else if (one_shot_layer != -1) {
    bool delay_unregister = IS_QK_BASIC(keycode) || IS_QK_MODS(keycode);
    if (record->event.pressed) {
      if (delay_unregister) {
        register_code16(keycode);
        return false;
      }
    } else {
      one_shot_layer = -1;
      if (delay_unregister) {
        unregister_code16(keycode);
        return false;
      }
    }
  }
  return true;
}

void keyboard_post_init_user(void) {
  rgb_matrix_mode_noeeprom(0);
  rgb_matrix_enable_noeeprom();
  rgb_matrix_set_color_all(0, 0, 0);
}

bool rgb_matrix_indicators_user(void) {
  rgb_matrix_set_color_all(0, 0, 0);
  uint8_t row = 0;
  uint8_t col = 0;
  switch (get_highest_layer(layer_state)) {
    case _SYMBOL:
      row = 1;
      col = 3;
      break;
    case _NUMPAD:
      row = 6;
      col = 1;
      break;
    case _CONTROL:
      row = 2;
      col = 3;
      break;
    case _GAME:
      row = 1;
      col = 5;
      break;
    case _ARROW:
      row = 1;
      col = 1;
      break;
    case _MOUSE:
      row = 6;
      col = 0;
      break;
    case _FUNCTION:
      row = 0;
      col = 3;
      break;
    case _WINDOW:
      row = 0;
      col = 2;
      break;
    default:
      return true;
  }
  uint8_t index = g_led_config.matrix_co[row][col];
  static const uint8_t rgb_matrix_split[2] = RGB_MATRIX_SPLIT;
  if (is_keyboard_left() == (index < rgb_matrix_split[0])) // TODO: figure out why this is needed...
  {
    rgb_matrix_set_color(index, 0xff, 0xff, 0xff);
  }
  return true;
}
