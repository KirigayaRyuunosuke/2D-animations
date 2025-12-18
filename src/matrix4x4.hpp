#pragma once

#include <iostream>
#include "vector4.hpp"

namespace X2D{

    class Matrix4x4{
    private:
        Vector4 elems[4]{
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
        };

    public:
        Matrix4x4(){};
        ~Matrix4x4(){};

        Matrix4x4 operator+(Matrix4x4 second);

        Matrix4x4 operator*(Matrix4x4 second);

        Vector4 operator*(Vector4 Matrix4x4);

        void indentity();
        void zero();

        void rotationX(float,float);
        void rotationY(float,float);
        void rotationZ(float,float);

        void conversion(float,float,float);
        void translation(float,float,float);
        void scaleMatrix(float,float,float);

        void debug(){
            for(int i = 0; i < 4; i++){
                std::cout << "Row " << i+1 << ": ";
                elems[i].debug();
            }
        }

    };
}
