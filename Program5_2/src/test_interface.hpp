#ifndef TEST_INTERFACE_HPP
#define TEST_INTERFACE_HPP

#include <iostream>
#include <iomanip>
#include "testFuncs.hpp"
#include "PFAString.hpp"

void runTests()
{
    using std::cout;
    using std::left;
    using std::setw;
    using std::endl;

    const int COL = 40;

    char prev = cout.fill('.');
    cout << "PFAString Class Tests\n";
    cout << setw(COL) << left << "Default Constructor" << testDConstr() << endl;
    cout << setw(COL) << left << "Capacity" << testGetCap() << endl;
    cout << setw(COL) << left << "Size" << testGetSize() << endl;
    cout << setw(COL) << left << "Fill Constructor (Default Provided)" << testFillConstr(true) << endl;
    cout << setw(COL) << left << "Fill Constructor (No Default Proided)" << testFillConstr(false) << endl;
    cout << setw(COL) << left << "Push Back" << testPushBack(true) << endl;
    cout << setw(COL) << left << "Push Back (On Empty)" << testPushBack(false) << endl;
    cout << setw(COL) << left << "Copy Constructor" << testCopConstr(false) << endl;
    cout << setw(COL) << left << "Copy Constructor (Copy from Empty)" << testCopConstr(true) << endl;
    cout << setw(COL) << left << "Move Constructor" << testMovConstr(false) << endl;
    cout << setw(COL) << left << "Move Constructor (Move from Empty)" << testMovConstr(true) << endl;
    cout << setw(COL) << left << "Pop Back" << testPopBack(false) << endl;
    cout << setw(COL) << left << "Pop Back (On Empty)" << testPopBack(true) << endl;
    cout << setw(COL) << left << "Resize (Smaller)" << testResizeSmaller() << endl;
    cout << setw(COL) << left << "Resize (Larger, Value Provided)" << testResizeLarger("PSY") << endl;
    cout << setw(COL) << left << "Resize (Larger, No Value Provided)" << testResizeLarger() << endl;
    cout << setw(COL) << left << "[] (l-value)" << testSQBLV() << endl;
    cout << setw(COL) << left << "[] (const)" << testSQAcc() << endl;
    cout << setw(COL) << left << "Empty" << testEmpty() << endl;
    cout << setw(COL) << left << "Expansion" << testExpansion() << endl;
    cout << setw(COL) << left << "Copy Assignment" << testAssgn(false) << endl; // ADD BOOL FOR EMPTY CHECK
    cout << setw(COL) << left << "Copy Assignment (Copy From Empty)" << testAssgn(true) << endl;
    cout << setw(COL) << left << "Copy Assignment (Copy From Smaller)" << testAssgnCpySize(true) << endl;
    cout << setw(COL) << left << "Copy Assignment (Copy From Larger)" << testAssgnCpySize(false) << endl;
    cout << setw(COL) << left << "Move Assignment" << testAssgnMov(false) << endl;
    cout << setw(COL) << left << "Move Assignment (Move From Empty)" << testAssgnMov(true) << endl;
    cout << setw(COL) << left << "Move Assignment (Move From Smaller)" << testAssgnMovSize(true) << endl;
    cout << setw(COL) << left << "Move Assignment (Move From Larger)" << testAssgnMovSize(false) << endl;
    cout << setw(COL) << left << "Equality (T)" << testEQUIVT() << endl;
    cout << setw(COL) << left << "Equality (F)" << testEQUIVF() << endl;
    cout << setw(COL) << left << "Inequality (T)" << testINEQUIVT() << endl;
    cout << setw(COL) << left << "Inequality (F)" << testINEQUIVF() << endl;
    cout << setw(COL) << left << "Less Than (T)" << testLTT() << endl;
    cout << setw(COL) << left << "Less Than (F)" << testLTF() << endl;
    cout << setw(COL) << left << "Less Than (F, ==)" << testLTFE() << endl;
    cout << setw(COL) << left << "Greater Than (T)" << testGTT() << endl;
    cout << setw(COL) << left << "Greater Than (F)" << testGTF() << endl;
    cout << setw(COL) << left << "Greater Than (F, ==)" << testGTFE() << endl;
    cout << setw(COL) << left << "Less Than or Equal (T)" << testLEQT() << endl;
    cout << setw(COL) << left << "Less Than or Equal (T, ==)" << testLEQTE() << endl;
    cout << setw(COL) << left << "Less Than or Equal (F)" << testLEQF() << endl;
    cout << setw(COL) << left << "Greater Than or Equal (T)" << testGEQT() << endl;
    cout << setw(COL) << left << "Greater Than or Equal (T, ==)" << testGEQTE() << endl;
    cout << setw(COL) << left << "Greater Than or Equal (F)" << testGEQF() << endl;

    cout.fill(prev);
}

#endif
