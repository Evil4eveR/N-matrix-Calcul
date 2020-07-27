#include "matrix.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

matrix::matrix()
{
    Size = 0;
}

matrix::matrix(int SS)
{
    Size = SS;
}

vector<int> matrix::getMatrix()
{
    return store;
}

void matrix::setMatrix(vector<int>& vec)
{
    store = vec;
}

int matrix::getSize()
{
    return Size;
}
void matrix::setSize(int S)
{
    Size = S;
}

int matrix::getEntry(int i, int j)
{
    int index;
    if(i < Size && j < Size)
    {
        if(i==Size-1 && j==Size-1)
        {
            return store[Size*2+Size-3];
        }
        if(j == 0)
        {
            index = i*3-1;
        }
        else if(j == Size-1)
        {
            index = i*3+1;
        }
        else if (i==j)
        {
            index = i*3;
        }
        else
        {
            return 0;
        }
        if(index<0)
        {
            index = 0;
        }
    }
    else
        return 0;

    return store[index];
}
void matrix::printN()
{
    cout<<"\n\n\n-------------------\nthe N matrix Print\n-------------------\n\n";
    int Size,temp;
    store.clear();
    cout << "First: Please input the size of the matrix:";
    cin>>Size;
    while(Size<1 || cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"please input Size number greater than ZERO:";
        cin>>Size;
    }
    cout << "Second: Please input "<<Size*2+Size-2<<" number of the matrix"<<endl;
    for(int i=0; i<Size*2+Size-2; i++)
    {
        cin >> temp;

        store.push_back(temp);
    }
    for(int i=0; i<Size*2+Size-2; i++)
    {
        if(store[i]==0)
        {
            cout<<"Wrong input value of Index("<<i+1<<"): enter now value of index "<<i+1<<":";
            cin>>store[i];
        }
    }
    int o=0;
    cout<<endl;
    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            if(j==i ||j==0 || j==Size-1  && i<Size)
            {
                cout<<store[o]<<"\t";
                o++;
            }
            else
            {
                cout<<"0\t";
            }
        }
        cout<<endl;
    }
}
void matrix::printNR()
{
    cout<<"\n\n\n-------------------\nthe N matrix Print\n-------------------\n\n";
    store.clear();
    int Size,temp;
    cout << "First: Please input the size of the matrix:";
    cin>>Size;
    while(Size<1|| cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"please input Size number greater than ZERO:";
        cin>>Size;
    }
    for(int i=0; i<Size*2+Size-2; i++)
    {
        store.push_back(rand()%100+1);
    }
    int o=0;
    cout<<endl;
    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            if(j==i ||j==0 || j==Size-1  && i<Size)
            {
                cout<<store[o]<<"\t";
                o++;
            }
            else
            {
                cout<<"0\t";
            }
        }
        cout<<endl;
    }
}
void matrix::store2get()
{
    store.clear();
    int Size,temp;
    cout << "First: Please input the size of the N matrix:";
    cin>>Size;
    while(Size<1 || cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"please input Size number greater than ZERO:";
        cin>>Size;
    }
    setSize(Size);
    cout << "Second: Please input "<<Size*2+Size-2<<" number of the N matrix"<<endl;
    for(int i=0; i<Size*2+Size-2; i++)
    {
        cin >> temp;
        store.push_back(temp);
    }
    for(int i=0; i<Size*2+Size-2; i++)
    {
        if(store[i]==0)
        {
            cout<<"Wrong input value of Index("<<i+1<<"): enter now value of index "<<i+1<<":";
            cin>>store[i];
        }
    }
    setMatrix(store);
    int i,j;
    cout<<"Enter the indexes seperated by space: ";
    cin>>i>>j;
    if(i<Size && j<Size)
    {
        cout<<"\nthe value of the indexes i = "<<i<<" and j = "<<j<<" is: "<<getEntry(i,j)<<endl;
    }
    else
        cout<<"not exist"<<endl;
}
void matrix::storeR2get()
{
    store.clear();
    int Size,temp;
    cout << "First: Please input the size of the N matrix:";
    cin>>Size;
    while(Size<1 || cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"please input Size number greater than ZERO:";
        cin>>Size;
    }
    setSize(Size);
    cout << "\nThe random N Matrix:"<<endl;
    for(int i=0; i<Size*2+Size-2; i++)
    {
        store.push_back(rand()%100+1);
    }
    for(int i=0; i<Size*2+Size-2; i++)
    {
        store.push_back(rand()%100+1);
    }
    int o=0;
    cout<<endl;
    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            if(j==i ||j==0 || j==Size-1  && i<Size)
            {
                cout<<store[o]<<"\t";
                o++;
            }
            else
            {
                cout<<"0\t";
            }
        }
        cout<<endl;
    }
    setMatrix(store);
    int i,j;
    cout<<"\nEnter the indexes seperated by space (not bigger than "<<Size<<"): ";
    cin>>i>>j;
    if(i<Size && j<Size)
    {
        cout<<"\nthe value of the indexes i = "<<i<<" and j = "<<j<<" is: "<<getEntry(i,j)<<endl;
    }
    else
        cout<<"not exist"<<endl;
}

void matrix::Sum2()
{
    int temp;
    vector<int> v;
    vector<int> v2;
    vector<int>sum;
    cout<<"the matrix square Size:";
    cin>>Size;
    while(Size<1 || cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"please input Size number greater than ZERO:";
        cin>>Size;
    }
    int siz = Size*2+Size-2;
    cout<<"enter "<<siz<<" value of first N matrix"<<endl;
    for(int i=0; i<siz; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    for(int i=0; i<Size*2+Size-2; i++)
    {
        if(v[i]==0)
        {
            cout<<"Wrong input value of Index("<<i+1<<"): enter now value of index "<<i+1<<":";
            cin>>v[i];
        }
    }
    cout<<"\nenter "<<siz<<" value of Second N matrix"<<endl;
    for(int i=0; i<siz; i++)
    {
        cin >> temp;
        v2.push_back(temp);
    }

    for(int i=0; i<Size*2+Size-2; i++)
    {
        if(v2[i]==0)
        {
            cout<<"Wrong input value of Index("<<i+1<<"): enter now value of index "<<i+1<<":";
            cin>>v2[i];
        }
    }
    cout<<"\nthe Addition of that two above N matrix :"<<endl;
    int s=0;
    int o=0;
    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            if(j==i ||j==0 || j==Size-1  && i<Size)
            {
                s=v[o]+v2[o];
                sum.push_back(s);
                cout<<sum[o]<<"\t";
                o++;
            }
            else
            {
                cout<<"0\t";
            }
        }
        cout<<endl;
    }
}
void matrix::multi2()
{
    int temp;
    vector<int> v;
    vector<int> v2;
    vector<int>multi;
    multi.clear();
    v.clear();
    v2.clear();
    cout<<"the matrix square Size:";
    cin>>Size;
    while(Size<1 || cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"please input Size number greater than ZERO:";
        cin>>Size;
    }
    int ss = Size;
    int siz = Size*2+Size-2;
    cout<<"enter "<<siz<<" value of first N matrix"<<endl;
    for(int i=0; i<siz; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    for(int i=0; i<Size*2+Size-2; i++)
    {
        if(v[i]==0)
        {
            cout<<"Wrong input value of Index("<<i+1<<"): enter now value of index "<<i+1<<":";
            cin>>v[i];
        }
    }
    cout<<"\nenter "<<siz<<" value of Second N matrix"<<endl;
    for(int i=0; i<siz; i++)
    {
        cin >> temp;
        v2.push_back(temp);
    }

    for(int i=0; i<Size*2+Size-2; i++)
    {
        if(v2[i]==0)
        {
            cout<<"Wrong input value of Index("<<i+1<<"): enter now value of index "<<i+1<<":";
            cin>>v2[i];
        }
    }
    cout<<"\nthe Multiplication of that two above N matrix :"<<endl;
    int o=0;
    int i, j, k;
    int a,b;
    for (i = 0; i < ss; i++)
    {
        for (j = 0; j < ss; j++)
        {
            for (k = 0; k < ss; k++)
            {
                setMatrix(v);
                setSize(Size);
                a = getEntry(i,k);
                setMatrix(v2);
                setSize(Size);
                b = getEntry(k,j);
                multi.push_back(0);
                multi[o] += a * b;
            }
            if(j==i ||j==0 || j==Size-1  && i<Size)
            {
                cout<<multi[o]<<"\t";
                o++;
            }
            else
            {
                cout<<"0\t";
            }
        }
        cout<<endl;
    }
}

void matrix::VectorPush(int newValue)
{
    store.push_back(newValue);
}

istream& operator>>(istream& is, matrix& a)
{
    int s;
    is >> s;
    a.setSize(s);

    std::cout << "I read size as " << s << "\n";

    int temp;
    for(int i=0; i<s*2+s-2; i++)
    {
        is >> temp;
        std::cout << "I read new value as " << temp << "\n";
        a.VectorPush(temp);
    }

    return is;
}

matrix operator+(matrix& a ,matrix& b)
{
    int s= a.getSize();
    if(s != b.getSize()) throw matrix::DIFFERENT;
    matrix newMatrix(s);
    int sum=0;
    int siz = a.getSize();
    for(int i=0; i<siz; i++)
    {
        for(int j=0; j<siz; j++)
        {
            sum=a.getEntry(i,j)+b.getEntry(i,j);
            if(sum!=0){
                newMatrix.VectorPush(sum);
            }
        }
    }
    return newMatrix;
}
matrix operator*(matrix& a ,matrix& b)
{
    int s= a.getSize();
    if(s != b.getSize()) throw matrix::DIFFERENT;
    matrix newMatrix(s);
    int sum=0;
    int siz = a.getSize();
    for(int i=0; i<s; i++)
    {
        for(int j=0; j<s; j++)
        {
            sum=0;
            for(int k=0;k<s;k++){
                sum+=a.getEntry(i,k)*b.getEntry(k,j);
            }
            if(sum!=0){newMatrix.VectorPush(sum);}
        }
    }
    return newMatrix;
}
