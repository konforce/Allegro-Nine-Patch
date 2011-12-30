CC=gcc
ALLEGRO_VERSION=5.1
CFLAGS=-W -Wall -O2
LFLAGS=lib/liballegro_nine_patch.a $$(pkg-config --libs allegro-$(ALLEGRO_VERSION) allegro_image-$(ALLEGRO_VERSION))

all: lib examples

lib: lib/liballegro_nine_patch.a

lib/liballegro_nine_patch.a: obj/nine_patch.o
	ar rcs lib/liballegro_nine_patch.a obj/nine_patch.o

obj/nine_patch.o: src/nine_patch.c include/allegro_nine_patch.h
	$(CC) $(CFLAGS) -c -Iinclude src/nine_patch.c -o obj/nine_patch.o
	
examples: bin/export bin/demo
	
bin/export: obj/export.o lib/liballegro_nine_patch.a
	$(CC) obj/export.o $(LFLAGS) -o bin/export
	
obj/export.o: examples/export.c
	$(CC) $(CFLAGS) -c -Iinclude examples/export.c -o obj/export.o
	
bin/demo: obj/demo.o lib/liballegro_nine_patch.a
	$(CC) obj/demo.o $(LFLAGS) -o bin/demo
	
obj/demo.o: examples/demo.c
	$(CC) $(CFLAGS) -c -Iinclude examples/demo.c -o obj/demo.o


clean:
	rm -f obj/*.o
