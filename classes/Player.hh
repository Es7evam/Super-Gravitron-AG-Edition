// Own codes
#include "globalconstants.hh"

#include <time.h>
#include <curses.h>
#include <unistd.h>
#include <utility>
#include <iostream>
#include <termios.h> //terminal stuff

#include <thread>
#include <mutex>

#include <chrono> // time libs

class Player{
    private:
        int _x, _y; // coordenadas
        int _updown, _leftright; // -1 - up; 1 - down; -1 - left; 1 - right
        bool _isReady;

        std::chrono::steady_clock::time_point _start_time;
        std::mutex _mutex;
    public:

        Player();

        int x() {return _x;}
        int y() {return _y;}
        int isReady() {return _isReady;}

        void Update();

        void Change_dir(int key);
};