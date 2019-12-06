#ifndef BLAST_HH
#define BLAST_HH

// Own codes
#include "globalconstants.hh"
#include "Object.hh"

// Libs
#include <chrono>
#include <random>
#include <utility>
#include <vector>

class Blast: public Object{
    private:
        int _leftright; // -1 - up; 1 - down; -1 - left; 1 - right
        bool _ended;

        std::chrono::steady_clock::time_point _start_time;
    public:

        Blast();

        int leftright() {return _leftright;}
        bool ended() {return _ended;}
        void setRunning() {_ended = false;}

        void Update();
        void init();
        std::string name();

};

#endif