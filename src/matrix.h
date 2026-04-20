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
                    this->values[i].push_back(input[i][j]);
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
            float det = 0;

            if(this->values.size() == 2){
                det = this->values[0][0] * this->values[1][1] - this->values[0][1] * this->values[1][0];
                return det;
            }

            for(int col = 0; col < this->values.size(); col++){
                det += this->values[0][col] * this->cofactor(0,col);
            }
            return det;
            }

        Matrix submatrix(int row, int column){
	        Matrix tmp = Matrix(this->values);

            tmp.values.erase(tmp.values.begin() + row);

            for(int i = 0; i < tmp.values.size(); i++){
                tmp.values[i].erase(tmp.values[i].begin() + column);
            }

            return tmp;
        }

        float minor(int row, int column){
            return this->submatrix(row,column).determinant();
        }

        float cofactor(int row, int column){
            if((row + column) % 2 == 0){
                return this->minor(row, column);
            } else {
                return -this->minor(row, column);
            }
        }

        bool isInvertible(){
            if(this->determinant() == 0){
                return false;
            }
            return true;
        }

        Matrix inverse(){
            Matrix tmp = Matrix(this->rows, this->columns);
            float det = this->determinant();

            for(int i = 0; i < this->values.size(); i++){
                for(int j = 0; j < this->values[0].size(); j++){
                    float c = this->cofactor(i,j);
                    tmp.values[j][i] = c / det;
                }
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
            Matrix tmp = Matrix(4,4);

            for (int i = 0; i < tmp.values.size(); i++){
                tmp.values[i][0] = this->values[i][0] * a.x +
                            this->values[i][1] * a.y +
                            this->values[i][2] * a.z +
                            this->values[i][3] * a.w;
            }

            return Tuple(tmp.values[0][0], tmp.values[1][0], tmp.values[2][0], tmp.values[3][0]);
        }

        
};

const float PI = 2 * std::acos(0.0);

Matrix identityMatrix() {
    std::vector<std::vector<float>> tmp = {{1,0,0,0},
                                            {0,1,0,0},
                                            {0,0,1,0},
                                            {0,0,0,1}};

    return Matrix(tmp);
}

Matrix translation(float x, float y, float z){
    Matrix tmp = identityMatrix();
    tmp.values[0][3] = x;
    tmp.values[1][3] = y;
    tmp.values[2][3] = z;

    return Matrix(tmp);
}

Matrix scaling(float x, float y, float z){
    Matrix tmp = identityMatrix();
    tmp.values[0][0] = x;
    tmp.values[1][1] = y;
    tmp.values[2][2] = z;

    return Matrix(tmp);
}

Matrix rotationX(float radian) {
	Matrix tmp = identityMatrix();
	tmp.values[1][1] = cos(radian);
	tmp.values[1][2] = -sin(radian);
	tmp.values[2][1] = sin(radian);
	tmp.values[2][2] = cos(radian);

	return tmp;
}

Matrix rotationY(float radian) {
	Matrix tmp = identityMatrix();
	tmp.values[0][0] = cos(radian);
	tmp.values[0][2] = sin(radian);
	tmp.values[2][0] = -sin(radian);
	tmp.values[2][2] = cos(radian);

	return tmp;
}

Matrix rotationZ(float radian) {
	Matrix tmp = identityMatrix();
	tmp.values[0][0] = cos(radian);
	tmp.values[0][1] = -sin(radian);
	tmp.values[1][0] = sin(radian);
	tmp.values[1][1] = cos(radian);

	return tmp;
}

Matrix shearing(float xy, float xz, float yx, float yz, float zx, float zy){
    Matrix tmp = identityMatrix();
    tmp.values[0][1] = xy;
    tmp.values[0][2] = xz;
    tmp.values[1][0] = yx;
    tmp.values[1][2] = yz;
    tmp.values[2][0] = zx;
    tmp.values[2][1] = zy;

    return tmp;
}