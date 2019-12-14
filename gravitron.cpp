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
            std::cout << "AG enabled\n";
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

    Player *P = new Player();
    std::vector<Blast> B;
    std::pair <int, int> coord;

    Window *W = new Window();

    int key;
    int cont = 0;
    int maxscore = 0;
    bool loop = false;
    std::string s;
    for (int i = 0; i < 50; i++) {
        myAg.load();
        mvaddstr(5, 40, "Geracao: ");
        s = std::to_string(i).substr(0,4);
        mvaddstr(5, 60, s.c_str());
        mvaddstr(7, 40, "Maior score: ");
        s = std::to_string((float)maxscore/1000.0).substr(0,4);
        mvaddstr(7, 60, s.c_str());   
        while(!loop){
            //printf("%d %d\n", P.x, P.y);
            //sleep(1);
            coord = std::make_pair(P->x(), P->y());
            P->Update();
            for(long unsigned int i=0;i<B.size();i++){
                B[i].Update();
            }
            if(myAg.enabled) {
                key = myAg.makeMove();
            } else {
                key = getch();
            }
            
            if(key < 10000 && key != -1)
                P->Change_dir(key);

            // Renders Window
            loop = W->Update(*P, &B, coord);
            
            if(cont++ == 100){
                //debug(B);
                cont=0;
            }
        }
        if(P->score() > maxscore) {
            maxscore = P->score();
        }
        myAg.endGame(P->score());
        delete P;
        delete W;
        B.clear();

        clear();

        P = new Player();
        W = new Window();
        loop = false;
    }

    nocbreak();
    echo();
    return 0;
}
