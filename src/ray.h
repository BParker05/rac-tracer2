#pragma once

#include <vector>

#include "tuple.h"
#include "sphere.h"

class Ray {
    public:
        Tuple origin;
        Tuple direction;

        Ray() = default;

        Ray(Tuple origin, Tuple direction){
            this->origin = origin;
            this->direction = direction;
        }

        Tuple position(float t){
            return this->origin + this->direction * t;

        }
};

std::vector<float> intersect(Ray r, Sphere s){
    std::vector<float> tmp = {0,0};

    Tuple sphereToRay = r.origin - Point(0,0,0);

    float a = dot(r.direction, r.direction);
    float b = 2 * dot(r.direction, sphereToRay);
    float c = dot(sphereToRay, sphereToRay) - 1;

    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0){
        return tmp;
    }

    tmp[0] = (-b - std::sqrt(discriminant)) / (2 * a);
    tmp[1] = (-b + std::sqrt(discriminant)) / (2 * a);

    return tmp;
}