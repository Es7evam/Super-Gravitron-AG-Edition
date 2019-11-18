#include "Blast.hh"
#include "globalconstants.hh"
#include <iostream>

Blast::Blast() {
    _start_time = std::chrono::steady_clock::now();
    _leftright = (rand()%2 == 0) ? 1 : -1;
    _ended = false;

    // Starting X and Y
    _x = (_leftright == 1) ? 1 : MAXX-1;
    _y = (rand()%(MAXY+1)) + 1;
    _pastx = _x;
}

void Blast::Update() {
    // Calculates time difference
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - _start_time).count();

    // Dá volta
    if(_x == 0 && _leftright == -1){
        _ended = true;
    }else if(_x == MAXX && _leftright == 1){
        _ended = true;
    }

    if(elapsed < refresh_time){
        return;
    }
    _start_time = std::chrono::steady_clock::now();

    _pastx = _x;
    _x += _leftright; 
    std::cerr << "Updated "<< "[" << _pastx << "," << _y << "]" << "to " << "[" << _x << "," << _y << "]" << std::endl;

    // Dá volta
    if(_x == 0 && _leftright == -1){
        _ended = true;
    }else if(_x == MAXX && _leftright == 1){
        _ended = true;
    }
}

// std::pair<Blast*,std::chrono::steady_clock::time_point> Blast::generateNew(std::chrono::steady_clock::time_point last_time){
//     auto now = std::chrono::steady_clock::now();
//     auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_time).count();

//     if(elapsed < bullet_time)
//         return std::make_pair(NULL, last_time);

//     Blast *newBlast = new(Blast);
//     return std::make_pair(newBlast, now);
// }