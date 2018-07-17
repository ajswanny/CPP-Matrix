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

    // Define the determinant.
    this->determinant = 0.9;

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
    for (const std::vector row : in_vectors) { // NOLINT

        this->rows.push_back(row);

    }

    // Define a collection of the COLUMNS.
    for (int i = 0; i < in_vectors.size(); i++) {

        std::vector<double> new_column_x;

        for (int j = 0; j < in_vectors[i].size(); j++) {

            new_column_x.push_back(in_vectors[j][i]);

        }

        this->columns.push_back(new_column_x);

    }

    // Define the TRANSPOSE.
    for (int i = 0; i < in_vectors.size(); i++) {

        std::vector<double> new_row_x;

        for (std::vector<double> row : in_vectors) {

            new_row_x.push_back(row[i]);

        }

        this->transpose.push_back(new_row_x);

    }

    // Define new dimensions.
    this->dimensions = {
            static_cast<int>(in_vectors.size()),
            static_cast<int>(in_vectors[0].size())
    };

    // Update statistical data.
    this->num_of_rows = dimensions[0];
    this->num_of_columns = dimensions[1];

    // Define the determinant.
    this->calculate_determinant();

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

    this->dimensions = std::move(dimensions);

}

//
std::vector<std::vector<double>> Matrix::get_rows() {

    return this->columns;

}

//
std::vector<std::vector<double>> Matrix::get_columns() {

    return this->columns;

}

//
std::vector<std::vector<double>> Matrix::get_transpose() {

    return this->transpose;

}

//
double Matrix::get_determinant() {

    return this->determinant;

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

    for (std::vector<double> row : this->transpose) {

        for (double e : row) {
            std::cout << e << "\t";
        }

        std::cout << "\n";

    }

}

//
void Matrix::display_columns() {


    for (std::vector<double> column : this->columns) {

        for (double e : column) {
            std::cout << e << "\t";
        }

        std::cout << "\n";

    }

}

//
void Matrix::calculate_determinant() {

    // Define references to Matrix dimensions.
    std::vector<int> two_x_two = {2, 2};
    std::vector<int> three_x_three = {3, 3};

    if (this->dimensions == two_x_two) {
        // Calculate the determinant for a 2x2 Matrix, where det(M) = a*d - b*c.

        // Calculate the products of the diagonals.
        double element_one = rows[0][0] * rows[1][1];
        double element_two = rows[0][1] * rows[1][0];

        // Define the determinant.
        this->determinant = element_one - element_two;

    }

    if (this->dimensions == three_x_three) {
        // Calculate the determinant for a 3x3 Matrix, where
        // det(M) = a_1,1 * C_1,1 - a_1,2 * C_1,2 + a_1,3 * C_1,3.

        // Calculate the co-factors.
        double element_one = rows[0][0] * (
                rows[1][1] * rows[2][2] - rows[1][2] * rows[2][1]
                                          );

        double element_two = rows[0][1] * (
                rows[1][0] * rows[2][2] - rows[1][2] * rows[2][0]
                                          );

        double element_three = rows[0][2] * (
                rows[1][0] * rows[2][1] - rows[1][1] * rows[2][0]
                                            );

        // Define the determinant.
        this->determinant = element_one - element_two + element_three;

    }

    else {

        std::cout << "The determinant could not be calculated." << std::endl;
        this->determinant = 0.9;

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

//
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

//
Matrix operator*(Matrix l_matrix, const Matrix &r_matrix) {

    std::vector<std::vector<double>> products;

    // Loop through each ROW of the left matrix.
    for (std::vector<double> l_matrix_row_x : l_matrix.rows) {

        // Define a collection of results to become a new ROW for the product.
        std::vector<double> new_row_x;

        // Loop through each COLUMN of the right matrix.
        for (const std::vector<double> &r_matrix_column : r_matrix.columns) {

            // Define a variable to record the sum of the products of the corresponding elements
            // of the current ROW and COLUMN.
            double products_sum = 0;

            // Loop through each of the elements of the current COLUMN.
            for (int k = 0; k < r_matrix_column.size(); k++) {

                // Find the product of corresponding elements and add to the total sum.
                products_sum += (l_matrix_row_x[k] * r_matrix_column[k]);

            }

            // Record the final sum to the new ROW for the multiplication product.
            new_row_x.push_back(products_sum);

        }

        // Record the new ROW of the matrix multiplication product.
        products.push_back(new_row_x);

    }

    // Return the product.
    return Matrix(products);

}

