CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -fdiagnostics-color=always
LIBS = -lSDL2main -lSDL2 -lm -lSDL2_image
INCLUDE = -Iinclude
OBJDIR = obj
BINDIR = bin

# List of source files
SOURCES = source.c addImage.c attillery.c ceilNfloor.c circle.c crossHair.c direction.c events.c frame.c move.c ray.c rect.c wall.c window.c player.c rain.c

# Convert source file names to object file names
OBJECTS = $(addprefix $(OBJDIR)/,$(SOURCES:.c=.o))

# Target: maze
$(BINDIR)/maze: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

# Rule for compiling source files into object files
$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(BINDIR)/maze $(OBJECTS)
