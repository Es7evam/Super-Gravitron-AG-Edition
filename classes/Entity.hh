#ifndef ENTITY_HH
#define ENTITY_HH

#include <iostream>
#include <string>
#include <mutex>

class Entity {
    private:
        bool _isReady;

    protected:
        std::mutex _readyMutex;
        int _x, _y;
        int _pastx, _pasty;
        bool _isRunning;
        
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
        int lastX() {return _pastx;}
        int lastY() {return _pasty;}
        int isReady() {return _isReady;}
        void setReady();
        virtual std::string name() = 0;
};

#endif