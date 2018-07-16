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

private:

    /*/ Data Fields /*/

    // The number of rows and columns.
    int num_of_rows;
    int num_of_columns;

    // The collections of the rows, columns, and the transpose.
    std::vector<std::vector<double>> rows;
    std::vector<std::vector<double>> columns;
    std::vector<std::vector<double>> transpose;

    // The vector of the elements of the matrix.
    std::vector<double> elements;

    // The dimensions of the matrix.
    std::vector<int> dimensions;


    /*/ Methods /*/

    /**
     * Sets the number of ROWS.
     *
     * @param num_of_rows
     */
    void set_num_of_rows(int num_of_rows);

    /**
     * Sets the number of COLUMNS.
     *
     * @param num_of_columns
     */
    void set_num_of_columns(int num_of_columns);

    /**
     * Sets the dimensions.
     *
     * @param dimensions
     */
    void set_dimensions(std::vector<int> dimensions);


public:

    /*/ Methods /*/

    /**
     * Constructor to initialize an empty Matrix.
     */
    Matrix();

    /**
     * Constructor to initialize a 1x0 Matrix.
     *
     * @param in_vector
     */
    explicit Matrix(std::vector<double> in_vector);

    /**
     * Constructor to initialize a multidimensional Matrix.
     *
     * @param in_vectors
     */
    explicit Matrix(const std::vector<std::vector<double>> &in_vectors);

    /**
     * Returns the number of ROWS.
     *
     * @return
     */
    unsigned long get_num_of_rows();

    /**
     * Returns the number of COLUMNS.
     *
     * @return
     */
    unsigned long get_num_of_columns();

    /**
     * Returns the dimensions of the Matrix.
     *
     * @return
     */
    std::vector<int> get_dimensions();

    /**
     * Returns the COLUMNS of the Matrix.
     *
     * @return
     */
    std::vector<std::vector<double>> get_rows();

    /**
     * Returns the COLUMNS of the Matrix.
     *
     * @return
     */
    std::vector<std::vector<double>> get_columns();

    /**
     * Returns the TRANSPOSE of the Matrix.
     *
     * @return
     */
    std::vector<std::vector<double>> get_transpose();

    /**
     * Displays the Matrix in MatrixForm.
     */
    void display_matrix();

    /**
     * Displays the TRANSPOSE of the Matrix in MatrixForm.
     */
    void display_transpose();

    /**
     * Displays the COLUMNS of the Matrix in MatrixForm.
     */
    void display_columns();

    /**
     * Operator overload to return ROWS from a Matrix.
     * Can continue to then index a returned ROW.
     *
     * @param element_index
     * @return
     */
    std::vector<double> operator[] (int element_index);

    /**
     * Performs matrix addition.
     *
     * @param l_matrix
     * @param r_matrix
     * @return
     */
    friend Matrix operator+ (Matrix l_matrix, const Matrix& r_matrix);

    /**
     * Performs matrix subtraction
     *
     * @param l_matrix
     * @param r_matrix
     * @return
     */
    friend Matrix operator- (Matrix l_matrix, const Matrix& r_matrix);

    /**
     * Performs matrix multiplication.
     *
     * @param l_matrix
     * @param r_matrix
     * @return
     */
    friend Matrix operator* (Matrix l_matrix, const Matrix& r_matrix);



};


#endif //MATRIX_MATRIX_H

