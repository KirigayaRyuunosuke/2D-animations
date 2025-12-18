#include "src/cube.hpp"
#include "src/Xmath.hpp"
#include "src/renderer.hpp"

int main(){
    X2D::Cube cube;
    cube.scale(15,15,15);
    cube.rotate(0.0,1,0.0);
    //cube.debug();

    X2D::Renderer screen{71};
    float i = 0;

    while(1){

        std::cout << "\033[2J\033[1;1H";
        cube.rotate(0.01,0.0,0.0);
        //cube.setPosition(Xmath::sin(i)*9, Xmath::cos(i)*9, 0);

        screen.render(&cube);
        screen.print();
        screen.clear();

        i += 0.1;
        if(i >= 3.14)
            i -= 6.28;

        std::this_thread::sleep_for(std::chrono::milliseconds(12));
    }




    return 0;
}
