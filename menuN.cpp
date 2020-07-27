#include<iostream>
#include<cstdlib>
#include "menuN.h"

using namespace std;
void clear_screen();
menu::menu()
{
    cout<<"\t============\n\tTHE N MATRIX\n\t============"<<endl;
}

void menu::run()
{
    cout<<"\n MENU"<<endl;

    int n;

    do
    {
        cout<<"_______________________\n\n"<<"   1-Print the N matrix"<<endl;
        cout<<"   2-Get element"<<endl;
        cout<<"   3-Add N Matrices"<<endl;
        cout<<"   4-Multiply N Matrices"<<endl;
        cout<<"   5-Exit"<<"\n_______________________"<<endl;

    }
    while(n>1 && n<5);
    cout<<"Enter your choice:\n >>>>>";
    cin>>n;
    while(n<1 || n>6 || cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<" \nplease use Number from Menu!!!\nEnter your choice again:\n >>>>>";
        cin>>n;
    }

    switch(n)
    {
    case 1:
        clear_screen();
        print();
        break;
    case 2:
        clear_screen();
        getIndex();
        break;
    case 3:
        clear_screen();
        add();
        break;
    case 4:
        clear_screen();
        mult();
        break;
    case 5:
        cout<<"\nGood bye (^_^)\n";
        exit(1);
        break;
    }
}
//print menu
void menu::print()
{
    int p;
    while(1)
    {
        cout<<"~~~~~~~~~~~~~~~~~~~~~~\n"<<"Print Menu:\n-------------------------------"<<endl;
        cout<<"   1-Store the N Matrix to Print"<<endl;
        cout<<"   2-Print a random N Matrix by Size"<<endl;
        cout<<"   3-back to Main Menu"<<endl;
        cout<<"   4-Exit"<<endl;
        cout<<"\nEnter your choice:\n >>>>>";
        cin>>p;
        while(p<1 || p>5 || cin.fail())
        {
            cin.clear();
            cin.ignore(256,'\n');
            cout<<" \nplease use Number from Menu!!!\nEnter your choice again:\n >>>>>";
            cin>>p;
        }
        switch(p)
        {
        case 1:
            mm.printN();
            break;
        case 2:
            mm.printNR();
            break;
        case 3:
        {
            clear_screen();
            menu r;
            r.run();
        }
        break;
        case 4:
            cout<<"\nGood bye (^_^)\n";
            exit(1);
            break;
        }

        cout<<"\n\n"<<endl;
    }
}
//get element menu
void menu::getIndex()
{
    int g;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~\n"<<"Index Menu:\n-------------------------------"<<endl;
    cout<<"   1-Store the N Matrix to get value by Index"<<endl;
    cout<<"   2-get value of Random N Matrix by Size"<<endl;
    cout<<"   3-back to Main Menu"<<endl;
    cout<<"   4-Exit"<<endl;
    cout<<"Enter your choice:\n >>>>>";
    cin>>g;
    while(g<1 || g>5 || cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<" \nplease use Number from Menu!!!\nEnter your choice again:\n >>>>>";
        cin>>g;
    }
    switch(g)
    {
    case 1:
        mm.store2get();
        getIndex();
        break;
    case 2:
        mm.storeR2get();
        getIndex();
        break;
    case 3:
    {
        clear_screen();
        menu r;
        r.run();
    }
    break;
    case 4:
        cout<<"\nGood bye (^_^)\n";
        exit(1);
        break;
    }
}
//addition menu
void menu::add()
{
    cout<<"\n---------------------\nADDITION TWO N MATRIX\n---------------------\n\n";
    mm.Sum2();
again:
    cout<<"~~~~~~~~~~~~~~~~~~~~~~\n"<<"Mini Addition Menu:\n-------------------------------"<<endl;
    cout<<"\n   1-Add another two matrix"<<endl;
    cout<<"   2-back to Main Menu"<<endl;
    cout<<"   3-exit"<<endl;
    cout<<"\n\n"<<endl;
    cout<<"Enter your choice:\n >>>>>";
    int a;
    cin>>a;
    while(a<1 || a>4 || cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<" \nplease use Number from Menu!!!\nEnter your choice again:\n >>>>>";
        cin>>a;
    }
    switch(a)
    {
    case 1:
        mm.Sum2();
        goto again;
        break;
    case 2:
    {
        clear_screen();
        menu r;
        r.run();
    }
    break;
    case 3:
        cout<<"\nGood bye (^_^)\n";
        exit(1);
        break;
    }
}
//multiplication menu
void menu::mult()
{
    cout<<"\n---------------------------\nMULTIPLICATION TWO N MATRIX\n---------------------------\n\n";
    mm.multi2();
again2:
    cout<<"~~~~~~~~~~~~~~~~~~~~~~\n"<<"Mini Multiplication Menu:\n-------------------------------"<<endl;
    cout<<"\n   1-Multi another two matrix"<<endl;
    cout<<"   2-back to Main Menu"<<endl;
    cout<<"   3-exit"<<endl;
    cout<<"\n\n"<<endl;
    cout<<"Enter your choice:\n >>>>>";
    int mu;
    cin>>mu;
    while(mu<1 || mu>4 || cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<" \nplease use Number from Menu!!!\nEnter your choice again:\n >>>>>";
        cin>>mu;
    }
    switch(mu)
    {
    case 1:
        mm.multi2();
        goto again2;
        break;
    case 2:
    {
        clear_screen();
        menu r;
        r.run();
    }
    break;
    case 3:
        cout<<"\nGood bye (^_^)\n";
        exit(1);
        break;
    }
}

void clear_screen()
{
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif // Windows
}
