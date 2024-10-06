/*myFile3.cpp : Ex3 a2 CSI2372A*/

#include <iostream>
using namespace std;

int** triangleInf(int size) {
    int** tab = new int*[size];
    for (int i = 0; i < size; i++) {
		//allocate memory for each row
        tab[i] = new int[i + 1];  
        //the first and last value in every row is 1 always
        tab[i][0] = 1;
        tab[i][i] = 1;
        //rest of values are the sum of the two values above it
        for (int j = 1; j < i; j++) {
            tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
        }
    }
    return tab;
}

int main() {
	int** tab;
	const int size = 10;
	tab = triangleInf(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}