#ifndef WINDOW_HH
#define WINDOW_HH

#include <time.h>
#include <curses.h>
#include <unistd.h>
#include <utility>
#include <iostream>
#include <termios.h> //terminal stuff

// Own codes
#include "globalconstants.hh"
#include "Player.hh"


class Window{
    private:
        Player *_P;
        bool _start;

    public:
        Window(Player *P);

        void Update();
        void FirstDraw();

        // Thread
        void run();
};

#endif
