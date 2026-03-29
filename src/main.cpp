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

    Tuple p = Point(2,3,4);

    Matrix t1 = shearing(1,0,0,0,0,0);
    Matrix t2 = shearing(0,1,0,0,0,0);
    Matrix t3 = shearing(0,0,1,0,0,0);
    Matrix t4 = shearing(0,0,0,1,0,0);
    Matrix t5 = shearing(0,0,0,0,1,0);
    Matrix t6 = shearing(0,0,0,0,0,1);

    Tuple tp1 = t1*p;
    Tuple tp2 = t2*p;
    Tuple tp3 = t3*p;
    Tuple tp4 = t4*p;
    Tuple tp5 = t5*p;
    Tuple tp6 = t6*p;

    std::cout << tp1.x << " " << tp1.y << " " << tp1.z << " " << tp1.w << std::endl;
    std::cout << tp2.x << " " << tp2.y << " " << tp2.z << " " << tp2.w << std::endl;
    std::cout << tp3.x << " " << tp3.y << " " << tp3.z << " " << tp3.w << std::endl;
    std::cout << tp4.x << " " << tp4.y << " " << tp4.z << " " << tp4.w << std::endl;
    std::cout << tp5.x << " " << tp5.y << " " << tp5.z << " " << tp5.w << std::endl;
    std::cout << tp6.x << " " << tp6.y << " " << tp6.z << " " << tp6.w << std::endl;
    
    return 0; 
}