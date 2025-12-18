#include "vector4.hpp"
#include "matrix4x4.hpp"

namespace X2D{
    Matrix4x4 Matrix4x4::operator+(Matrix4x4 second){
        Matrix4x4 result{*this};
        for(int i = 0; i < 4; i++){
            result.elems[i] = result.elems[i] + second.elems[i];
        }
        return result;
    };

    Matrix4x4 Matrix4x4::operator*(Matrix4x4 second){
        Matrix4x4 result;
        result.zero();
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    result.elems[i].coords[j] += this->elems[i].coords[k] * second.elems[k].coords[j];
                }
            }
        }
        return result;
    };

    Vector4 Matrix4x4::operator*(Vector4 vector4){
        Vector4 result{0.0,0.0,0.0,0.0};
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                result.coords[i] += this->elems[i].coords[j] * vector4.coords[j];
            }
        }
        return result;
    }

    void Matrix4x4::indentity(){
        elems[0] = {1.0,0.0,0.0,0.0};
        elems[1] = {0.0,1.0,0.0,0.0};
        elems[2] = {0.0,0.0,1.0,0.0};
        elems[3] = {0.0,0.0,0.0,1.0};
    }

    void Matrix4x4::zero(){
        elems[0] = {0.0,0.0,0.0,0.0};
        elems[1] = {0.0,0.0,0.0,0.0};
        elems[2] = {0.0,0.0,0.0,0.0};
        elems[3] = {0.0,0.0,0.0,0.0};
    }

    void Matrix4x4::rotationX(float sinValue, float cosValue){
        elems[0] = {1.0, 0.0, 0.0, 0.0};
        elems[1] = {0.0, cosValue, -(sinValue), 0.0};
        elems[2] = {0.0, sinValue, cosValue, 0.0};
        elems[3] = {0.0, 0.0, 0.0, 1.0};
    }

    void Matrix4x4::rotationY(float sinValue, float cosValue){
        elems[0] = {cosValue, 0.0, sinValue, 0.0};
        elems[1] = {0.0, 1.0, 0.0, 0.0};
        elems[2] = {-(sinValue), 0.0, cosValue, 0.0};
        elems[3] = {0.0, 0.0, 0.0, 1.0};
    }

    void Matrix4x4::rotationZ(float sinValue, float cosValue){
        elems[0] = {cosValue, -(sinValue), 0.0, 0.0};
        elems[1] = {sinValue, cosValue, 0.0, 0.0};
        elems[2] = {0.0, 0.0, 1.0, 0.0};
        elems[3] = {0.0, 0.0, 0.0, 1.0};
    }

    void Matrix4x4::conversion(float A, float B,float d){
        elems[0] = {1.0,0.0,0.0,0.0};
        elems[1] = {0.0,1.0,0.0,0.0};
        elems[2] = {0.0,0.0, A, B};
        elems[3] = {0.0,0.0,1/d,0.0};

    }

    void Matrix4x4::translation(float X, float Y,float Z){
        elems[0] = {1.0,0.0,0.0, X };
        elems[1] = {0.0,1.0,0.0, Y };
        elems[2] = {0.0,0.0,1.0, Z };
        elems[3] = {0.0,0.0,0.0,1.0};
    }

    void Matrix4x4::scaleMatrix(float X, float Y,float Z){
        elems[0] = { X ,0.0,0.0,0.0};
        elems[1] = {0.0, Y ,0.0,0.0};
        elems[2] = {0.0,0.0, Z ,0.0};
        elems[3] = {0.0,0.0,0.0,1.0};
    }

}
