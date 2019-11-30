#include "Window.hh"

Window::Window(Player *P) {
    if(P == nullptr) {
        exit(1);
    }

    _P = P;
    _start = false;
    _key = 0;
}

std::string Window::name() {
    return "Window";
}

void Window::FirstDraw() {
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

void Window::init() {
    // Curses
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr,TRUE);

    clear(); // limpa tela
    FirstDraw();
}

void Window::Update() {
    _key = getch();
    if(_key < 10000 && _key != -1) {
        _P->Change_dir(_key);
    }

    mvaddch(_P->pasty(), _P->pastx(), ' ');
    mvaddch(_P->y(), _P->x(), 'X');
    refresh();
    
    _P->setReady();
    _isReady = true;
}
