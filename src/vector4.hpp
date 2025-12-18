#pragma once

#include <iostream>

namespace X2D{
    class Vector4{
    private:
    public:

        union {
            struct {
                float x,y,z,w;
            };
            float coords[4];
        };

        Vector4 toCartesian();
        void toHomogeneous();


        void scale(int);

        Vector4();
        Vector4(const Vector4&) = default;
        Vector4(float,float,float,float=1);
        ~Vector4();

        Vector4 operator+(Vector4);

        Vector4 operator*(float);

        void debug(){
            std::cout << "X: " << x <<" Y: " << y << " Z: " << z << " W: " << w << '\n';
        }

    };
}
