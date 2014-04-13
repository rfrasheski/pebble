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
  makeRecipeSelectWindow((int)simple_menu_layer_get_selected_index(simple_menu_layer));
  // This context defaults to the window, but may be changed with \ref window_set_click_context.
} 
void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  Window *window = (Window *)context;
  if((int)simple_menu_layer_get_selected_index(simple_menu_layer)<6){
    simple_menu_layer_set_selected_index(simple_menu_layer,(int)simple_menu_layer_get_selected_index(simple_menu_layer) + 1, true);
  }
}
void up_click_handler(ClickRecognizerRef recognizer, void *context){
   Window *window = (Window *)context;
  if((int)simple_menu_layer_get_selected_index(simple_menu_layer)>0){
    simple_menu_layer_set_selected_index(simple_menu_layer,(int)simple_menu_layer_get_selected_index(simple_menu_layer) - 1, true);
  }
}
void click_config_provider(Window *window) {
 // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler) select_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler) down_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, (ClickHandler) up_click_handler);
}
void makeRecipeSelectWindow(int index) {
  
  GRect frame;
	
	window = window_create();
	frame = layer_get_bounds(window_get_root_layer(window));
  window_set_click_config_provider(window, (ClickConfigProvider) click_config_provider);
  switch(index){
    case 0:
      menu_items[0] = (SimpleMenuItem){.title = "Asian-Chicken-Noodle-Soup", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Cilantro-Chicken-and-Spicy-Thai-Noodles", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Moroccan-Chicken-with-Green-Olives-and-Lemon", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Collard-Greens-with-Lentils-Tomatoes-and-Indian-Spices", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Aloo-Gobi", NULL, .callback = call_back_for_item,};   
    
    break;
    case 1:
      menu_items[0] = (SimpleMenuItem){.title = "Joes-Screaming-Stuffed-Jalapeno-Poppers", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Saucy-Asian-Meatballs", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Crme-De-Brie-Apple-Pinwheels", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Chicken-Enchilada-Puffs", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Spicy-Vegetable-Dip", NULL, .callback = call_back_for_item,};
	    
    break;
    case 2:
      menu_items[0] = (SimpleMenuItem){.title = "Potato-Casserole", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Egg-Sandwich", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Grilled-Cheese-Roast-Beef-Sandwiches", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Bacon-and-Cheese-Stuffed-Chicken", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Hot-Dog-Filled-Crescents", NULL, .callback = call_back_for_item,};
	   
      break;
   case 3:
      menu_items[0] = (SimpleMenuItem){.title = "Pizza-Pasta", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Pasta-Primavera", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Pasta-with-Pesto", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Pasta-Fagioli", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Pasta-Salad", NULL, .callback = call_back_for_item,};   
    
    break;
    case 4:
      menu_items[0] = (SimpleMenuItem){.title = "Green-Salad-with-Cranberry-Vinaigrette", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Spinach-Salad-with-Orzo-and-Feta", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Buffalo-Style-Chicken-Salad", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Cindys-Grilled-Salad", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Ceasar-Salad", NULL, .callback = call_back_for_item,};
	   
    break;
    case 5:
      menu_items[0] = (SimpleMenuItem){.title = "Helens-Lentil-Soup", NULL, .callback = call_back_for_item,};
	    menu_items[1] = (SimpleMenuItem){.title = "Boracho-Bean-Soup-or-Frijoles-a-La-Charra-Restaurant-Style", NULL, .callback = call_back_for_item,};
	    menu_items[2] = (SimpleMenuItem){.title = "Hearty-White-Bean-Soup", NULL, .callback = call_back_for_item,};
	    menu_items[3] = (SimpleMenuItem){.title = "Ham-Bean-Soup", NULL, .callback = call_back_for_item,};
	    menu_items[4] = (SimpleMenuItem){.title = "Easy-Bean-Soup-aka-Petras-Kitchen-Sink-Soup", NULL, .callback = call_back_for_item,};
    break;
    
  }
  menu_section[0] = (SimpleMenuSection){.items = menu_items, .num_items = 6, .title = "receipe gettera 91241",};
	
	simple_menu_layer = simple_menu_layer_create(frame, window, menu_section, 1, NULL);
	window_set_click_config_provider(window, (ClickConfigProvider) click_config_provider);

	layer_add_child(window_get_root_layer(window), simple_menu_layer_get_layer(simple_menu_layer));
  
	window_stack_push(window, true);
  
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