#include <pebble.h>

static SimpleMenuLayer *simple_menu_layer;
static SimpleMenuSection menu_section[1];
static SimpleMenuItem menu_items[6];
static Window *window;
void call_back_for_item(int index, void *ctx){
 menu_layer_reload_data(simple_menu_layer_get_menu_layer(simple_menu_layer));
 }

void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  Window *window = (Window *)context;
  // This context defaults to the window, but may be changed with \ref window_set_click_context.
} 
void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  Window *window = (Window *)context;
}
void click_config_provider(Window *window) {
 // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler) select_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler) down_click_handler);
}


void init(void){
	
}

void deinit(void) {
	
  window_destroy(window);
}

