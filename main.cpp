#include "matrix.h"
#include "matrix.cpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include "menuN.h"

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE


int main()
{
    menu play;
    play.run();

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("create", "inp.txt")
{
/*
matrix test from inp.txt file

1
1

2
1 3
2 4

3
1       2
3   4   5
6       7

*/

    ifstream in("inp.txt");
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }
    matrix a;
    in >> a;
    CHECK(a.getEntry(0,0) == 1);

    matrix b;
    in >> b;
    CHECK(b.getEntry(0,0) == 1);
    CHECK(b.getEntry(0,1) == 2);
    CHECK(b.getEntry(1,1) == 4);
    CHECK(b.getEntry(1,0) == 3);

    matrix c;
    in >> c;
    CHECK(c.getEntry(0,0) == 1);
    CHECK(c.getEntry(1,1) == 4);
    CHECK(c.getEntry(2,2) == 7);
    CHECK(c.getEntry(0,2) == 2);
    CHECK(c.getEntry(1,0) == 3);
    CHECK(c.getEntry(1,2) == 5);
    CHECK(c.getEntry(2,0) == 6);
}


TEST_CASE("copy constructor", "inp2.txt")
{
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    matrix a;
    in >> a; // 3

    matrix b = a;

    CHECK(a.getEntry(0,0) == b.getEntry(0,0));
    CHECK(a.getEntry(1,1) == b.getEntry(1,1));
    CHECK(a.getEntry(2,2) == b.getEntry(2,2));
}


TEST_CASE("assignment operator", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    matrix a, b; // 3
    in >> a;

    b = a; // check every non-zero item
    CHECK(a.getEntry(0,0) == b.getEntry(0,0));
    CHECK(a.getEntry(1,1) == b.getEntry(1,1));
    CHECK(a.getEntry(2,2) == b.getEntry(2,2));

    matrix c; // 3
    c = b = a; // check every non-zero item
    CHECK(a.getEntry(0,0) == c.getEntry(0,0));
    CHECK(a.getEntry(1,1) == c.getEntry(1,1));
    CHECK(a.getEntry(2,2) == c.getEntry(2,2));

    a = a; // check every non-zero item
    CHECK(a.getEntry(0,0) == 1);
}

TEST_CASE("add", "inp2.txt")
{
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    matrix a, b, c, d; // 3
    in >> a >> b;

    c = a + b; // check every non-zero item
    CHECK(c.getEntry(0,0) == 8);
    CHECK(c.getEntry(1,1) == 8);
    CHECK(c.getEntry(2,2) == 8);
    CHECK(c.getEntry(0,2) == 8);
    CHECK(c.getEntry(1,0) == 8);
    CHECK(c.getEntry(1,2) == 8);
    CHECK(c.getEntry(2,0) == 8);
    d = b + a; // check every non-zero item
    CHECK(c.getEntry(0,0) == d.getEntry(0,0));
    CHECK(c.getEntry(1,1) == d.getEntry(1,1));
    CHECK(c.getEntry(2,2) == d.getEntry(2,2));
    CHECK(c.getEntry(0,2) == d.getEntry(0,2));
    CHECK(c.getEntry(1,0) == d.getEntry(1,0));
    CHECK(c.getEntry(1,2) == d.getEntry(1,2));
    CHECK(c.getEntry(2,0) == d.getEntry(2,0));
}

TEST_CASE("multiply", "inp2.txt")
{
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    matrix a, b, c, d, f, e, z; // 3
    in >> a >> b;

    c = a * b;
    CHECK(c.getEntry(0,0) == 11);
    CHECK(c.getEntry(1,1) == 16);
    CHECK(c.getEntry(2,2) == 43);
    CHECK(c.getEntry(0,2) == 8);
    CHECK(c.getEntry(1,0) == 51);
    CHECK(c.getEntry(1,2) == 35);
    CHECK(c.getEntry(2,0) == 56);


    d = b * a;
    CHECK(c.getEntry(0,0) == d.getEntry(2,2));
    CHECK(c.getEntry(1,1) == d.getEntry(1,1));
    CHECK(c.getEntry(2,2) == d.getEntry(0,0));
    CHECK(c.getEntry(0,2) == d.getEntry(2,0));
    CHECK(c.getEntry(1,0) == d.getEntry(1,2));
    CHECK(c.getEntry(1,2) == d.getEntry(1,0));
    CHECK(c.getEntry(2,0) == d.getEntry(0,2));

}

#endif

