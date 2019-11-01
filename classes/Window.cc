#include "Window.hh"

Window::Window() {
    int len = (1 + MAXX - 15)/2;
    int i;

    char wall = '#';

    for(i=0;i<len+1/2;i++) {
        mvaddch(0, i, wall);
    }

    mvaddstr(0, i, "Super Gravitron");
    for(i=15+len;i<=MAXX;i++) {
        mvaddch(0, i, wall);
    }

    for(int i=1;i<MAXY;i++){
        mvaddch(i, 0, wall);
        mvaddch(i, MAXX, wall);
    }

    for(int i=0;i<=MAXX;i++) {
        mvaddch(MAXY, i, wall);
    }
}

void Window::Update(Player P, std::pair<int, int> pastPlayer) {
    mvaddch(pastPlayer.second, pastPlayer.first, ' ');
    mvaddch(P.y(), P.x(), 'X');
    refresh();
}