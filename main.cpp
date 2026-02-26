#include <iostream>

#include "tuple.h"
#include "canvas.h"
#include "colour.h"
#include "environment.h"
#include "projectile.h"

Projectile tick(Environment env, Projectile proj){
    proj.position = proj.position + proj.velocity;
    proj.velocity = proj.velocity + env.gravity + env.wind;
    return proj;
};

int main(){

    /*
    Canvas canva = Canvas(10,20);

    Projectile p = Projectile(Point(0,1,0),normalize(Vector(1,1,0)));
    Environment e = Environment(Vector(0,-0.1,0), Vector(-0.01,0,0));

    while(p.position.y > 0){
        std::cout << p.position.x << " " << p.position.y << " " << p.position.z << std::endl;
        p = tick(e,p);
    }
    */

    Canvas c = Canvas(10,2);

    for (int i = 0; i < c.pixels.size(); i++) {
        for (int j = 0; j < c.pixels[i].size(); j++)
            c.pixels[i][j] = Colour(1,0.8,0.6);
    }
    

    c.writePPM();
    
}