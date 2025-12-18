#pragma once
#include "header.hpp"

namespace Xmath{
    constexpr uint64_t GCD(uint64_t,uint64_t);
    constexpr long factorial(long);
    constexpr double power(double, int);
    constexpr double sin(double, int = 5);
    constexpr double cos(double, int = 5);
    constexpr double tan(double, int = 5);
    constexpr double ctg(double, int = 5);
    constexpr int round(double);
    constexpr double newtonRoot(double, int = 5);






    constexpr double newtonRoot(double var, int precision){
        double result{1};
        for(int i = 0; i < precision; i++)
            result = 0.5 * (result + var/result);
        return result;
    }

    constexpr int round(double var){
        return (var > 0) ? int(var + 0.5) : int(var - 0.5);
    }

    constexpr uint64_t GCD(uint64_t a, uint64_t b) {
        while (b != 0) {
            uint64_t temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    constexpr long factorial(long number){

        long result = number;
        if(number > 1)
            result *= factorial(number - 1);
        else
            result = 1;
        return result;

        //return (number > 1) ? number *= factorial(number - 1) : number;

    }

    constexpr double power(double a, int b){

        if(b == 0)
            return 1;

        double result = a;
        if(b > 1)
            result *= power(a, b-1);

        return result;

        //return (b > 1) ? a *= power( a, b-1 ) : a;

    }

    constexpr double sin(double x, int precision){
        double result = x;

        if(precision > 0)
            result = power(-1, precision) * (power(x, (2 * precision + 1) ) / ( factorial( 2 * precision + 1) ) ) + sin(x, precision - 1);

        return result;
    };

    constexpr double cos(double x, int precision){
        double result = 1;

        if(precision > 0)
            result = power(-1, precision) * (power(x, (2 * precision) ) / ( factorial( 2 * precision) ) ) + cos(x, precision - 1);

        return result;
    };

    constexpr double tan(double x, int precision){
        double result = x;

        result = sin(x,precision)/cos(x,precision);

        return result;
    };
}
