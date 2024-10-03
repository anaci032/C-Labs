/*myfile1.cpp : Ex1 a1 CSI2372A*/
//Ayman Naciri
//300143727
//anaci032@uottawa.ca

#include "myfile1.h"

int main (){
    cout << "\nSize in bytes of a Charcter: "<< sizeof(char);
    cout << "\nSize in bytes of an Integer: "<< sizeof(int); 
    cout << "\nSize in bytes of an Fload: "<< sizeof(float); 
    cout << "\nSize in bytes of an Double: "<< sizeof(double); 
    cout << "\nSize in bytes of an Short Integer: "<< sizeof(short); 
    cout << "\nSize in bytes of an Unsinged Integer: "<< sizeof(unsigned)<<"\n\n"; 
    int i;
    cout << "\nEnter an Integer:";
    cin >> i;
    cout <<"\nNumber in decimal:\t" << i << endl;
    cout <<"Number in octal:\t" << oct << i << endl;
    cout <<"Number in hex:\t\t" << hex << i <<endl;
    //reset
    cout << dec;
    cout <<"\nNumber in decimal:\t" << i << endl;
    cout <<"Number in octal:\t" << oct << i << endl;
    cout <<"Number in hex:\t\t" << hex << i <<endl;
    
    double r;
    cout << "\nEnter a real number:\t";
    cin >> r;
    cout << setprecision(3) << fixed << r << endl;
    //question wasn't very clear, looks very different from expected value
    cout << setprecision(3) << scientific << r << endl;
    cout << setprecision (13) << hexfloat << r << endl;

    string c;
    cout << "\nEnter a word:";
    cin >> c; 

    char firstLetter = c[0];
    cout << firstLetter << endl;
    cout << static_cast<int>(firstLetter) << endl;



    return 0;
}