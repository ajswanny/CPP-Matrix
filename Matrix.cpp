//
// Created by Alexander Swanson on 7/12/18.
// Copyright (c) 2018, Alexander Joseph Swanson Villares
// alexjosephswanson@gmail.com
//

#include <iostream>
#include "Matrix.h"


// The default constructor.
Matrix::Matrix() {

    this->dimensions = {0, 0};

}


// Creates a Matrix with a single row.
Matrix::Matrix(std::vector<double> in_vector) {

    // Append 1D vector to collection of ROWS.
    this->rows.push_back(in_vector);

    // Append every element in the 1D vector to the collection of elements.
    for (double i : in_vector) {

        this->elements.push_back(i);

    }

    // Define new dimensions.
    this->dimensions = {1, 0};

    // Update statistical data.
    this->num_of_rows = 1;
    this->num_of_columns = 0;

}

//
Matrix::Matrix(const std::vector<std::vector<double>> &in_vectors) {

    // Determine is the Matrix is not symmetrical (Corresponding ROW and
    // COLUMN dimensions).
    for (const std::vector<double> &row : in_vectors) {

        if (static_cast<int>(row.size()) != static_cast<int>(in_vectors[0].size())) {

            std::cout << "Created unsymmetrical Matrix." << std::endl;

        }

    }

    // Define a collection of the ROWS.
    for (const std::vector row : in_vectors) {

        this->rows.push_back(row);

    }

    // Define a collection of the COLUMNS.
    for (int i = 0; i < in_vectors.size(); i++) {

        std::vector<double> new_column_x;

        for (std::vector<double> row : in_vectors) {

            new_column_x.push_back(row[i]);

        }

        this->columns.push_back(new_column_x);

    }

    // Define new dimensions.
    this->dimensions = {
            static_cast<int>(in_vectors.size()),
            static_cast<int>(in_vectors[0].size())
    };

    // Update statistical data.
    this->num_of_rows = dimensions[0];
    this->num_of_columns = dimensions[1];

}

//
unsigned long Matrix::get_num_of_rows() {

    return this->rows.size();

}

//
void Matrix::set_num_of_rows(int num_of_rows) {

    this->num_of_rows = num_of_rows;

}

//
unsigned long Matrix::get_num_of_columns() {

    return this->columns.size();

}

//
void Matrix::set_num_of_columns(int num_of_columns) {

    this->num_of_columns = num_of_columns;

}

//
std::vector<int> Matrix::get_dimensions() {

    return this->dimensions;

}

//
void Matrix::set_dimensions(std::vector<int> dimensions) {

    this->dimensions = dimensions;

}

//
std::vector<std::vector<double>> Matrix::get_columns() {

    return this->columns;

}

//
std::vector<std::vector<double>> Matrix::get_rows() {

    return this->columns;

}

//
void Matrix::display_matrix() {

    for (std::vector<double> row : this->rows) {

        for (double e : row) {
            std::cout << e << "\t";
        }

        std::cout << "\n";

    }

}

//
void Matrix::display_transpose() {

    for (std::vector<double> row : this->columns) {

        for (double e : row) {
            std::cout << e << "\t";
        }

        std::cout << "\n";

    }

}

//
std::vector<double> Matrix::operator[](int element_index) {

    return this->rows[element_index];

}

//
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

Matrix operator-(Matrix l_matrix, const Matrix &r_matrix) {

    std::vector<std::vector<double>> differences;

    for (int i = 0; i < l_matrix.rows.size(); i++) {

        std::vector<double> left_row_x = l_matrix.rows[i];
        std::vector<double> right_row_x = r_matrix.rows[i];
        std::vector<double> new_row_x;

        for (int j = 0; j < left_row_x.size(); j++) {

            // Perform subtraction.
            new_row_x.push_back(left_row_x[j] - right_row_x[j]);


        }

        differences.push_back(new_row_x);

    }

    return Matrix(differences);

}

/**
 *
 * @param l_matrix
 * @param r_matrix
 * @return
 */
Matrix operator*(Matrix l_matrix, const Matrix &r_matrix) {

    std::vector<std::vector<double>> products;

    for (int i = 0; i < l_matrix.rows.size(); i++) {

        std::vector<double> left_row_x = l_matrix.rows[i];
        std::vector<double> right_column_x = r_matrix.columns[i];

        std::vector<double> new_row_x;

        for (int j = 0; j < r_matrix.columns.size(); j++) {

            double products_sum = 0;

            for (int k = 0; k < l_matrix.rows.size(); i++) {

                products_sum += (left_row_x[k] * right_column_x[k]);

            }

            new_row_x.push_back(products_sum);

        }

        products.push_back(new_row_x);

    }

    return Matrix(products);

}







