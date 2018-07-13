//
// Created by Alexander Swanson on 7/12/18.
// Copyright (c) 2018, Alexander Joseph Swanson Villares
// alexjosephswanson@gmail.com
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H


#include <vector>
#include <ostream>

class Matrix {

protected:

    // The number of rows and columns.
    int num_of_rows;
    int num_of_columns;

    // The collections of the rows and the columns.
    std::vector<std::vector<double>> rows;
    std::vector<std::vector<double>> columns;

    // The vector of the elements of the matrix.
    std::vector<double> elements;

    // The dimensions of the matrix.
    std::vector<int> dimensions;


public:


    Matrix();

    // Constructor to initialize 1x0 matrix.
    explicit Matrix(std::vector<double> in_vector);

    explicit Matrix(const std::vector<std::vector<double>> &in_vectors);

    /**
     * Operator overload to return ROWS.
     * Can continue to then index a returned ROW.
     */
    std::vector<double> operator[] (int element_index);

    friend Matrix operator+ (Matrix l_matrix, const Matrix& r_matrix);

    void display_matrix();

    int get_num_of_rows() {
        return rows.size();
    }


};


#endif //MATRIX_MATRIX_H
