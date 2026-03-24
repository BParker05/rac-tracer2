#include <iostream>
#include <vector>

#include "tuple.h"
#include "canvas.h"
#include "colour.h"
#include "environment.h"
#include "projectile.h"
#include "matrix.h"

Projectile tick(Environment env, Projectile proj){
    proj.position = proj.position + proj.velocity;
    proj.velocity = proj.velocity + env.gravity + env.wind;
    return proj;
};



int main(){

    Tuple p = Point(0,1,0);
    Matrix hq = rotationX(PI/4);
    Matrix fq = rotationX(PI/2);

    Tuple hqp = hq*p;
    Tuple fqp = fq*p;

    std::cout << fqp.x << " " << fqp.y << " " << fqp.z << std::endl;
    std::cout << hqp.x << " " << hqp.y << " " << hqp.z << std::endl;
    
    
    return 0; 
}