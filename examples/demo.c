#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro_nine_patch.h"

int main(int argc, const char *argv[])
{
	ALLEGRO_PATH *path;
	ALLEGRO_DISPLAY *display;
	NINE_PATCH_BITMAP *button, *grab, *select;
	ALLEGRO_EVENT_QUEUE *queue;
	int i, y, h;
	
	(void) argc;
	(void) argv;
	
	al_init();
	al_init_image_addon();
	al_install_keyboard();
	
	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "media");
	al_change_directory(al_path_cstr(path, '/'));
	al_destroy_path(path);
	
	display = al_create_display(600, 400);
	if (!display)
	{
		fprintf(stderr, "Unable to create display.\n");
		return 1;
	}
	
	button = load_nine_patch_bitmap("button.9.png");
	if (!button)
	{
		fprintf(stderr, "Unable to load button.9.png\n");
		return 1;
	}
	
	grab = load_nine_patch_bitmap("grab.9.png");
	if (!grab)
	{
		destroy_nine_patch_bitmap(button);
		fprintf(stderr, "Unable to load grab.9.png\n");
		return 1;
	}
	
	select = load_nine_patch_bitmap("select.9.png");
	if (!select)
	{
		destroy_nine_patch_bitmap(button);
		destroy_nine_patch_bitmap(grab);
		fprintf(stderr, "Unable to load select.9.png\n");
		return 1;
	}
	
	queue = al_create_event_queue();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	
	al_clear_to_color(al_map_rgb(255,255,255));
	
	for (i = 0, h = 25, y = 0; i < 5; ++i)
	{
		draw_nine_patch_bitmap(button, 0, y, h, h);	
		draw_nine_patch_bitmap(grab, 200, y, h, h);	
		draw_nine_patch_bitmap(select, 400, y, h, h);	
		
		draw_nine_patch_bitmap(button, h + 2, y, 200 - h - 4, 25);	
		draw_nine_patch_bitmap(grab, 200 + h + 2, y, 200 - h - 4, 25);	
		draw_nine_patch_bitmap(select, 400 + h + 2, y, 200 - h - 4, 25);	
		
		y += h + 2;
		h += 25;
	}
		
	
	al_flip_display();
	while (true)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);
		
		if (event.type == ALLEGRO_EVENT_KEY_UP || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;		
	}
	
	destroy_nine_patch_bitmap(button);
	destroy_nine_patch_bitmap(grab);
	destroy_nine_patch_bitmap(select);		
		
	return 0;
}