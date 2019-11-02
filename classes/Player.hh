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
        int _lastX, _lastY;
        int _updown, _leftright; // -1 - up; 1 - down; -1 - left; 1 - right
        bool _isReady;

        std::chrono::steady_clock::time_point _start_time;
        std::mutex _mutex;

        std::mutex _readyMutex;
    public:

        Player();

        int x() {return _x;}
        int y() {return _y;}
        int lastX() {return _lastX;}
        int lastY() {return _lastY;}
        int isReady() {return _isReady;}
        void setReady();

        void Update();

        // Thread
        void run();

        void Change_dir(int key);
};