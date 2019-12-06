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
#include "Entity.hh"
#include "Player.hh"
#include "Blast.hh"

class Window : public Entity{
    private:
        Player *_P;
        std::vector<Blast *> _B;
        bool _start;
        int _key;

    public:
        Window(Player *P, std::vector<Blast *> B);

        std::string name();
        void init();
        void Update();
        void FirstDraw();
        void finish();

        bool Collided();
};

#endif
