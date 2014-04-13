

static SimpleMenuLayer *simple_menu_layer;
static SimpleMenuSection menu_section[1];
static SimpleMenuItem menu_items[5];
static Window *window;

static void call_back_for_item(int index, void *ctx){
	menu_layer_reload_data(simple_menu_layer_get_menu_layer(simple_menu_layer));
}
static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  Window *window = (Window *)context;
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
void makeRecipeSelectWindow(int index) {
  
  GRect frame;
	
	window = window_create();
	frame = layer_get_bounds(window_get_root_layer(window));
  window_set_click_config_provider(window, (ClickConfigProvider) click_config_provider);
  switch(index){
    case "Ethnic":
      menu_items[0] = (SimpleMenuItem){.title = "Asian-Chicken-Noodle-Soup", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Cilantro-Chicken-and-Spicy-Thai-Noodles", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Moroccan-Chicken-with-Green-Olives-and-Lemon", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Collard-Greens-with-Lentils-Tomatoes-and-Indian-Spices", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Aloo-Gobi", NULL, .callback = call_back_for_item,};   
    
    break;
    case  "Hord d'oeuvre":
      menu_items[0] = (SimpleMenuItem){.title = "Joes-Screaming-Stuffed-Jalapeno-Poppers", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Saucy-Asian-Meatballs", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Crme-De-Brie-Apple-Pinwheels", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Chicken-Enchilada-Puffs", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Spicy-Vegetable-Dip", NULL, .callback = call_back_for_item,};
	    
    break;
    case "Kid-Friendly":
      menu_items[0] = (SimpleMenuItem){.title = "Potato-Casserole", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Egg-Sandwich", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Grilled-Cheese-Roast-Beef-Sandwiches", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Bacon-and-Cheese-Stuffed-Chicken", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Hot-Dog-Filled-Crescents", NULL, .callback = call_back_for_item,};
	   
      break;
   case "Pasta":
      menu_items[0] = (SimpleMenuItem){.title = "Pizza-Pasta", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Pasta-Primavera", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Pasta-with-Pesto", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Pasta-Fagioli", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Pasta-Salad", NULL, .callback = call_back_for_item,};   
    
    break;
    case "Salads":
      menu_items[0] = (SimpleMenuItem){.title = "Green-Salad-with-Cranberry-Vinaigrette", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Spinach-Salad-with-Orzo-and-Feta", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Buffalo-Style-Chicken-Salad", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Cindys-Grilled-Salad", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Ceasar-Salad", NULL, .callback = call_back_for_item,};
	   
    break;
    case "Soups":
      menu_items[0] = (SimpleMenuItem){.title = "Helens-Lentil-Soup", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Boracho-Bean-Soup-or-Frijoles-a-La-Charra-Restaurant-Style", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Hearty-White-Bean-Soup", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Ham-Bean-Soup", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Easy-Bean-Soup-aka-Petras-Kitchen-Sink-Soup", NULL, .callback = call_back_for_item,};
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