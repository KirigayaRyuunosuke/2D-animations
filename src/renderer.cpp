#include "renderer.hpp"
#include "shape.hpp"
#include "Xmath.hpp"
#include "vector4.hpp"
#include <vector>

// int screenY;
// int screenX;
//
// char** screen;
// float** depth;

namespace X2D{
    void Renderer::drawLine(int xa, int ya, int xb, int yb, char characterToFill) {
        double dx = xb - xa;
        double dy = yb - ya;

        double steps = std::max(std::abs(dx), std::abs(dy));

        if (steps == 0) {
            if(xa >= 0 && xa < screenX && ya >= 0 && ya < screenY)
                screen[ya][xa] = characterToFill;
            return;
        }

        double xInc = dx / steps;
        double yInc = dy / steps;

        double x = xa;
        double y = ya;

        for (int i = 0; i <= steps; i++) {
            int rX = Xmath::round(x);
            int rY = Xmath::round(y);

            int finalX = rX + screenX/2;
            int finalY = rY + screenY/2;

            if(finalX >= 0 && finalX < screenX && finalY >= 0 && finalY < screenY) {
                screen[finalY][finalX] = characterToFill;
            }
            x += xInc;
            y += yInc;
        }
    }

    void Renderer::initialize(){
        screen = new char* [screenY];
        depth = new float* [screenX];
        for(int i = 0; i < screenY; i++){
            screen[i] = new char[screenX];
            depth[i] = new float[screenX];
        }
    }

    void Renderer::clear(){
        for(int y = 0; y < screenY; y++){
            for(int x = 0; x < screenX; x++){
                screen[y][x] = ' ';
            }
        }
    }

    Renderer::Renderer(const int size){
        screenX = size * 2;
        screenY = size;

        A = (f+n)/(f-n);
        B = (-2*n*f)/(f-n);

        conversionMatrix.conversion(A, B, d);

        initialize();
        clear();
    }

    Renderer::~Renderer(){
        for(int i = 0; i < screenY; i++){
            delete screen[i];
            delete depth[i];
        }
        delete screen;
        delete depth;
    }

    void Renderer::print(){
        for(int y = 0; y < screenY; y++){
            for(int x = 0; x < screenX; x++){
                std::cout << screen[y][x];
            }
            std::cout << '\n';
        }
    }

    void Renderer::render(Shape* shape){

        std::vector<Vector4> transformed, list = shape->indexedVerticies;

        Vector4 raw;
        Matrix4x4 result, tmp;
        Vector4 temp = shape->position;
        float angle;
        int x1,y1,x2,y2;

        result.indentity();
        tmp.translation(temp.x, temp.y, temp.z);
        result = result * tmp;

        temp = shape->scaleVec;
        tmp.scaleMatrix(temp.x, temp.y, temp.z);
        result = result * tmp;

        angle = shape->rotation.x;
        if(angle){
            tmp.rotationX(Xmath::sin(angle), Xmath::cos(angle));
            result = result * tmp;
        }

        angle = shape->rotation.y;
        if(angle){
            tmp.rotationY(Xmath::sin(angle), Xmath::cos(angle));
            result = result * tmp;
        }

        angle = shape->rotation.z;
        if(angle){
            tmp.rotationZ(Xmath::sin(angle), Xmath::cos(angle));
            result = result * tmp;
        }

        for(size_t i = 0; i < shape->verticies.size(); i++){
            raw = shape->verticies[i];
            temp = result * raw;
            temp.toCartesian();
            transformed.push_back(temp);
        }

        for(size_t i = 0; i < shape->indexedVerticies.size(); i++){
            x1 = Xmath::round(transformed[list[i].coords[0]].x);
            y1 = Xmath::round(transformed[list[i].coords[0]].y);
            for(int j = 1; j < 4; j++){
                x2 = Xmath::round(transformed[list[i].coords[j]].x);
                y2 = Xmath::round(transformed[list[i].coords[j]].y);
                drawLine(x1, y1, x2, y2, 'o');
            }
        }
    };


}
