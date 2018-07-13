#include <iostream>

#include "Matrix.h"

int main() {

    std::cout << "Hello, World!!!" << std::endl;

    std::vector<double> vector = {1, 2, 3};
    std::vector<double> vector1 = {5, 2, 3};



    Matrix matrix1 = Matrix({{2, 2, 2}, {2, 5, 2}, {2, 2, 2}});

    matrix1.display_matrix();

    std::cout << "\n";

    Matrix matrix2 = Matrix({{1, 1, 1}, {2, 2, 2}, {3, 3, 3}});

    matrix2.display_matrix();

    std::cout << "\n";

    Matrix matrix3 = matrix1 - matrix2;

    matrix3.display_matrix();

    std::cout << "\n";


    matrix3.display_transpose();



    return 0;
}