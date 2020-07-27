#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <vector>
#include "matrix.h"

using namespace std;
class menu
{
public :
    vector <int> v;
    int temp,Size;
    menu();
    void run();
    matrix mm;
private:
    void getIndex();
    void add();
    void mult();
    void print();
};;


#endif // MENU_H_INCLUDED
