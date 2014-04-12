#include <pebble.h>
#include <selectRecipe.c>

static SimpleMenuLayer *simple_menu_layer;
static SimpleMenuSection menu_section[1];
static SimpleMenuItem menu_items[6]; 

static Window *window;

static void call_back_for_item(int index, void *ctx){
 menu_layer_reload_data(simple_menu_layer_get_menu_layer(simple_menu_layer));
 }

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  Window *window = (Window *)context;
  makeRecipeSelectWindow();
  // This context defaults to the window, but may be changed with \ref window_set_click_context.
} 
static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  Window *window = (Window *)context;
}
static void click_config_provider(Window *window) {
 // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler) select_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler) down_click_handler);
}



void init(void){
	GRect frame;
	
	window = window_create();
	frame = layer_get_bounds(window_get_root_layer(window));
	menu_items[0] = (SimpleMenuItem){.title = "Pasta", .subtitle = "for the pastafarians", NULL, .callback = call_back_for_item,};
	menu_items[1] = (SimpleMenuItem){.title = "Soup", .subtitle = "when don't feel chew", NULL, .callback = call_back_for_item,};
	menu_items[2] = (SimpleMenuItem){.title = "Salad", .subtitle = "is this even a food", NULL, .callback = call_back_for_item,};
	menu_items[3] = (SimpleMenuItem){.title = "Beef", .subtitle = "for cool kids", NULL, .callback = call_back_for_item,};
	menu_items[4] = (SimpleMenuItem){.title = "Chicken", .subtitle = "this was a bird", NULL, .callback = call_back_for_item,};
	menu_items[5] = (SimpleMenuItem){.title = "Kebab", .subtitle = "aria", NULL, .callback = call_back_for_item,};

	menu_section[0] = (SimpleMenuSection){.items = menu_items, .num_items = 6, .title = "receipe gettera 91241",};
	
	simple_menu_layer = simple_menu_layer_create(frame, window, menu_section, 1, NULL);
	window_set_click_config_provider(window, (ClickConfigProvider) click_config_provider);

	layer_add_child(window_get_root_layer(window), simple_menu_layer_get_layer(simple_menu_layer));
  
	window_stack_push(window, true);

  

}

void deinit(void) {
	simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

int main(void) {
  init();
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);
  app_event_loop();
  deinit();
}