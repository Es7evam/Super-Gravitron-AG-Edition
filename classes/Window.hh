#include <time.h>
#include <curses.h>
#include <unistd.h>
#include <utility>
#include <iostream>
#include <termios.h> //terminal stuff

// Own codes
#include "globalconstants.hh"
#include "Player.hh"
#include "Blast.hh"

class Window{
    public:
        Window();

        bool Update(Player P, std::vector <Blast> *B,std::pair<int, int> pastPlayer);
        bool Collided(Player P, std::vector<Blast> B);
        void EndGame();
    
    private:
        std::chrono::steady_clock::time_point _lastblast ;
};
