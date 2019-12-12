#include <iostream>
#include "Player.hh"
#include "AG.hh"

Player::Player() {
    _start_time = std::chrono::steady_clock::now();
    _game_time = _start_time;
    _updown = -1;
    _leftright = -1;
    _x = MAXX/2;
    _y = MAXY/2;
    
    _moveCount = 0;
}

void Player::Update() {
    // Calculates time difference
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - _start_time).count();
    
    //std::cerr << "Score: " << _score << std::endl;

    if(_y == 1 && _updown == -1){
        _updown = 1;
    }else if(_y == MAXY-1 && _updown == 1){
        _updown = -1;
    }
    if(_x == 0 && _leftright == -1){
        _x = MAXX-1;
    }else if(_x == MAXX && _leftright == 1){
        _x = 1;
    }

    if(elapsed < refresh_time){
        return;
    }
    _moveCount++;
    if(myAg.enabled){
        myAg.makeMove(*this);
    }

    _score = (int)std::chrono::duration_cast<std::chrono::milliseconds>(now - _game_time).count();
    _start_time = now;

    _y += _updown;
    _x += _leftright; 
    if(_x == 0 && _leftright == -1){
        _x = MAXX-1;
    }else if(_x == MAXX && _leftright == 1){
        _x = 1;
    }
}

void Player::Change_dir(int key) {
    if(key == 122){
        _leftright = -1;
    }
    else if (key == 120){
        _leftright = 1;
    }
}