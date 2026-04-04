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

    Canvas c = Canvas(100,100);
    Colour w = Colour(1,1,1);
    float r = 35;

    Tuple twelve = Point(0,1,0);
    Tuple eleven = rotationZ(11 * PI/6) * twelve;
    Tuple ten = rotationZ(10 * PI/6) * twelve;
    Tuple nine = rotationZ(9 * PI/6) * twelve;
    Tuple eight = rotationZ(8 * PI/6) * twelve;
    Tuple seven = rotationZ(7 * PI/6) * twelve;
    Tuple six = rotationZ(6 * PI/6) * twelve;
    Tuple five = rotationZ(5 * PI/6) * twelve;
    Tuple four = rotationZ(4 * PI/6) * twelve;
    Tuple three = rotationZ(3 * PI/6) * twelve;
    Tuple two = rotationZ(2 * PI/6) * twelve;
    Tuple one = rotationZ(PI/6) * twelve;


    c.writePixel(twelve.x * r + 50, twelve.y * r + 50, w);
    c.writePixel(eleven.x * r + 50, eleven.y * r + 50, w);
    c.writePixel(ten.x * r + 50, ten.y * r + 50, w);
    c.writePixel(nine.x * r + 50, nine.y * r + 50, w);
    c.writePixel(eight.x * r + 50, eight.y * r + 50, w);
    c.writePixel(seven.x * r + 50, seven.y * r + 50, w);
    c.writePixel(six.x * r + 50, six.y * r + 50, w);
    c.writePixel(five.x * r + 50, five.y * r + 50, w);
    c.writePixel(four.x * r + 50, four.y * r + 50, w);
    c.writePixel(three.x * r + 50, three.y * r + 50, w);
    c.writePixel(two.x * r + 50, two.y * r + 50, w);
    c.writePixel(one.x * r + 50, one.y * r + 50, w);

    c.writePPM();
    
    return 0; 
}