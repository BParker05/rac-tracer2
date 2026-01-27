#pragma once

class Tuple{
    public:
        float x;
        float y;
        float z;
        float w;

        Tuple() = default;

        Tuple(float x, float y, float z, float w){
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        Tuple operator+(Tuple a){
            return Tuple(this->x + a.x, this->y + a.y, this->z + a.z, this->w + a.w);
        }

        Tuple operator-(Tuple a){
            return Tuple(this->x - a.x, this->y - a.y, this->z - a.z, this->w - a.w);
        }

        Tuple operator*(Tuple a){
            return Tuple(this->x * a.x, this->y * a.y, this->z * a.z, this->w * a.w);
        }

        Tuple operator/(Tuple a){
            return Tuple(this->x / a.x, this->y / a.y, this->z / a.z, this->w / a.w);
        }
};

Tuple Point(float x, float y, float z){
    Tuple point = Tuple(x,y,z,1.0f);
    return point;
}

Tuple Vector(float x, float y, float z){
    Tuple vector = Tuple(x,y,z,0.0f);
    return vector;
}