#ifndef __included_nine_patch_h
#define __included_nine_patch_h

#include <allegro5/allegro.h>

typedef struct nine_patch_bitmap_tag NINE_PATCH_BITMAP;

typedef struct nine_patch_padding_tag
{
	int top, right, bottom, left;
} NINE_PATCH_PADDING;

NINE_PATCH_BITMAP *create_nine_patch_bitmap(ALLEGRO_BITMAP *bmp, bool owns_bitmap);
NINE_PATCH_BITMAP *load_nine_patch_bitmap(const char *filename);
void draw_nine_patch_bitmap(NINE_PATCH_BITMAP *p9, int dx, int dy, int dw, int dh);
ALLEGRO_BITMAP *create_bitmap_from_nine_patch(NINE_PATCH_BITMAP *p9, int w, int h);

int get_nine_patch_bitmap_width(const NINE_PATCH_BITMAP *p9);
int get_nine_patch_bitmap_height(const NINE_PATCH_BITMAP *p9);

int get_nine_patch_bitmap_min_width(const NINE_PATCH_BITMAP *p9);
int get_nine_patch_bitmap_min_height(const NINE_PATCH_BITMAP *p9);

ALLEGRO_BITMAP *get_nine_patch_bitmap_source(const NINE_PATCH_BITMAP *p9);
NINE_PATCH_PADDING get_nine_patch_padding(const NINE_PATCH_BITMAP *p9);

void destroy_nine_patch_bitmap(NINE_PATCH_BITMAP *p9);

#endif