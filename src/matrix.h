#pragma once

#include <vector>

#include "tuple.h"

class Matrix{
    public:
        int rows;
        int columns;

        std::vector<std::vector<float>> values;

        Matrix() = default;

        Matrix(int rows, int columns){
            this->rows = rows;
            this->columns = columns;

            for (int i = 0; i < this->rows; i++){
                this->values.push_back(std::vector<float>());
                for (int j = 0; j < columns; j++){
                    this->values[i].push_back(0.0f);
                }
            }
        }

        Matrix(std::vector<std::vector<float>> input){
            this->rows = input.size();
            this->columns = input[0].size();

            for (int i = 0; i < this->rows; i++){
                this->values.push_back(std::vector<float>());
                for (int j = 0; j < columns; j++){
                    this->values[i].push_back(input[j][i]);
                }
            }
        }

        void writeValue(int row, int column, float val){
            this->values[row][column] = val;
        }

        float valueAt(int row, int column){
            return this->values[row][column];
        }

        Matrix transpose(){
            std::vector<std::vector<float>> tmp;
            for(int i = 0; i < this->values[0].size(); i++){
                tmp.push_back(std::vector<float>());
                for(int j = 0; j < this->values.size(); j++){
                    tmp[i].push_back(this->values[j][i]);
                }
            }
            return Matrix(tmp);
        }

        float determinant(){
            float a = this->values[0][0];
            float b = this->values[0][1];
            float c = this->values[1][0];
            float d = this->values[1][1];

            return a*d - b*c;
        }

        Matrix submatrix(int row, int column){
	        Matrix tmp = Matrix(this->values);

            tmp.values.erase(tmp.values.begin() + row);

            for(int i = 0; i < tmp.values.size(); i++){
                tmp.values[i].erase(tmp.values[i].begin() + column);
            }

            return tmp;
        }

        bool operator==(const Matrix &a){
            if (this->values.size() != a.values.size() || this->values[0].size() != a.values[0].size()){
                return false;
            }

            for (int i = 0; i < this->values.size(); i++){
                for (int j = 0; j < this->values[0].size(); j++){
                    if (this->values[i][j] == a.values[i][j]){
                        continue;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }

        bool operator!=(const Matrix &a){
            if (this->values.size() != a.values.size() || this->values[0].size() != a.values[0].size()){
                return true;
            }

            for (int i = 0; i < this->values.size(); i++){
                for (int j = 0; j < this->values[0].size(); j++){
                    if (this->values[i][j] == a.values[i][j]){
                        continue;
                    } else {
                        return false;
                    }
                }
            }
            return false;
        }

        Matrix operator*(const Matrix &a){
            Matrix b = Matrix(this->rows, a.columns);

            for (int i = 0; i < this->values.size(); i++){
                for (int j = 0; j < this->values[0].size(); j++){
                    // find the value we're working with
                    for (int k = 0; k < this->values[0].size(); k++){
                        b.values[i][j] += this->values[i][k] * a.values[k][j];
                    }
                }
            }
            return b;
        }

        Tuple operator*(const Tuple &a){
            return Tuple(this->values[0][0] * a.x + this->values[0][1] * a.y + this->values[0][2] * a.z + this->values[0][3] * a.w,
                        this->values[1][0] * a.x + this->values[1][1] * a.y + this->values[1][2] * a.z + this->values[1][3] * a.w,
                        this->values[2][0] * a.x + this->values[2][1] * a.y + this->values[2][2] * a.z + this->values[2][3] * a.w,
                        this->values[3][0] * a.x + this->values[3][1] * a.y + this->values[3][2] * a.z + this->values[3][3] * a.w);
        }

        
};