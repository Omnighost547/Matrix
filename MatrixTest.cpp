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
#include <random>        // default_random_engine
#include "MatrixTest.h"

using namespace MatrixM;

int DisplayTestString(std::string message)
{

    std::string stars("********");
    std::cout << stars << " " << message << " " << stars << std::endl;

    return 0;
}

int TestCopyCstr()
{
    DisplayTestString("Test a Copy Constructor");

    // Create first matrix
    Matrix m1(3, 3);
    m1.FillRand();

    std::cout << "Matrix 1:" << std::endl;
    std::cout << m1;

    // Create second matrix, as a copy
    Matrix m2(m1);

    std::cout << "Matrix 2 (copy):" << std::endl;
    std::cout << m2;

    return 0;
}
