#include "shape.hpp"

namespace X2D {
    Shape::Shape(){
        rotation = {0,0,0,1};
        position = {0,0,10,1};
        scaleVec = {1,1,1,1};
    }

    void Shape::reset(){
        Shape();
    }

    void Shape::rotate(float X, float Y, float Z){
        rotation.x += X;
        if(rotation.x >= 3.14)
            rotation.x -= 6.28;

        rotation.y += Y;
        if(rotation.y >= 3.14)
            rotation.y -= 6.28;

        rotation.z += Z;
        if(rotation.z >= 3.14)
            rotation.z -= 6.28;

    };

    void Shape::move(float X, float Y, float Z){
        position.x += X;
        position.y += Y;
        position.z += Z;
    };

    void Shape::scale(float X, float Y, float Z){
        scaleVec.x += X;
        scaleVec.y += Y;
        scaleVec.z += Z;
    };

    void Shape::setRotation(float X, float Y, float Z){
        rotation.x = X;
        rotation.y = Y;
        rotation.z = Z;
    };

    void Shape::setPosition(float X, float Y, float Z){
        position.x = X;
        position.y = Y;
        position.z = Z;
    };

    void Shape::setScale(float X, float Y, float Z){
        scaleVec.x = X;
        scaleVec.y = Y;
        scaleVec.z = Z;
    };
}
