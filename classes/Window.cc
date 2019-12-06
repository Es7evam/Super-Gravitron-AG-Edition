#include "Window.hh"

Window::Window(Player *P, std::vector<Blast *> B) {
    if(P == nullptr) {
        exit(1);
    }

    for (int i = 0; i < (int)B.size(); i++) {
        if(B[i] == nullptr) {
            exit(1);
        }
    }

    _P = P;
    _B = B;
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

    mvaddstr(0, 3, " Super Gravitron - Score:   ");
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

    for(int i = 0; i < (int)_B.size(); i++) {
        mvaddch(_B[i]->pasty(), _B[i]->pastx(), ' ');
        mvaddch(_B[i]->y(), _B[i]->x(), '*');

        if(_B[i]->ended() == true){
            mvaddch(_B[i]->y(), _B[i]->x(), '#');
            _B[i]->setRunning();
        }
    }

    Collided();

    for(int i = 0; i < (int)_B.size(); i++) {
        _B[i]->setReady();
    }

    _isReady = true;
}

void Window::finish() {
    char wall = 'O';
    int len = (1 + MAXX - 10)/2;
    int i;
    int writeY = MAXY+3;

    // Parede superior 
    for(i=0;i<=MAXX;i++) {
        mvaddch(writeY, i, wall);
    }
    
    for(i=0;i<=MAXX;i++) {
        mvaddch(writeY+1, i, wall);
    }
    mvaddstr(writeY+1, len, " You Lose ");
    
    for(i=0;i<=MAXX;i++) {
        mvaddch(writeY+2, i, wall);
    }
    refresh();
    while(1);    
}

bool Window::Collided() {
    bool collision = false;

    for(int i = 0; i < (int)_B.size(); i++) {
        if(_P->x() == _B[i]->x() && _P->y() == _B[i]->y()) {
            collision = true;
            _isRunning = false;
        }
    }


    return collision;
}