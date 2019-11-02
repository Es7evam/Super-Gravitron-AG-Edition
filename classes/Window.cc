#include "Window.hh"

Window::Window(Player *P) {
    if(P == nullptr) {
        exit(1);
    }

    _P = P;
    _start = false;
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

void Window::Update() {
    mvaddch(_P->lastY(), _P->lastX(), ' ');
    mvaddch(_P->y(), _P->x(), 'X');
    refresh();
    
    _P->setReady();
}

void Window::run() {

    std::cout << "[Window] Thread is running! \n";
    // Curses
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr,TRUE);

    clear(); // limpa tela

    int key = 0;

    FirstDraw();

    while(true) {
        key = getch();

        if(key < 10000 && key != -1) {
            _P->Change_dir(key);
        }

        Update();
    }
}