#include <iostream>

#include "Matrix.h"

int main() {

    std::cout << "Hello, World!!!" << std::endl;

    std::vector<double> vector = {1, 2, 3};
    std::vector<double> vector1 = {5, 2, 3};



    Matrix matrix1 = Matrix({{10, 6, 2}, {2, 5, 4}, {2, 8, 21}});

    matrix1.display_matrix();

    std::cout << "\n";

    Matrix matrix2 = Matrix({{1, 2, 11}, {15, 18, 12}, {10, 9, 3}});

//    matrix2.display_matrix();
//
//    std::cout << "\n";
//
//    matrix2.display_transpose();
//
//    std::cout << "\n";
//
//    matrix2.display_columns();
//
//    std::cout << "\n";
//
//    Matrix matrix3 = matrix1 - matrix2;
//
//    matrix3.display_matrix();
//
//    std::cout << "\n";


    Matrix matrix4 = matrix1*matrix2;

    matrix4.display_matrix();



    return 0;
}