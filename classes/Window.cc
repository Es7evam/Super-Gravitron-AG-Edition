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

void Window::Update(std::pair<int, int> pastPlayer) {
    mvaddch(pastPlayer.second, pastPlayer.first, ' ');
    mvaddch(_P->y(), _P->x(), 'X');
    refresh();
}

void Window::run() {

    std::cout << "[Window] Thread is running! \n";
    // Curses
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr,TRUE);

    clear(); // limpa tela

    std::pair <int, int> coord;
    int key = 0;

    FirstDraw();

    while(true) {
        coord = std::make_pair(_P->x(), _P->y());
        key = getch();

        _P->Update();
        if(key < 10000 && key != -1) {
            _P->Change_dir(key);
        }

        Update(coord);
        //std::cout << "[Window] Thread is still running! \n";
    }
}