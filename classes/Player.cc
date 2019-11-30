#include "Player.hh"

Player::Player() {

}

std::string Player::name() {
    return "Player";
}

void Player::init() {
    _start_time = std::chrono::steady_clock::now();
    _updown = -1;
    _leftright = -1;
    _x = MAXX/2;
    _y = MAXY/2;
    _pastx = 0;
    _pasty = 0;
}

void Player::Update() {

    _readyMutex.lock();
    _isReady = false;

    // Calculates time difference
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - _start_time).count();

    if(_y == 1 && _updown == -1){
        _updown = 1;
    }else if(_y == MAXY-1 && _updown == 1){
        _updown = -1;
    }
    if(_x == 0 && _leftright == -1){
        _pastx = _x;
        _x = MAXX-1;
    }else if(_x == MAXX && _leftright == 1){
        _pastx = _x;
        _x = 1;
    }

    while(elapsed < refresh_time){
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - _start_time).count();
    }

    _start_time = std::chrono::steady_clock::now();

    _pastx = _x;
    _pasty = _y;

    _y += _updown;
    _x += _leftright; 
    if(_x == 0 && _leftright == -1){
        _x = MAXX-1;
    }else if(_x == MAXX && _leftright == 1){
        _x = 1;
    }
    _readyMutex.unlock();
}

void Player::Change_dir(int key) {
    if(key == 122){
        _mutex.lock();
        _leftright = -1;
        _mutex.unlock();
    }
    else if (key == 120){
        _mutex.lock();
        _leftright = 1;
        _mutex.unlock();
    }
}