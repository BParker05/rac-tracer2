#include <iostream>
#include <vector>

#include "tuple.h"
#include "canvas.h"
#include "colour.h"
#include "environment.h"
#include "projectile.h"
#include "matrix.h"
#include "ray.h"
#include "intersection.h"

Projectile tick(Environment env, Projectile proj){
    proj.position = proj.position + proj.velocity;
    proj.velocity = proj.velocity + env.gravity + env.wind;
    return proj;
};



int main(){

    Ray r = Ray(Point(0,0,-5), Vector(0,0,1));
    Sphere s = Sphere(0);
    s.setTransform(translation(5,0,0));
    std::vector<Intersection> xs = intersect(r, s);

    std::cout << xs.size() << std::endl;
    std::cout << xs[0].t << std::endl;
    std::cout << xs[1].t << std::endl;

    return 0; 
}