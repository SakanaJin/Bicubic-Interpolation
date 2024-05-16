#include <iostream>
#include <vector>

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
        
        return 0.00;//delete later///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
};

class BicubicInterpolation{
private:
    std::vector<std::vector<double>> dfdx;
    std::vector<std::vector<double>> dfdy;
    std::vector<std::vector<double>> df2dxdy;
    std::vector<std::vector<Function>> functions;
public:
    BicubicInterpolation(std::vector<double> xval, std::vector<double> yval, std::vector<std::vector<double>> fval){

    }
};

int main(){
    std::cout << "working";
    return 0;
}