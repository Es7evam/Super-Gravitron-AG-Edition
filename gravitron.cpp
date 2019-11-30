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

int main(){
    
    Player *P = new Player();

    Blast *B = new Blast();
    Window *W = new Window(P, B);
    

    std::thread window_thread(&Window::run, W);
    std::thread player_thread(&Player::run, P);
    std::thread blast_thread(&Blast::run, B);

    window_thread.join();
    player_thread.join();
    blast_thread.join();

    return 0;
}
