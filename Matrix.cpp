////////////////////////////////////////////////////////////
//   #####    #####   ######   ######    ####    ##   ##  //
//  ## # ##  ##   ##    ##     ##   ##    ##     ##   ##  //
//  ## # ##  ##   ##    ##     ##   ##    ##      ## ##   //
//  ## # ##  #######    ##     ######     ##       ###    //
//  ##   ##  ##   ##    ##     ##   ##    ##      ## ##   //
//  ##   ##  ##   ##    ##     ##   ##    ##     ##   ##  //
//  ##   ##  ##   ##    ##     ##   ##   ####    ##   ##  //
////////////////////////////////////////////////////////////
// Tommy Kearns / g00320978
// Created: 2020-01-31
// Last Modified: 2020-03-09
// Module / Lecturer: C++ / Michelle Lynch
////////////////////////////////////////////////////////////

#include <iostream>  // cout
#include <random>    // default_random_engine
#include <vector>    // vector
#include <iterator>  // iterator, const_iterator
#include <chrono>    // time
#include <ctime>     // time
#include "Matrix.h"

namespace MatrixM {

    // Initialise the static data member
    int Matrix::matrixCnt = 0;

    Matrix::Matrix() : rows{ 0 }, cols{ 0 }
    {
#if VERBOSE
        std::cout << "Executing Matrix default constructor" << std::endl;
#endif
        matrixCnt++;
    }

    Matrix::Matrix(bool x) : rows{ 2 }, cols{ 2 }, mat{ {1, 0}, {0, 1} }
    {
#if VERBOSE
        std::cout << "Executing Matrix 2x2 identity matrix constructor" << std::endl;
#endif
        matrixCnt++;
    }

    Matrix::Matrix(int r, int c) : rows{ r }, cols{ c }
    {
#if VERBOSE
        std::cout << "Executing Matrix 2-arg constructor with rows & cols" << std::endl;
#endif
        mat.resize(r);
        for (auto i = mat.begin(); i != mat.end(); i++)
            i->resize(c);

        matrixCnt++;
    }

    // Constructor with specified inital value for all elements
    Matrix::Matrix(int r, int c, const double &initVal) : rows{ r }, cols{ c }
    {
#if VERBOSE
        std::cout << "Executing Matrix 3-arg constructor with rows, cols, & initial value" << std::endl;
#endif
        mat.resize(r);
        for (auto i = mat.begin(); i != mat.end(); i++)
            i->resize(c, initVal);

        matrixCnt++;
    }

    // Copy constructor
    Matrix::Matrix(const Matrix &rhs) : rows{ rhs.rows }, cols{ rhs.cols }, mat{ rhs.mat }
    {
#if VERBOSE
        std::cout << "Executing Matrix copy constructor" << std::endl;
#endif
        //rows = rhs.rows;
        //cols = rhs.cols;
        //mat  = rhs.mat;

        //mat.resize(q.getColums());
        //for (auto &r : mat) {
        //    r.resize(q.getRows());//resizes vetor which is in the vector
        //}

        //for (int i = 0; i < mat.size(); i++) {
        //    for (int j = 0; j < mat[i].size(); j++)
        //        mat[i][j] = q.mat[i][j];
        //}

        matrixCnt++;
    }

    Matrix::~Matrix()
    {
#if VERBOSE
        std::cout << "Executing Matrix Destructor" << std::endl;
#endif
        matrixCnt--;
    }

    // Copy assignment operator
    Matrix &Matrix::operator=(const Matrix &rhs)
    {
    /*
        if (this != &rhs) {
            mat.resize(rhs.GetCols());
            for (auto &r : mat) {
                r.resize(rhs.GetRows());//resizes vetor which is in the vector
            }

            for (int i = 0; i < mat.size(); i++) {
                for (int j = 0; j < mat[i].size(); j++)
                    mat[i][j] = rhs.mat[i][j];
            }
            return *this;
        }
    */
        if (this != &rhs) {
            rows = rhs.GetRows();
            cols = rhs.GetCols();
            mat.resize(rows);
            for (auto r : mat) {
                r.resize(rhs.GetRows());//resizes vetor which is in the vector
            }

            for (int i = 0; i < mat.size(); i++) {
                for (int j = 0; j < mat[i].size(); j++)
                    mat[i][j] = rhs.mat[i][j];
            }
            return *this;
        }

    }

    int Matrix::GetRows() const
    {
        return rows;
    }

    int Matrix::GetCols() const
    {
        return cols;
    }

    void Matrix::SetElement(int r, int c, double val)
    {
        mat[r][c] = val;
    }

    double Matrix::GetElement(int r, int c) const
    {
        return this->mat[r][c];
    }

    int Matrix::GetMatrixCnt()
    {
        return matrixCnt;
    }

    // Operator overload to compare energy of this matrix with another
    bool Matrix::operator<(const Matrix &rhs) const
    {
        double pow = 0.0;
        for (auto &r : mat)
            for (auto &c : r)
                pow += pow + c * c;
        pow = pow / (double(rows) * double(cols));

        double pow_rhs = 0.0;
        for (auto &r : rhs.mat)
            for (auto &c : r)
                pow_rhs += pow_rhs + c * c;
        pow_rhs = pow_rhs / (double(rhs.rows) * double(rhs.cols));

        if (pow <= pow_rhs)
            return true;
        else
            return false;
    }

    // Fill with random numbers
    int Matrix::FillRand()
    {
        static std::default_random_engine eng;
        static std::uniform_real_distribution <double> u(-1, 9);

        // Use a lambda & for_each algorithm to fill elements with sequence 0,
        // Start by iterating over each row, then for_each column
        for (auto &r : mat)
            std::for_each(r.begin(), r.end(), [](double &e) { e = u(eng); });

        /*
        // Auto reference iterator code
        for (auto &r : mat)
            for (auto &c : r)
                c = u(eng);
        */

        return 0;
    }

    std::ostream &operator<<(std::ostream &output, const Matrix &rhs)
    {
        for (int i = 0; i < rhs.GetRows(); ++i) {
            output << "| ";
            for (int j = 0; j < rhs.GetCols(); ++j)
                output << rhs.GetElement(i, j) << "  ";
            output << "|" << std::endl;
        }

        return output;
    }

}
