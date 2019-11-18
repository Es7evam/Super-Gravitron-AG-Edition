// Own codes
#include "globalconstants.hh"

// Libs
#include <chrono>
#include <random>
#include <utility>
#include <vector>

class Blast{
    private:
        int _x, _y; // coordenadas
        int _pastx, _pasty; // coordenadas
        int _leftright; // -1 - up; 1 - down; -1 - left; 1 - right
        bool _ended;

        std::chrono::steady_clock::time_point _start_time;
    public:

        Blast();

        int x() {return _x;}
        int y() {return _y;}
        int pastx() {return _pastx;}
        int pasty() {return _pasty;}
        int leftright() {return _leftright;}
        bool ended() {return _ended;}

        void Update();

};