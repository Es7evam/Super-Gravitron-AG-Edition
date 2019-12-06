#include <time.h>
#include <curses.h>
#include <unistd.h>
#include <utility>
#include <iostream>
#include <termios.h> //terminal stuff

#include <thread>

#include <chrono> // time libs

// Own codes
#include "classes/Window.hh"

#include <stdio.h>

#define NUMBLAST 1

int main(){
    
    Player *P = new Player();
    std::vector<Blast *> B;
    for(int i = 0; i < NUMBLAST; i++) {
        B.push_back(new Blast());
    }


    Window *W = new Window(P, B);
    

    std::thread window_thread(&Window::run, W);
    std::thread player_thread(&Player::run, P);
    std::vector<std::thread> blast_threads;
    for(int i = 0; i < NUMBLAST; i++) {
        blast_threads.push_back(std::thread(&Blast::run, B[i]));
    }


    window_thread.join();
    player_thread.join();

    return 0;
}
