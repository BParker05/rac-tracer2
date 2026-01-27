#include <iostream>

#include "tuple.h"

int main(){
    Tuple a = Point(1,2,3);

    std::cout<< a.x << " " << a.y << " " << a.z << " " << a.w << std::endl;

    return 0;
}