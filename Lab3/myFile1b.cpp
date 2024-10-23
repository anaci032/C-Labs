/*Ex1b - a3 CSI2372A
Student Name: Ayman Naciri
Student Number: 300143727
Course Code: CSI2372A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card
{
	Color color;
	Face face;
};

typedef Card Hand[5];

/* testPair() function*/
bool testPair(const Hand& h)
{
	//YOUR CODE  
	//go through deck card by card similar to sort algorithm
	for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (h[i].face == h[j].face) {
				// return pair
                return true;  
            }
        }
    }
	// return no pairs have been found
    return false;
}


/*Example of main()*/
int main() {
    Hand myHand = { {club, nine}, {diamond, eight}, {spades, ace}, {spades, jack}, {club, ace} };
    //example with no pairs:
	//Hand myHand = { {club, nine}, {diamond, eight}, {spades, ace}, {spades, jack}, {club, queen} };
	//example with 2 pairs: (output should still say at least 1 pair)
	// Hand myHand = { {club, nine}, {diamond, nine}, {spades, ace}, {spades, ace}, {club, queen} };
	cout << "\nI have at least: " << (testPair(myHand) ? "1 pair" : "no pair") << endl;
    return 0;
}


