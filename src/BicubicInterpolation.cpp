//4 by 4 grid will be split into 9 functions with derivatives and coefficients being global variables.//
//this design limits the size of interpolation to a 4x4 square which is sub-optimal and should be changed later//
//possibly a "function" class could be created that stores the coefficients of that quadrant//
//This could allow bicubic functions that are more than 4x4 and/or rectangular//
//defining "function" inside of BicubicInterpolation might be a good idea so I wont have to deal with header files//
//input should look something like BicubicInterpolatingFunction(double xval[], double yval[], doulbe fval[][])//

#include <iostream>
#include <vector>

class Function{
private:
    std::vector<std::vector<double>> coefficients;
public:
    Function(){

    }
};

class BicubicInterpolation{
private:
    std::vector<std::vector<double>> dfdx;
    std::vector<std::vector<double>> dfdy;
    std::vector<std::vector<double>> df2dxdy;
    std::vector<Function> functions;
public:
    BicubicInterpolation(std::vector<double> xval, std::vector<double> yval, std::vector<std::vector<double>> fval){

    }
};

int main(){
    std::cout << "working";
    return 0;
}