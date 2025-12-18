#pragma once

#include "shape.hpp"

namespace X2D {

    class Cube : public Shape {
    public:
        Cube(){
            verticies = {
            { 1, 1, 1},
            {-1, 1, 1},
            { 1,-1, 1},
            {-1,-1, 1},
            { 1, 1,-1},
            {-1, 1,-1},
            { 1,-1,-1},
            {-1,-1,-1},
            };
            indexedVerticies = {
            {0,2,1,4},
            {3,1,2,7},
            {5,1,4,7},
            {6,2,4,7}
            };
        }
        ~Cube(){};
    };
}
