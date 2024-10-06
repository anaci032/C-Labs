/*myFile2.cpp : Ex2 a2 CSI2372A*/

#include "myFile2.h"

int main() {
	int myArray[sizeArray] = { 2,4,88,20,3,55,87,134,2,5 };

	cout << "Displaying the unsorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout <<  endl << endl;
	sort(myArray, sizeArray);
	cout << "Displaying the sorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl;
}

void sort(int a[], int size)
{
	//YOUR CODE HERE
	//used pointers for optimization
	//go through array index by index
	for (int i=0;i<size;i++){
		//doesn't compare values to the left
		for (int j=i+1;j<size;j++){
			//when a value of a higher index is greater it is moved before reference index
			if (*(a+i) > *(a+j)){
				int tmp = *(a+j);
				//all other values are shifted
				for(int k=j;k>i;k--){
					*(a+k)=*(a+k-1);
				}
				//tmp value allocated to reference index
				*(a+i)=tmp;
			}
		}
	}
}