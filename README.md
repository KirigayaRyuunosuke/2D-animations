# Important
Visit [this repo](https://github.com/KirigayaRyuunosuke/math-x) to get header file I'm using in this project.

# 2D-animations
Simple 2D rotating cube

# Know how
In this project I'm using some basic linear algebra knowledge to firstly rotate some points in space and then make them look like cube!

Now let's look a bit closer:

## Xmath.hpp
This is my experimental header file to train with some basic math functions. Here I'm using some *constexpr* function to calculate trygonometric functions on compile time instead of runtime.
```cpp
constexpr static double sinConst = Xmath::sin(0.049);
```

## class Vector
This class is heart of this project. Here we find most important methods like rotate(), scale() and projectOn().
### rotate()
I'm not assuming everyone knows about [rotation matrix](https://en.wikipedia.org/wiki/Rotation_matrix), so here is some info.
This functions is implementation os this concept to rotate vector by some angle using precalculated [sin and cos values](##Xmath.hpp)
