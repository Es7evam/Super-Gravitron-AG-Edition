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
    std::pair <int, int> coord;

    Window *W = new Window(P);

    std::thread window_thread(&Window::run, W);
    std::thread player_thread(&Player::run, P);

    window_thread.join();
    player_thread.join();

    return 0;
}
