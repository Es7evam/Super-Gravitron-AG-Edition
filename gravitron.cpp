#include <time.h>
#include <curses.h>
#include <unistd.h>
#include <utility>
#include <iostream>
#include <termios.h> //terminal stuff
#include <cstring>

#include <chrono> // time libs

// Own codes
#include "classes/Window.hh"
#include "classes/AG.hh"
#include <stdio.h>

void debug(std::vector<Blast> B){
    int i=0;
    std::cerr << "Debug: " << B.size() << "\n";
    for (auto singleBlast : B){
        std::cerr  << i++  << "  " << singleBlast.x() << " " << singleBlast.y() << " -> " << singleBlast.leftright() << std::endl; 
    }
}

int main(int argc, char *argv[]){
    AG myAg;
    if(argc > 1){
        if(strcmp("evolution", argv[1]) == 0){
            myAg.enabled = true;
        }
        if(argc > 2){
            if(strcmp("--load", argv[2]) == 0){
                myAg.load();
            }
        }
    }

    // Curses
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr,TRUE);


    clear(); // limpa tela

    Player P;
    std::vector<Blast> B;
    std::pair <int, int> coord;

    Window W;

    int key;
    int cont = 0;
    while(true){
        //printf("%d %d\n", P.x, P.y);
        //sleep(1);
        coord = std::make_pair(P.x(), P.y());
        P.Update();
        for(long unsigned int i=0;i<B.size();i++){
            B[i].Update();
        }
        key = getch();
        if(key < 10000 && key != -1)
            P.Change_dir(key);

        // Renders Window
        W.Update(P, &B, coord);
        
        if(cont++ == 100){
            //debug(B);
            cont=0;
        }
    }

    return 0;
}
