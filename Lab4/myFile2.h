// myFile2.h
#include <cstdlib>
#include <iostream>
using namespace std;

class SetInt {
public:
    SetInt() : elem(nullptr), size(0) {}  // constructor
    //initialize with an int array
    SetInt(int arr[], int arrSize) : size(arrSize) {
        elem = new int[size];
        for (int i = 0; i < size; i++) {
            elem[i] = arr[i];
        }
    }

    SetInt(const SetInt& other) : size(other.size) { //copy constr
        elem = new int[size];
        for (int i = 0; i < size; i++) {
            elem[i] = other.elem[i];
        }
    }

    ~SetInt() {//destruct
        delete[] elem;
    }

    
    void add(int n) { //add int to  set if not there already
        int pos;
        if (!containsIn(n, pos)) {  //check if 'n' is in the set
            int* newElem = new int[size + 1];
            for (int i = 0; i < size; i++) {
                newElem[i] = elem[i];
            }
            newElem[size] = n;
            delete[] elem;
            elem = newElem;
            size++;
        }
    }

    
    void remove(int n) { //remove an int from the set if exists
        int pos;
        if (containsIn(n, pos)) {  // check if 'n' is in the set
            for (int i = pos; i < size - 1; i++) {
                elem[i] = elem[i + 1];
            }
            size--;
        }
    }
    bool contains(int n) {//check if set contains an int
        int pos;
        return containsIn(n, pos);
    }

    
    int nbElem() const {//return number of elements in set
        return size;
    }

    
    int* tabElem() const {// return an array of elements in the set
        if (size == 0) return nullptr;  // if set is empty return nullptr
        int* newArr = new int[size];
        for (int i = 0; i < size; i++) {
            newArr[i] = elem[i];
        }
        return newArr;
    }

private:
    int* elem;
    int size;
    //helper function
    bool containsIn(int n, int &pos) const {
        for (int i = 0; i < size; i++) {
            if (elem[i] == n) {
                pos = i;
                return true;
            }
        }
        return false;
    }
};
