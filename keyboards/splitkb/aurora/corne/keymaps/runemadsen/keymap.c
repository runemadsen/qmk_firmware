#include QMK_KEYBOARD_H
// Compile:
// qmk compile -e CONVERT_TO=promicro_rp2040 -kb splitkb/aurora/corne -km runemadsen
//
// Compile + Flash
// qmk flash -e CONVERT_TO=promicro_rp2040 -kb splitkb/aurora/corne -km runemadsen

enum layers {
    BASE,
    RAISE,
    LOWER
};

enum macros {
    CYCL_APP = SAFE_RANGE,
    ZOOM_IN,
    ZOOM_OUT,
    SCRNSHOT,
    FIGMA_UI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.    
        KC_LALT,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,                          KC_Y,    KC_U,    KC_I,   KC_O,     KC_P,  XXXXXXX, 
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|  
        KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                          KC_H,    KC_J,    KC_K,   KC_L,    KC_SCLN, KC_QUOT, 
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|      
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                          KC_N,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH, KC_ESC, 
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|    
                                    KC_LCMD,  LT(1, KC_BSPC),  MO(2),    LT(2, KC_ENT),  LT(1, KC_SPC),  KC_RCTL
	                                //`------------------------------'  `------------------------------'
    ),
    
    [RAISE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.        
       XXXXXXX,  KC_EXLM,  KC_AT, KC_HASH, KC_DLR,  KC_PERC,                      XXXXXXX, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, XXXXXXX, 
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|      
       CYCL_APP, KC_AMPR, KC_PLUS, KC_MINUS, KC_UNDS, KC_GRV,                    XXXXXXX, KC_LEFT,  KC_UP,  KC_DOWN, KC_RIGHT, XXXXXXX, 
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|        
       XXXXXXX, XXXXXXX, KC_ASTR, KC_CIRC, KC_PIPE, XXXXXXX,                      XXXXXXX, KC_LBRC, KC_RBRC,  KC_EQL,  KC_BSLS, XXXXXXX, 
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|   
                                           XXXXXXX, _______, _______,     _______, _______, XXXXXXX
                                        //`--------------------------'  `--------------------------'   
    ),

	[LOWER] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.            
        XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,                      XXXXXXX,  KC_P7,  KC_P8,   KC_P9,  KC_PMNS, XXXXXXX, 
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|      
        XXXXXXX, FIGMA_UI, SCRNSHOT, ZOOM_OUT, ZOOM_IN, XXXXXXX,          XXXXXXX,  KC_P4,  KC_P5,   KC_P6,  KC_PPLS, XXXXXXX, 
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|          
        XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                      XXXXXXX,  KC_P1,  KC_P2,   KC_P3,  KC_PEQL, XXXXXXX, 
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|    
                                           XXXXXXX, _______, _______,      _______, _______, KC_P0
                                        //`--------------------------'  `--------------------------'    
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case CYCL_APP:
                SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_GRV));
                return false;
            case ZOOM_IN:
                SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_EQL));
                return false;
            case ZOOM_OUT:
                SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_MINUS));
                return false;
            case SCRNSHOT:
                SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_LSFT)SS_DOWN(X_4));
                return false;
            case FIGMA_UI:
                SEND_STRING(SS_DOWN(X_LCMD)SS_DOWN(X_BSLS));
                return false;
        }
    }

    return true;
};


