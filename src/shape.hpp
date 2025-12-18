#pragma once

#include <vector>
#include "vector4.hpp"

namespace X2D {

    class Shape {
    protected:
    public:
        std::vector<Vector4> verticies;
        std::vector<Vector4> indexedVerticies;
        Vector4 rotation;
        Vector4 position;
        Vector4 scaleVec;
        Shape();
        virtual ~Shape(){};

        void rotate(float,float,float);
        void move(float,float,float);
        void scale(float,float,float);

        void setPosition(float,float,float);
        void setRotation(float,float,float);
        void setScale(float,float,float);

        void reset();

        void debug(){
            for(size_t i = 0; i < verticies.size(); i++){
                verticies[i].debug();
            }
        }

    };

}
