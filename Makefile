CC = emcc
CFLAGS = -O2 -Wall -I$(PDCURSES_DIR)
LDFLAGS = -s WASM=1 -s USE_SDL=2 -s USE_SDL_TTF=2 -s ALLOW_MEMORY_GROWTH=1 \
          -s EXPORTED_RUNTIME_METHODS='["cwrap"]' \
          --preload-file assets \
          -s ASYNCIFY=1 \
          -s ASSERTIONS=1 \
          -s SAFE_HEAP=1 \
          -s ERROR_ON_UNDEFINED_SYMBOLS=0 \
          -s EXPORTED_FUNCTIONS='["_main", "_malloc"]'

# Path to PDCurses SDL2 port
PDCURSES_DIR = pdcurses
PDCURSES_SDL_DIR = $(PDCURSES_DIR)/sdl2

# PDCurses source files for SDL2
PDCURSES_SRCS = $(wildcard $(PDCURSES_SDL_DIR)/*.c) \
                $(wildcard $(PDCURSES_DIR)/pdcurses/*.c)

# Output files
OUTPUT = hello_pdcurses

# Main target
all: dir $(OUTPUT).html

# Create necessary directories
dir:
	mkdir -p assets
	
# Compile the program
$(OUTPUT).html: main.c $(PDCURSES_SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) --shell-file shell.html

# Clean up
clean:
	rm -f $(OUTPUT).html $(OUTPUT).js $(OUTPUT).wasm $(OUTPUT).data

# Run with node (for testing)
run: $(OUTPUT).html
	emrun --browser chrome $(OUTPUT).html

# Download and set up PDCurses
setup:
	# Clone PDCurses repository
	git clone https://github.com/wmcbrine/PDCurses.git pdcurses
	# Create assets directory for SDL font
	mkdir -p assets
	# Copy a font file to assets (you may need to adjust this path)
	cp /usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf assets/ || echo "Please manually copy a TTF font to assets directory"
	# Create dummies.c file for SDL port
	echo "/* Empty file to satisfy emscripten linker */" > dummies.c