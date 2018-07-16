#include <iostream>

#include "Matrix.h"

int main() {

    std::cout << "Hello, World!!!" << std::endl;

    std::vector<double> vector = {1, 2, 3};
    std::vector<double> vector1 = {5, 2, 3};



//    Matrix matrix1 = Matrix({{10, 6, 2, 1}, {2, 5, 4, 2}, {2, 8, 21, 3}, {3, 1, 66, 7}});
//
//    matrix1.display_matrix();
//
//    std::cout << "\n";
//
//    Matrix matrix2 = Matrix({{4, 1, 2, 11}, {4, 15, 18, 12}, {7, 10, 9, 3}, {9, 7, 15, 10}});

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


//    Matrix matrix4 = matrix1*matrix2;
//
//    matrix4.display_matrix();


//    Matrix matrixA = Matrix({{2, 2}, {1, 1}});

    Matrix matrixB = Matrix({0, 3, 1});

    matrixB.display_matrix();





    std::cout << matrixB.get_determinant() << std::endl;

    for (double e : matrixB.get_dimensions()) {

        std::cout << e << "\n";

    }

    return 0;
}