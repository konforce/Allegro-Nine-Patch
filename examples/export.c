#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro_nine_patch.h"

static int usage(const char *argv[])
{
	fprintf(stderr, "Usage:\n %s w h infile outfile\n\nExample:\n %s 150 50 button.9.png button150x50.png\n", argv[0], argv[0]);
	return 1;
}

int main(int argc, const char *argv[])
{
	int w, h;
	NINE_PATCH_BITMAP *nine_patch;
	ALLEGRO_BITMAP *bmp;
	
	if (argc != 5)
		return usage(argv);
		
	w = atoi(argv[1]);
	h = atoi(argv[2]);
	
	if (w <= 0 || h <= 0)
		return usage(argv);
	
	al_init();
	al_init_image_addon();
		
	nine_patch = load_nine_patch_bitmap(argv[3]);
	if (!nine_patch)
	{
		fprintf(stderr, "Unable to load %s as a nine patch bitmap.\n", argv[3]);
		return 1;
	}
	
	bmp = create_bitmap_from_nine_patch(nine_patch, w, h);
	if (!bmp)
	{
		fprintf(stderr, "Unable to create nine patch bitmap.\n");
		destroy_nine_patch_bitmap(nine_patch);
		return 1;
	}
	
	if (!al_save_bitmap(argv[4], bmp))
	{
		fprintf(stderr, "Unable to save bitmap as %s.\n", argv[4]);
	}
	
	destroy_nine_patch_bitmap(nine_patch);
	al_destroy_bitmap(bmp);
	
	return 0;
}