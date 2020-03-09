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
// Last Modified: 2020-02-10
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

    Matrix::Matrix(bool x) : rows{ 2 }, cols{ 2 }, mat{ {1,0}, {0,1} }
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
        matrixCnt++;
    }

    Matrix::Matrix(int r, int c, const double &initVal) : rows{ r }, cols{ c }
    {
#if VERBOSE
        std::cout << "Executing Matrix 2-arg constructor with rows, cols, & initial value" << std::endl;
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
        matrixCnt++;
    }

    Matrix::~Matrix()
    {
#if VERBOSE
        std::cout << "Executing Matrix destructor" << std::endl;
#endif
        matrixCnt--;
    }

    /**
     * @todo insert return statement here

     * 
     */
    //Matrix &Matrix::operator=(const Matrix &)
    //{
    //}

    int Matrix::GetRows() const
    {
        return rows;
    }

    int Matrix::GetCols() const
    {
        return cols;
    }

    void Matrix::SetElement(int, int, double)
    {
    //TODO: add functionality
    }

    double Matrix::GetElement(int, int) const
    {
        //TODO: add functionality
        return 0.0;
    }

    int Matrix::GetMatrixCnt()
    {
        //TODO: add functionality
        return 0;
    }

    // Operator overload to compare energy of this matrix with another
    bool Matrix::operator<(const Matrix & rhs) const
    {
        //
        double pow = 0.0;
        for (auto& r : mat)
            for (auto& c : r)
                pow += pow + c * c;

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

}
