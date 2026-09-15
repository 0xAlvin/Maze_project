CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -fdiagnostics-color=always
INCLUDE = -Iinclude
OBJDIR = obj
BINDIR = bin

UNAME_S := $(shell uname -s 2>/dev/null)

ifeq ($(OS),Windows_NT)
	EXE = .exe
	RM = del /Q
	SDL_CFLAGS = $(shell pkg-config --cflags sdl2 SDL2_image)
	SDL_LIBS = $(shell pkg-config --libs sdl2 SDL2_image)
else ifeq ($(UNAME_S),Darwin)
	EXE =
	RM = rm -f
	SDL_CFLAGS = $(shell sdl2-config --cflags)
	SDL_LIBS = $(shell sdl2-config --libs) -lSDL2_image
else ifeq ($(UNAME_S),Linux)
	EXE =
	RM = rm -f
	SDL_CFLAGS = $(shell sdl2-config --cflags)
	SDL_LIBS = $(shell sdl2-config --libs) -lSDL2_image
else
	$(error Unsupported platform: $(UNAME_S))
endif

# List of source files
SOURCES = source.c addImage.c attillery.c ceilNfloor.c circle.c crossHair.c direction.c events.c frame.c move.c ray.c rect.c wall.c window.c player.c rain.c

# Convert source file names to object file names
OBJECTS = $(addprefix $(OBJDIR)/,$(SOURCES:.c=.o))

# Target: maze
all: $(BINDIR)/maze$(EXE)

$(BINDIR)/maze$(EXE): $(OBJECTS) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(SDL_LIBS) -lm

# Rule for compiling source files into object files
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(SDL_CFLAGS) -c $< -o $@

ifeq ($(OS),Windows_NT)
$(OBJDIR) $(BINDIR):
	if not exist "$@" mkdir "$@"
else
$(OBJDIR) $(BINDIR):
	mkdir -p $@
endif

clean:
	$(RM) $(BINDIR)/maze$(EXE) $(OBJECTS)

.PHONY: all clean