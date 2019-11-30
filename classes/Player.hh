#ifndef PLAYER_HH
#define PLAYER_HH

// Own codes
#include "globalconstants.hh"
#include "Object.hh"

#include <time.h>
#include <curses.h>
#include <unistd.h>
#include <utility>
#include <iostream>
#include <termios.h> //terminal stuff

#include <thread>
#include <mutex>

#include <chrono> // time libs

class Player : public Object{
    private:
        int _updown, _leftright; // -1 - up; 1 - down; -1 - left; 1 - right

        std::chrono::steady_clock::time_point _start_time;
        std::mutex _mutex;
    public:

        Player();

        std::string name();
        void init();
        void Update();

        void Change_dir(int key);
};

#endif