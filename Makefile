CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -fdiagnostics-color=always
LIBS = -lSDL2main -lSDL2 -lm -lSDL2_image
INCLUDE = -Iinclude

maze: source.c addImage.c attillery.c ceilNfloor.c circle.c crossHair.c events.c frame.c ray.c rect.c wall.c window.c player.c 
	$(CC) -g source.c addImage.c attillery.c ceilNfloor.c circle.c crossHair.c events.c frame.c ray.c rect.c wall.c window.c player.c -o bin/maze $(INCLUDE) $(LIBS) $(CFLAGS)

clean:
	rm -f bin/maze