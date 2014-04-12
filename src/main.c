#include <pebble.h>

static SimpleMenuLayer *simple_menu_layer;
static SimpleMenuSection menu_section[1];
static SimpleMenuItem menu_items[6];


static Window *window;

static void call_back_for_item(int index, void *ctx){
	menu_layer_reload_data(simple_menu_layer_get_menu_layer(simple_menu_layer));
}


void init(void){

	GRect frame;
	
	window = window_create();

	frame = layer_get_bounds(window_get_root_layer(window));
	
	menu_items[0] = (SimpleMenuItem){.title = "Pasta", .subtitle = "for the pastafarians", NULL, .callback = call_back_for_item,};
	menu_items[1] = (SimpleMenuItem){.title = "Soup", .subtitle = "when don't feel chewing", NULL, .callback = call_back_for_item,};
	menu_items[2] = (SimpleMenuItem){.title = "Salad", .subtitle = "is this even a food", NULL, .callback = call_back_for_item,};
	menu_items[3] = (SimpleMenuItem){.title = "Beef", .subtitle = "for cool kids", NULL, .callback = call_back_for_item,};
	menu_items[4] = (SimpleMenuItem){.title = "Chicken", .subtitle = "this was a bird", NULL, .callback = call_back_for_item,};
	menu_items[5] = (SimpleMenuItem){.title = "Kebab", .subtitle = "aria", NULL, .callback = call_back_for_item,};

	menu_section[0] = (SimpleMenuSection){.items = menu_items, .num_items = 6, .title = "receipe gettera 91241",};
	
	simple_menu_layer = simple_menu_layer_create(frame, window, menu_section, 1, NULL);
	
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