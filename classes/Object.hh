#ifndef OBJECT_HH
#define OBJECT_HH

#include "Entity.hh"

class Object : public Entity {
    protected:
        int _x, _y;
        int _pastx, _pasty;

        virtual void Update() = 0;

    public:
        Object() {};

        virtual void init() = 0;

        // Getters and setters
        int x() {return _x;}
        int y() {return _y;}
        int pastx() {return _pastx;}
        int pasty() {return _pasty;}

        virtual std::string name() = 0;
};

#endif