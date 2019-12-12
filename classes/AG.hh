// Own codes
#ifndef AGIncluded
#define AGIncluded
#include "globalconstants.hh"
#include "Player.hh"

// Libs
#include <algorithm>
#include <vector>
#include <chrono> // time libs
#include <cstdio>



class AG{
    private:
        int _moveQuantity, _maxScore; //scores
        int _threshold, _bias; //algorithm parameters
        
        int _currentMove; //aux vars

        std::vector <std::pair<int, int>> _movements; // direction, moveCount
    public:

        AG();

        int makeMove(Player P);

        void save();
        void load();

        void endGame(Player P);
        
        bool enabled;
};

#endif