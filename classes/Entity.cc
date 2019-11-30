#include "Entity.hh"

Entity::Entity() {
    _x = 0;
    _y = 0;
    _pastx = -1;
    _pasty = -1;
    _isReady = false;
    _isRunning = true;    
}

void Entity::run() {
    std::cout << "[" << name() << "]" << " Thread is running!\n";

    init();

    while (_isRunning) {
        Update();

        while (_isReady == false); // Wait for window update
    }

    finish();
}

void Entity::setReady() {
    _readyMutex.lock();
    _isReady = true;
    _readyMutex.unlock();
}

void Entity::finish() {
    
}