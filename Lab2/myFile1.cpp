/*myFile1.cpp : Ex1 a2 CSI2372A
Student Name: Ayman Naciri
Student Number: 300143727
Course Code: CSI2372A*/
#include <iostream>
using namespace std;
int main(void)
{
    int tab[10];
    int *p;
    for (int i = 0; i < 10; i++)
    {
        tab[i] = i * i;
    }
    // "*" fetches value of address, & fetches address of value, tab on its own is an address
    cout << tab[2] << endl;
    tab[2] = tab[1];
    cout << tab[2] << endl;
    tab[2] = *(tab + 1);
    cout << tab[2] << endl;
    *(tab + 2) = tab[1];
    cout << tab[2] << endl;
    *(tab + 2) = *(tab + 1);
    cout << tab[2] << endl;
    p = &tab[0];
    p = tab + 1;
    tab[4] = *p;
    cout << tab[4] << endl;
}