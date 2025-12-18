#include "vector4.hpp"

namespace X2D{

    Vector4::Vector4(){
        x = 0; y = 0; z = 0; w = 1;
    }

    Vector4::Vector4(float a, float b, float c, float d){
        x=a; y=b; z=c; w=d;
    }

    Vector4::~Vector4(){
        return;
    }

    Vector4 Vector4::operator+(Vector4 other){
        Vector4 result{*this};
        result.x += other.x;
        result.y += other.y;
        result.z += other.z;
        return result;
    }

    Vector4 Vector4::operator*(float scalar){
        Vector4 result{*this};
        for(int i = 0; i < 3; i++){
            result.coords[i] *= scalar;
        }
        return result;
    }

    Vector4 Vector4::toCartesian(){
        // Vector4 result{
        //     x/w,y/w,z/w,w
        // };
        // return result;
        return {x/w,y/w,z/w,w};
    }
}
