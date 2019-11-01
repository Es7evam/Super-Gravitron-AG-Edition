#include <time.h>
#include <curses.h>
#include <unistd.h>
#include <utility>
#include <iostream>
#include <termios.h> //terminal stuff

#include <chrono> // time libs

// Own codes
#include "classes/Window.hh"

#include <stdio.h>

int main(){

    // Curses
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr,TRUE);


    clear(); // limpa tela

    Player P;
    std::pair <int, int> coord;

    Window W;

    int key;
    while(true){
        //printf("%d %d\n", P.x, P.y);
        //sleep(1);
        coord = std::make_pair(P.x(), P.y());
        P.Update();
        key = getch();
        if(key < 10000 && key != -1)
            P.Change_dir(key);

        // Renders Window
        W.Update(P, coord);
    }

    return 0;
}
