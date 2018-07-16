#include <iostream>

#include "Matrix.h"

int main() {

    std::cout << "Hello, World!!!" << std::endl;

    std::vector<double> vector = {1, 2, 3};
    std::vector<double> vector1 = {5, 2, 3};



    Matrix matrix1 = Matrix({{2, 2, 2}, {2, 5, 2}, {2, 2, 2}});

    matrix1.display_matrix();

    std::cout << "\n";

    Matrix matrix2 = Matrix({{1, 2, 1}, {5, 8, 2}, {10, 10, 3}});

    matrix2.display_matrix();

    std::cout << "\n";

    matrix2.display_transpose();

    std::cout << "\n";

    matrix2.display_columns();

//    Matrix matrix3 = matrix1 - matrix2;
//
//    matrix3.display_matrix();
//
//    std::cout << "\n";

    Matrix matrix4 = matrix1 * matrix2;

    matrix4.display_matrix();



    return 0;
}