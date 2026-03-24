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

    std::vector<std::vector<float>> z = {{0,9,3,0},
                                        {9,8,0,8},
                                        {1,8,5,3},
                                        {0,0,5,8}};

    std::vector<std::vector<float>> x = {{-2,1,2,3},
                                        {3,2,1,-1},
                                        {4,3,6,5},
                                        {1,2,7,8}};

    Matrix a = Matrix(z);
    Matrix b = a.transpose();

    Matrix c = a*b;

    Matrix d = c*b.inverse();
    std::cout << "a" << std::endl;
    for(int i = 0; i < b.values.size(); i++){
        for(int j = 0; j < b.values[0].size(); j++){
            std::cout << a.values[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "b" << std::endl;
    for(int i = 0; i < b.values.size(); i++){
        for(int j = 0; j < b.values[0].size(); j++){
            std::cout << b.values[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "c" << std::endl;
    for(int i = 0; i < b.values.size(); i++){
        for(int j = 0; j < b.values[0].size(); j++){
            std::cout << c.values[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "d" << std::endl;
    for(int i = 0; i < b.values.size(); i++){
        for(int j = 0; j < b.values[0].size(); j++){
            std::cout << d.values[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    return 0; 
}