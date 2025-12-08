# TODO
* Add operator overload for simplifying notation
* Change drawLine args from int to class Vector
* Simplyfy (maybe) cube calculations

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

## void drawLine
This function draws lines in my result char matrix.

## class Vector
This class is heart of this project. Here we find most important methods like rotate(), scale() and projectOn().
### rotate()
I'm not assuming everyone knows about [rotation matrix](https://en.wikipedia.org/wiki/Rotation_matrix), so here is some info.
This functions is implementation os this concept to rotate vector by some angle using precalculated [sin and cos values](#xmathhpp).
### projectOn()
This methods places our point in char table.
### scale()
This is simplest possible implementation of multiplying vector by scalar.

## class Square
This class uses 4 [Vectors](#class-vector) and their methods to project square on flat matrix.

# class Cube
Finally! Now lets think about some ideas I had during programming this:
* So, how do you draw 3D shape in 2D space?
* How should I compute rotation (rotation matrix 3x3 isn't the best solution for me)
* How to add depth to your square?

Well, I kinda cheated. This is cube, but if you think about it, cube is actualy square with third dimension attached to it, so everything that is happening here is rotating square, and on each corner i compute point above and below that corner.

Ok, but what about depth? Well... If something is more far away from observer it should be smaller, so I calculate how far each corner is from observer point and scale lengh of according edge by *c/distance*, where c is some constant.

Last step is to change our 8 3D points to 8 2D point which is also done by implementing simple matrix calculations, and then project it onto our table and print it out.
