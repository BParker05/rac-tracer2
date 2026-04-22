#pragma once

#include "tuple.h"
#include "matrix.h"

class Sphere{
    public:

        int id;
        Matrix transformation = identityMatrix();

        Sphere() = default;

        Sphere(int id){
            this->id = id;
        }

        void setTransform(Matrix t){
            this->transformation = this->transformation * t;
        }
};