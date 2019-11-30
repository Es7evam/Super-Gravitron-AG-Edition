#ifndef ENTITY_HH
#define ENTITY_HH

#include <iostream>
#include <string>
#include <mutex>

class Entity {
    protected:
        std::mutex _readyMutex;
        bool _isRunning, _isReady;;
        
        virtual void Update() = 0;

    public:

        Entity();

        //Thread
        void run();
        virtual void init() = 0;
        virtual void finish();

        //Getters and setters
        bool isReady() {return _isReady;}
        void setReady();
        virtual std::string name() = 0;
};

#endif