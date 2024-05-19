#include <iostream>
#include <vector>
#include <math.h>

class Function{
private:
    std::vector<std::vector<double>> coefficients;
    std::vector<std::vector<int>> A1 = {{1,0,0,0},{0,0,1,0},{-3,3,-2,-1},{2,-2,1,1}};
    std::vector<std::vector<int>> A2 = {{1,0,-3,2},{0,0,3,-2},{0,1,-2,1},{0,0,-1,1}};
public:
    //This is not very well optimized something like strassen method could make this faster and simpler//////////////////////////////////////////////////////////////////////
    Function(std::vector<std::vector<double>> funcvals){
        std::vector<std::vector<double>> temp;
        for(int i = 0; i < A1.size(); i++){
            for(int j = 0; j < funcvals.at(0).size(); j++){
                for(int k = 0; k < A1.at(0).size(); k++){
                    temp[i][j] += A1[i][k] * funcvals[k][j];
                }
            }
        }

        for(int i = 0; i < temp.size(); i++){
            for(int j = 0; j < A2.at(0).size(); j++){
                for(int k = 0; k < temp.at(0).size(); k++){
                    coefficients[i][j] += temp[i][k] * A2[k][j];
                }
            }
        }
    }

    double interpolate(double x, double y){
        double interpolated = 0;

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                interpolated += coefficients[i][j] * pow(x, i) * pow(y, j);
            }
        }
        
        return interpolated;
    }
};

class BicubicInterpolation{
private:
    std::vector<std::vector<double>> dfdx;
    std::vector<std::vector<double>> dfdy;
    std::vector<std::vector<double>> df2dxdy;
    std::vector<std::vector<Function>> functions;

    double partialDerivative(std::vector<double> xval, std::vector<double> fval, int index){
        double derivative;
        if(index == 0){
            derivative = (fval[1] - fval[0]) / (xval[1] - xval[index]);
            return derivative;
        }
        else if(index == xval.size() - 1){
            derivative = (fval[xval.size() -1] - fval[xval.size() -2]) / (index - xval[xval.size()-2]);
            return derivative;
        }
        else{
            derivative = ((fval[index] - fval[index-1]) / (xval[index] - xval[index-1]) + (fval[index+1] - fval[index]) / (xval[index+1] - xval[index]))/2;
            return derivative;
        }
    }
public:
    BicubicInterpolation(std::vector<double> xval, std::vector<double> yval, std::vector<std::vector<double>> fval){
        //make dfdx//
        //make dfdy//
        //make df2dxdy//
        //make functions//
    }

    double interpolate(double x, double y){
        return 0.00; //delete later////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
};

int main(){
    std::cout << "working";
    return 0;
}