#ifndef ENTITY_HH
#define ENTITY_HH

#include <iostream>
#include <string>
#include <mutex>

class Entity {
    protected:
        std::mutex _readyMutex;
        int _x, _y;
        int _pastx, _pasty;
        bool _isRunning, _isReady;;
        
        virtual void Update() = 0;

    public:

        Entity();

        //Thread
        void run();
        virtual void init() = 0;
        virtual void finish();

        //Getters and setters
        int x() {return _x;}
        int y() {return _y;}
        int pastx() {return _pastx;}
        int pasty() {return _pasty;}
        bool isReady() {return _isReady;}
        void setReady();
        virtual std::string name() = 0;
};

#endif