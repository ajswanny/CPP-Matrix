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

    /*/ Data Fields /*/

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


    /*/ Methods /*/

    /**
     *
     * @param num_of_rows
     */
    void set_num_of_rows(int num_of_rows);

    /**
     *
     * @param num_of_columns
     */
    void set_num_of_columns(int num_of_columns);

    /**
     *
     * @param dimensions
     */
    void set_dimensions(std::vector<int> dimensions);


public:

    /*/ Methods /*/

    Matrix();

    /**
     * Constructor to initialize an empty Matrix.
     *
     * @param in_vector
     */
    explicit Matrix(std::vector<double> in_vector);

    /**
     * Constructor to initialize a 1x0 Matrix.
     *
     * @param in_vectors
     */
    explicit Matrix(const std::vector<std::vector<double>> &in_vectors);

    /**
     *
     * @return
     */
    unsigned long get_num_of_rows();

    /**
     *
     * @return
     */
    unsigned long get_num_of_columns();

    /**
     *
     * @return
     */
    std::vector<double> get_dimensions();

    /**
     *
     */
    void display_matrix();

    /**
     * Operator overload to return ROWS.
     * Can continue to then index a returned ROW.
     *
     * @param element_index
     * @return
     */
    std::vector<double> operator[] (int element_index);

    /**
     *
     * @param l_matrix
     * @param r_matrix
     * @return
     */
    friend Matrix operator+ (Matrix l_matrix, const Matrix& r_matrix);


    friend Matrix operator- (Matrix l_matrix, const Matrix& r_matrix);



};


#endif //MATRIX_MATRIX_H
