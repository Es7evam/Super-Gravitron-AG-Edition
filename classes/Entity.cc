#include "Entity.hh"

Entity::Entity() {
    _isReady = false;
    _isRunning = true;    
}

void Entity::run() {
    std::cout << "[" << name() << "]" << " Thread is running!\n";

    init();

    while (_isRunning) {
        Update();

        while (_isReady == false);
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