/*myFile1a, Ex1 a4 CSI2372A
Ayman Naciri
300143727
anaci032@uottawa.ca*/
#ifndef MYFILE1A_H
#define MYFILE1A_H

#include <iostream>
using namespace std;

class Course {
    int num;
    int hours;
public:
    Course(int courseNum, int courseHours); 	//constructor
    int getNum();
    int getHours();
};

#endif

