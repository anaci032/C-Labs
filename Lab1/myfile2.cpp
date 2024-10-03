/*Header file: myfile2.h*/
/*myfile2.cpp : Ex2 a1 CSI2372A*/
//Ayman Naciri
//300143727
//anaci032@uottawa.ca
/*1) the following code prints a menu on the console asking the user to select from 3 options
(cases) 1 is a disk surface calculator, 2 is cylinder volume calculator and 3 is how many times each of those 
have been run then exits the program , also the program goes back to the menu once that 
calculation has been done*/
#include "myfile2.h"

char menu(void)
{
    char choice;
    cout << "What do you want to do?:" << endl
         << endl;
    cout << "\t-Calculate the area of a disk from a radius (Press 1)" << endl
         << endl;
    cout << "\t-Calculate the volume of a cylinder from a radius and a height (Press 2)" << endl
         << endl;
    cout << "\t-Exit the program (press 3)" << endl
         << endl;
    cout << "Your choice:";
    cin >> choice;
    return (choice);
    cout << endl;
}
int volume(double const &ray, double const &height){
    double vol = ray * ray * height * Pi;
    cout << "the volume is: " << vol << endl << endl;
    return vol;
}
int surface(double const &ray){
    double sur = ray * ray *Pi;
    cout << "the surface is: " << sur << endl << endl;
    return sur;
}

/*main Function*/
int main()
{
    char choice;
    int nvolume = 0;  // number of times the volume function has been executed
    int nsurface = 0; // number of times the surface function has been executed
    double radius, height;
    while (1)
    {
        choice = menu();
        switch (choice)
        {
        case '1':
            cout << endl
                 << "Surface calculation" << endl;
            cout << "Enter the radius:";
            cin >> radius;
            //changed this part because it doesnt work for expected code
            nsurface++;
            surface(radius);
            break;
        case '2':
            cout << endl
                 << "Volume calculation" << endl;
            cout << " Enter the radius:";
            cin >> radius;
            cout << " Enter the height:";
            cin >> height;
            //changed this part because it doesnt work for expected code
            nvolume++;
            volume(radius, height);
            break;
        case '3':
            cout << endl
                 << "Exit the program" << endl;
                 // added spacing for better reading
            cout << "The volume function has been executed " << nvolume << " times" << endl;
            cout << "The surface function has been executed " << nsurface
                 << " times" << endl;
            exit(0);
        default:
            break;
        }
    }
}

