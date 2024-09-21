#include "esp_log.h"
#include "lvgl.h"

extern lv_font_t my_symbol_custom;
#define MY_USB_SYMBOL "\xEF\x8A\x87"
#define MY_USER_SYMBOL "\xEF\x80\x87"
#define MY_STAR_SYMBOL "\xEF\x80\x85"
#define MY_DROPLET_SYMBOL "\xEF\x81\x83"
#define MY_SUN_SYMBOL "\xEF\x86\x85"
#define MY_THERMOMETER_SYMBOL "\xEF\x8B\x89"
#define MY_WIND_SYMBOL "\xEF\x9C\xAE"
#define MY_PERCENT_SYMBOL "\xEF\x8A\x95"
#define MY_PERCENTAGE_SYMBOL "\xEF\x95\x81"
#define MY_CLOCK_SYMBOL "\xEF\x80\x97"
#define MY_SMOG_SYMBOL "\xEF\x9D\x9F"
#define MY_WATER_SYMBOL "\xEF\x9D\xB3"
#define MY_TACHOMETER_ALT_SYMBOL "\xEF\x8F\xBD"
#define MY_TREE_SYMBOL "\xEF\x86\xBB"
#define MY_UMBRELLA_SYMBOL "\xEF\x83\xA9"
#define MY_SNOWFLAKE_SYMBOL "\xEF\x8B\x9C"
#define MY_STAR_SYMBOL "\xEF\x80\x85"
#define MY_CLOUD_SYMBOL "\xEF\x83\x82"
#define MY_CLOUD_SHOWERS_HEAVY_SYMBOL "\xEF\x9D\x80"


static const char *TAG = "lvgl_text_ui";

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        ESP_LOGI(TAG, "Clicked");
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        ESP_LOGI(TAG, "Toggled");
    }
}

void example_lvgl_text_ui(lv_disp_t *disp)
{
    lv_obj_t * label2;
    lv_obj_t *scr = lv_disp_get_scr_act(disp);

    static lv_style_t style;
    lv_style_init(&style);

    lv_style_set_text_color(&style, lv_palette_main(LV_PALETTE_BLUE_GREY));
    lv_style_set_text_font(&style, &lv_font_montserrat_48);

    lv_disp_set_rotation(disp, LV_DISP_ROT_270);

    /*Create an object with the new style*/
    lv_obj_t * oTime = lv_label_create(scr);
    lv_obj_add_style(oTime, &style, 0);
    lv_label_set_text(oTime, "20:00");
    lv_obj_align(oTime, LV_ALIGN_CENTER, 0, 0); // lv_obj_center(oTime);

    lv_obj_t * oDate = lv_label_create(scr);
    lv_obj_add_style(oDate, &style, 0);
    lv_label_set_text(oDate, "2024/09/21");
    lv_obj_align(oDate, LV_ALIGN_BOTTOM_MID, 0, 0); // lv_obj_center(oTime);



/////////////////////

    lv_obj_t * btn2 = lv_btn_create(scr);
    lv_obj_add_event_cb(btn2, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn2, LV_ALIGN_TOP_RIGHT, -5, 5);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2, LV_SIZE_CONTENT);

    label2 = lv_label_create(btn2);
    lv_label_set_text(label2, LV_SYMBOL_POWER " Power");
    lv_obj_center(label2);

/////////////////////
    lv_obj_t * label3;
    lv_obj_t * label4;
    static lv_style_t style3;
    lv_style_init(&style3);
    lv_style_set_text_font(&style3, &my_symbol_custom);
    label3 = lv_label_create(scr);
    lv_obj_align(label3, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_add_style(label3, &style3, 0);
    lv_label_set_text(label3, MY_CLOCK_SYMBOL MY_THERMOMETER_SYMBOL MY_DROPLET_SYMBOL
                MY_TACHOMETER_ALT_SYMBOL MY_TREE_SYMBOL);


    label4 = lv_label_create(scr);
    lv_obj_align(label4, LV_ALIGN_TOP_LEFT, 0, 50);
    lv_obj_add_style(label4, &style3, 0);
    lv_label_set_text(label4, MY_SUN_SYMBOL MY_SMOG_SYMBOL 
                 MY_WATER_SYMBOL MY_UMBRELLA_SYMBOL MY_SNOWFLAKE_SYMBOL MY_STAR_SYMBOL
                 MY_CLOUD_SYMBOL MY_CLOUD_SHOWERS_HEAVY_SYMBOL);

}
