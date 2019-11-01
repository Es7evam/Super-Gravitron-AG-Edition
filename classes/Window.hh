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
    public:
        Window();

        void Update(Player P, std::pair<int, int> pastPlayer);
};
