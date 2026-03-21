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

    std::vector<std::vector<float>> z = {{-6,1,1,6},
                                        {-8,5,8,6},
                                        {-1,0,8,2},
                                        {-7,1,-1,1}};

    Matrix a = Matrix(z);

    Matrix c = a.submatrix(2,1);

    for (int i = 0; i < c.values.size(); i++) {
        for (int j = 0; j < c.values[i].size(); j++){
            std::cout << " " << c.values[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0; 
}