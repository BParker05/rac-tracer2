#pragma once

#include "tuple.h"

class Sphere{
    public:

        int id;
        Tuple origin = Point(0,0,0);

        Sphere() = default;

        Sphere(int id){
            this->id = id;
        }
};