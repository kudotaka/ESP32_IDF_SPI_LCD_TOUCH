#include "lvgl.h"

void example_lvgl_qrcode_ui(lv_disp_t *disp)
{
    lv_obj_t *scr = lv_disp_get_scr_act(disp);

//    lv_color_t bg_color = lv_palette_lighten(LV_PALETTE_LIGHT_BLUE, 5);
//    lv_color_t fg_color = lv_palette_darken(LV_PALETTE_BLUE, 4);
    lv_color_t bg_color = lv_color_white();
    lv_color_t fg_color = lv_color_black();

    lv_obj_t * qr = lv_qrcode_create(scr, 200, fg_color, bg_color);

    /*Set data*/
//    const char * data = "https://lvgl.io";
    const char * data = "https://docs.espressif.com/projects/esp-idf/en/v5.3.1/esp32s3/api-reference/system/freertos_idf.html";

    lv_qrcode_update(qr, data, strlen(data));
    lv_obj_center(qr);

    /*Add a border with bg_color*/
    lv_obj_set_style_border_color(qr, bg_color, 0);
    lv_obj_set_style_border_width(qr, 5, 0);
}
