#pragma once

#include "sphere.h"

class Intersection {
    public:
        float t;
        Sphere object;

        Intersection() = default;

        Intersection(float t){
            this->t = t;
            this->object = NULL;
        }

        Intersection(float t, Sphere object){
            this->t = t;
            this->object = object;
        }
};