#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <emscripten.h>

#define WIDTH 60
#define HEIGHT 15

typedef struct {
    WINDOW* win;
    int x, y;
    int dx, dy;
    char message[20];
} AppState;

void draw_frame(AppState* state) {
    // Clear window
    wclear(state->win);

    // Draw border
    box(state->win, 0, 0);

    // Print message at current position
    mvwprintw(state->win, state->y, state->x, "%s", state->message);

    // Update the position for next frame
    state->x += state->dx;
    state->y += state->dy;

    // Bounce off walls
    if (state->x <= 0 || state->x >= WIDTH - strlen(state->message) - 1) {
        state->dx = -state->dx;
        state->x += state->dx * 2; // Prevent sticking to walls
    }

    if (state->y <= 0 || state->y >= HEIGHT - 2) {
        state->dy = -state->dy;
        state->y += state->dy * 2; // Prevent sticking to walls
    }

    // Refresh the window
    wrefresh(state->win);
}

void main_loop(void* arg) {
    AppState* state = (AppState*)arg;
    draw_frame(state);

    // Slow down animation
    emscripten_sleep(100);
}

int main() {
    //// Initialize ncurses
    //initscr();
    //cbreak();
    //noecho();
    //curs_set(0); // Hide cursor

    //// Check terminal size
    //int max_y, max_x;
    //getmaxyx(stdscr, max_y, max_x);

    //if (max_y < HEIGHT || max_x < WIDTH) {
    //    endwin();
    //    printf("Terminal too small. Need at least %dx%d\n", WIDTH, HEIGHT);
    //    return 1;
    //}

    //// Create window
    //WINDOW* win = newwin(HEIGHT, WIDTH, (max_y - HEIGHT) / 2, (max_x - WIDTH) / 2);
    //keypad(win, TRUE);

    //// Initialize app state
    //AppState state;
    //state.win = win;
    //state.x = WIDTH / 4;
    //state.y = HEIGHT / 2;
    //state.dx = 1;
    //state.dy = 1;
    //strcpy(state.message, "Hello, PDCurses!");

    //// Set up animation loop
    //emscripten_set_main_loop_arg(main_loop, &state, 0, 1);

    //// This code is unreachable in Emscripten's main loop mode
    //delwin(win);
    //endwin();
    return 0;
}