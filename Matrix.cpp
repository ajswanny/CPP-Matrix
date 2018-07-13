//
// Created by Admin on 7/12/18.
//

#include <iostream>
#include "Matrix.h"


// The default constructor.
Matrix::Matrix() {

    this->dimensions = {0, 0};

}


// Creates a Matrix with a single row.
Matrix::Matrix(std::vector<double> in_vector) {

    // Define new dimensions.
    this->dimensions = {1, 0};

    // Append 1D vector to collection of ROWS.
    this->rows.push_back(in_vector);

    // Append every element in the 1D vector to the collection of elements.
    for (double i : in_vector) {

        this->elements.push_back(i);

    }

    // Update statistical data.
    this->num_of_rows = 1;
    this->num_of_columns = 0;

}


Matrix::Matrix(const std::vector<std::vector<double>> &in_vectors) {

    for (const std::vector row : in_vectors) {

        this->rows.push_back(row);

    }

}


std::vector<double> Matrix::operator[](int element_index) {

    return this->rows[element_index];

}


Matrix operator+(Matrix l_matrix, const Matrix &r_matrix) {

    std::vector<std::vector<double>> sums;

    for (int i = 0; i < l_matrix.rows.size(); i++) {

        std::vector<double> left_row_x = l_matrix.rows[i];
        std::vector<double> right_row_x = r_matrix.rows[i];
        std::vector<double> new_row_x;

        for (int j = 0; j < left_row_x.size(); j++) {

            new_row_x.push_back(left_row_x[j] + right_row_x[j]);


        }

        sums.push_back(new_row_x);

    }

    return Matrix(sums);

}

void Matrix::display_matrix() {

    for (std::vector<double> row : this->rows) {

        for (double e : row) {
            std::cout << e << "\t";
        }

        std::cout << "\n";

    }

}



