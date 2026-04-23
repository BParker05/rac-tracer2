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

    Tuple rayOrigin = Point(0,0,-5);
    float wallZ = 10;
    float wallSize = 7;
    float canvasPixels = 200;
    float pixelSize = wallSize / canvasPixels;
    float half = wallSize / 2;

    Canvas c = Canvas(canvasPixels, canvasPixels);
    Colour red = Colour(1,0,0);
    Sphere s = Sphere(0);

    for (int i = 0; i < canvasPixels; i++){
        float worldY = half - pixelSize * i;

        for (int j = 0; j < canvasPixels; j++){
            float worldX = -half + pixelSize * j;

            Tuple position = Point(worldX, worldY, wallZ);
            Ray r = Ray(rayOrigin, normalize(position - rayOrigin));
            std::vector<Intersection> xs = intersect(r,s);

            if (xs.size() > 0){
                c.writePixel(j,i,Colour(j/200.0,i/200.0,j/200.0));
            } else {
                c.writePixel(j,i,Colour(0,0,0));
            }
        }
    }

    c.writePPM();

    return 0; 
}