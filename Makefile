CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -fdiagnostics-color=always 
LIBS = -lSDL2main -lSDL2 -lm -lSDL2_image
INCLUDE = -Iinclude

Maze: source.c addImage.c attillery.c ceilNfloor.c circle.c crossHair.c events.c frame.c ray.c rect.c source.c wall.c window.c
	$(CC) -g source.c addImage.c attillery.c ceilNfloor.c circle.c crossHair.c events.c frame.c ray.c rect.c source.c wall.c window.c -o /bin/maze $(INCLUDE) $(LIBS) $(CFLAGS)

clean:
	rm -f bin/maze 