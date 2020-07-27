#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#pragma once
#include <string>
#include <vector>
using namespace std;

class matrix
{
private:
    int Size;
    vector<int> store;
public:
    enum Exceptions{OVERINDEXED, NULLPART, DIFFERENT, INVALID};
    matrix();
    matrix(int SS);
    vector<int> getMatrix();
    void setMatrix(vector<int>& vec);
    int getSize();
    void setSize(int S);
    void VectorPush(int newValue);
    int getEntry(int i, int j);
    void printN();
    void printNR();
    void store2get();
    void storeR2get();
    void Sum2();
    void multi2();
    friend std::istream& operator>> (std::istream& s, matrix& a);
    friend matrix operator+ (matrix& a, matrix& b);
    friend matrix operator* (matrix& a, matrix& b);

};


#endif // MATRIX_H_INCLUDED

