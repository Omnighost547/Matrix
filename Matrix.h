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
// Last Modified: 2020-03-02
// Module / Lecturer: C++ / Michelle Lynch
////////////////////////////////////////////////////////////

//#pragma once
#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#define VERBOSE 1

#include <vector>   // vector
#include <iostream> // ostream


namespace MatrixM 
{
    class Matrix 
    {
    private:
        int rows;                               // Number of rows
        int cols;                               // Number of columns
        std::vector<std::vector<double>> mat;   // 2D Matrix created from STL vector
        static int matrixCnt;                   // Static count of number of Matrix objects

    public:
        Matrix();                               // Default constructor
        Matrix(bool);                           // 2x2 identity matrix
        Matrix(int, int);                       // Constructor
        Matrix(int, int, const double&);        // Constructor with init value
        Matrix(const Matrix&);                  // Copy constructor
        ~Matrix();                              // Destructor
        Matrix& operator=(const Matrix&);       // Copy assignment operator

        int GetRows() const;                    // Get number of rows
        int GetCols() const;                    // Get number of columns
        void SetElement(int, int, double);      // Set an element value
        double GetElement(int, int) const;      // Get an element value
        static int GetMatrixCnt();              // Static function to get Matric count



        //double &operator()(const int &, const int &);               // Overload parentheses
        //const double& operator() (const int&, const int&) const;    // Ditto

        //Matrix operator+(const Matrix &) const;   // + operator overload to add rhs to lhs
        //Matrix operator-(const Matrix &) const;   // - operator overload to subtract rhs from lhs?)
        //Matrix operator*(const Matrix &) const;   // * operator overload to multiply matrices
        //bool operator==(const Matrix &) const;    // == operator to logically compare lhs with rhs
        //bool operator!=(const Matrix &) const;    // != operator to logically compare lhs with rhs
        bool operator<(const Matrix &) const;       // < operator to compare two matrices (lhs < rhs)?

        int FillRand();


    };

    std::ostream& operator<<(std::ostream&, const Matrix&);
}
#endif // !MATRIX_H_INCLUDED
