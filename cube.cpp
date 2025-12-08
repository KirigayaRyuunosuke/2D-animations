#include <iostream>
#include <thread>
#include <chrono>
#include "src/Xmath.hpp"

constexpr int TabSize = 101;

void drawLine(char table[TabSize][TabSize], int xa, int ya, int xb, int yb) {
    double dx = xb - xa;
    double dy = yb - ya;

    double steps = std::max(std::abs(dx), std::abs(dy));

    if (steps == 0) {
        if(xa >= 0 && xa < TabSize && ya >= 0 && ya < TabSize)
             table[ya][xa] = 'o';
        return;
    }

    double xInc = dx / steps;
    double yInc = dy / steps;

    double x = xa;
    double y = ya;

    for (int i = 0; i <= steps; i++) {
        int rX = Xmath::round(x);
        int rY = Xmath::round(y);
        table[rY + TabSize/2][rX + TabSize/2] = 'o';
        x += xInc;
        y += yInc;
    }
}

class Vector{
private:
    constexpr static double sinConst = Xmath::sin(0.049);
    constexpr static double cosConst = Xmath::cos(0.049);
    double x{0}, y{0}, z{0};
public:
    Vector(int newX, int newY, int newZ = 0){
        x = newX; y = newY; z = newZ;
    }
    void scale(double scalar){
        x *= scalar;
        y *= scalar;
        z *= scalar;
    }
    void rotate(){
        double xa{1},xb{0},ya{0},yb{1};
        xa = x * cosConst;
        ya = x * sinConst;
        xb = y * (-1) * sinConst;
        yb = y * cosConst;
        x = xa + xb;
        y = ya + yb;
    }
    void projectOn(char table[TabSize][TabSize]){
        table[ TabSize/2 + Xmath::round(y) ][ TabSize/2 + Xmath::round(x) ] = 'X';
    }
    int getX(){
        return Xmath::round(x);
    }
    int getY(){
        return Xmath::round(y);
    }
    int getZ(){
        return Xmath::round(z);
    }
    void print(){
        std::cout << "x: " << x << " y: " << y << " z: " << z << "\n";
    }
};

class Square{
private:
    Vector vectors[4]{
    {1,1},{-1,1},{-1,-1},{1,-1}
    };
public:
    void scale(double scalar){
        for (int i = 0; i < 4 ; i++) {
            vectors[i].scale(scalar);
        }
    }
    void rotate(){
        for (int i = 0; i < 4 ; i++) {
            vectors[i].rotate();
        }
    }
    void projectOn(char table[TabSize][TabSize]){
        for (int i = 0; i < 4 ; i++) {
            if( i == 3 )
                drawLine(table, vectors[i].getX(), vectors[i].getY(), vectors[0].getX(), vectors[0].getY() );
            else
                drawLine(table, vectors[i].getX(), vectors[i].getY(), vectors[i+1].getX(), vectors[i+1].getY() );
        }
    }
    Vector getA(){
        return vectors[0];
    }
    Vector getB(){
        return vectors[1];
    }
    Vector getC(){
        return vectors[2];
    }
    Vector getD(){
        return vectors[3];
    }

};



class Cube{
private:
    const double c = 200;
    Square base;
    Vector buildingVector{0,0,1};
    Vector resulting[8]{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    Vector observer = {0,1};
    Vector done[8]{{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};

    double distances[4];

    void getDistance(Vector tab[4]){
        for(int i = 0; i < 4; i++){
            distances[i] = Xmath::newtonRoot( Xmath::power(tab[i].getX(),2) + Xmath::power((observer.getY() - tab[i].getY()), 2) );
        }
    }

public:
    void scale(double scalar){
        base.scale(scalar);
        buildingVector.scale(scalar);
        observer.scale(5*scalar);
    }
    void rotate(){
        base.rotate();
    }
    void projectOn(char table[TabSize][TabSize]){

        Vector tab[4]{base.getA(),base.getB(),base.getC(),base.getD()};


        getDistance(tab);

        for(int i = 0; i < 4; i++){

            resulting[2 * i]        = {tab[i].getX(), tab[i].getY(), int((double(buildingVector.getZ()) * c/distances[i])) };
            resulting[(2 * i) + 1]  = {tab[i].getX(), tab[i].getY(), int((double(buildingVector.getZ()) * c/(distances[i])*(-1)))  };
            //points stored in resulting

            // done[2 * i] = { (resulting[ 2 * i].getX()*(-1) + resulting[2 * i].getY()) , (resulting[ 2 * i].getY() + resulting[2 * i].getZ()) };
            // done[(2 * i) + 1] = { (resulting[(2 * i) + 1].getX()*(-1) + resulting[(2 * i) + 1].getY()) , (resulting[(2 * i) + 1].getY() + resulting[(2 * i) + 1].getZ()) };

            done[2*i] = {resulting[2 * i].getX(),resulting[2 * i].getZ()};
            done[2*i + 1] = {resulting[2 * i + 1].getX(),resulting[2 * i + 1].getZ()};

            drawLine(table, done[2*i].getX(), done[2*i].getY(), done[2*i + 1].getX(), done[2*i + 1].getY() );

         }
            {
            int i = 6;
            drawLine(table, done[i].getX(), done[i].getY(), done[0].getX(), done[0].getY() );
            drawLine(table, done[i+1].getX(), done[i+1].getY(), done[1].getX(), done[1].getY() );
            for (i = 0; i < 6 ; i++) {
                    drawLine(table, done[i].getX(), done[i].getY(), done[i+2].getX(), done[i+2].getY() );
            }

            }

        }



    void print(){
        std::cout << "Wierzcholki:\n";
        for(int i = 0; i < 8; i++){
            std::cout << i+1 << ": "; resulting[i].print();
        }
        std::cout << "Wierzcholki w 2D:\n";
        for(int i = 0; i < 8; i++){
            std::cout << i+1 << ": "; done[i].print();
        }
        std::cout << "\nOdleglosci:\n";
        for(int i = 0; i < 4; i++){
            std::cout << i+1 << ": "<< distances[i] << "\n";
        }
    }

};


void clearTable(char table[TabSize][TabSize]){
    for(int i = 0; i < TabSize; i++)
        for(int j = 0; j < TabSize; j++)
            table[i][j] = ' ';

}

void printTable(char table[TabSize][TabSize]){
    for(int i = 0; i < TabSize; i++){
        for(int j = 0; j < TabSize; j++){
            std::cout << table[i][j];
        }
        std::cout << "\n";
    }
}

void swap(int &a, int &b){
    int temp{a}; a = b; b = temp;
}

int main(){
    char table[TabSize][TabSize];
    clearTable(table);

    // Square square;
    // square.scale(10);

    Cube cube;
    cube.scale(15);

    printTable(table);
    clearTable(table);

    // for(int i = 0; i < 4; i++){
    while(1){
        std::cout << "\033[2J\033[1;1H";
        cube.rotate();
        cube.projectOn(table);
        printTable(table);
        clearTable(table);
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    return 0;
}
