void config_provider(Window *window) {
 // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_DOWN, down_single_click_handler);
}
void down_single_click_handler(ClickRecognizerRef recognizer, void *context) {
  ... called on single click ...
  Window *window = (Window *)context; // This context defaults to the window, but may be changed with \ref window_set_click_context.
} 
static void call_back_for_item(int index, void *ctx){
	menu_layer_reload_data(simple_menu_layer_get_menu_layer(simple_menu_layer));
}
static SimpleMenuLayer *simple_menu_layer;
static SimpleMenuSection menu_section[1];
static SimpleMenuItem menu_items[6];

void makeRecipeSelectWindow(int index) {
  
  GRect frame;
	
	window = window_create();
	frame = layer_get_bounds(window_get_root_layer(window));
  window_set_click_config_provider(&window, (ClickConfigProvider) config_provider);
  switch(index){
    case 0:
      menu_items[0] = (SimpleMenuItem){.title = "Pasta", .subtitle = "for the pastafarians", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Soup", .subtitle = "when don't feel chew", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Salad", .subtitle = "is this even a food", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Beef", .subtitle = "for cool kids", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Chicken", .subtitle = "this was a bird", NULL, .callback = call_back_for_item,};
	    menu_items[5] = (SimpleMenuItem){.title = "Kebab", .subtitle = "aria", NULL, .callback = call_back_for_item,};
   
    
    break;
    case 1:
      menu_items[0] = (SimpleMenuItem){.title = "Pasta", .subtitle = "for the pastafarians", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Soup", .subtitle = "when don't feel chew", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Salad", .subtitle = "is this even a food", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Beef", .subtitle = "for cool kids", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Chicken", .subtitle = "this was a bird", NULL, .callback = call_back_for_item,};
	    menu_items[5] = (SimpleMenuItem){.title = "Kebab", .subtitle = "aria", NULL, .callback = call_back_for_item,};
    break;
    case 2:
      menu_items[0] = (SimpleMenuItem){.title = "Pasta", .subtitle = "for the pastafarians", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Soup", .subtitle = "when don't feel chew", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Salad", .subtitle = "is this even a food", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Beef", .subtitle = "for cool kids", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Chicken", .subtitle = "this was a bird", NULL, .callback = call_back_for_item,};
	    menu_items[5] = (SimpleMenuItem){.title = "Kebab", .subtitle = "aria", NULL, .callback = call_back_for_item,};
    break;
    case 3:
      menu_items[0] = (SimpleMenuItem){.title = "Pasta", .subtitle = "for the pastafarians", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Soup", .subtitle = "when don't feel chew", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Salad", .subtitle = "is this even a food", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Beef", .subtitle = "for cool kids", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Chicken", .subtitle = "this was a bird", NULL, .callback = call_back_for_item,};
	    menu_items[5] = (SimpleMenuItem){.title = "Kebab", .subtitle = "aria", NULL, .callback = call_back_for_item,};
    break;
    case 4:
      menu_items[0] = (SimpleMenuItem){.title = "Pasta", .subtitle = "for the pastafarians", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Soup", .subtitle = "when don't feel chew", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Salad", .subtitle = "is this even a food", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Beef", .subtitle = "for cool kids", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Chicken", .subtitle = "this was a bird", NULL, .callback = call_back_for_item,};
	    menu_items[5] = (SimpleMenuItem){.title = "Kebab", .subtitle = "aria", NULL, .callback = call_back_for_item,};
    break;
    case 5:
      menu_items[0] = (SimpleMenuItem){.title = "Pasta", .subtitle = "for the pastafarians", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Soup", .subtitle = "when don't feel chew", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Salad", .subtitle = "is this even a food", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Beef", .subtitle = "for cool kids", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Chicken", .subtitle = "this was a bird", NULL, .callback = call_back_for_item,};
	    menu_items[5] = (SimpleMenuItem){.title = "Kebab", .subtitle = "aria", NULL, .callback = call_back_for_item,};
    break;
  }
  
}


void init(void){
	
}

void deinit(void) {
	
  window_destroy(window);
}

int main(void) {
  init();
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);
  app_event_loop();
  deinit();
}