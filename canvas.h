#pragma once

#include <vector>
#include <fstream>
#include "colour.h"

class Canvas{
    public:
        int width;
        int height;
        std::vector<std::vector<Colour>> pixels;

        Canvas() = default;

        Canvas(int width, int height){
            this->width = width;
            this->height = height;


            for (int i = 0; i < height; i++){
                this->pixels.push_back(std::vector<Colour>());
                for (int j = 0; j < width; j++){
                    this->pixels[i].push_back(Colour(0,0,0));
                }
            }
        }

        void writePixel(int x, int y, Colour c){
            this->pixels[y][x] = c;
        }

        Colour pixelAt(int x,int y){
            return this->pixels[y-1][x-1];
        }

        void writePPM(){
            std::ofstream myFile;
            myFile.open("image.ppm");
            myFile << "P3\n" << this->width << " " << this->height << "\n255\n";
            for (int i = 0; i < pixels.size(); i++) {
                for (int j = 0; j < pixels[i].size(); j++)
                    myFile << pixels[i][j];
                myFile << std::endl;
            }
            myFile.close();
        }
};