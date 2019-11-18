// Own codes
#include "globalconstants.hh"

// Libs
#include <chrono> // time libs

class Player{
    private:
        int _x, _y; // coordenadas
        int _updown, _leftright; // -1 - up; 1 - down; -1 - left; 1 - right
        int _score;

        std::chrono::steady_clock::time_point _start_time, _game_time;
    public:

        Player();

        int x() {return _x;}
        int y() {return _y;}
        int score() {return _score;}


        void Update();

        void Change_dir(int key);
};