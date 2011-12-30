CC=gcc
CFLAGS=-W -Wall -O2

lib: lib/liballegro_nine_patch.a

lib/liballegro_nine_patch.a: obj/nine_patch.o
	ar rcs lib/liballegro_nine_patch.a obj/nine_patch.o

obj/nine_patch.o: src/nine_patch.c include/allegro_nine_patch.h
	$(CC) $(CFLAGS) -c -Iinclude src/nine_patch.c -o obj/nine_patch.o

clean:
	rm -f obj/nine_patch.o
