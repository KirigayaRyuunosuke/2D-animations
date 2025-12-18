#pragma once
#include "shape.hpp"
#include "matrix4x4.hpp"

namespace X2D{
    class Renderer{
    private:
        int screenY;
        int screenX;

        char** screen;
        float** depth;

        float f{100}, n{0.1}, d{1};     //camera settings
        float A, B;
        Matrix4x4 conversionMatrix;

        void initialize();
        void drawLine(int,int,int,int,char = 'o');

    public:
        Renderer(const int size);
        ~Renderer();

        void clear();
        void print();

        void render(Shape*);
    };
}
