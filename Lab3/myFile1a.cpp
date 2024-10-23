/*Ex1a - a3 CSI2372A
Student Name: Ayman Naciri
Student Number: 300143727
Course Code: CSI2372A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card{
	Color color;
	Face face;
};

int main(){
	Card game[32];
	//YOUR CODE HERE
	int index = 0;
	//build deck from combination of face and color
	for (int c = club; c <= heart; ++c){
		for (int f = seven; f <= ace; ++f) {
            game[index].color = static_cast<Color>(c);
            game[index].face = static_cast<Face>(f);
            index++;
        }
	}

	//display the deck
	for (int i = 0; i < 32; ++i) {
        cout << "Card " << i + 1 << ": Color = " << game[i].color << ", Face = " << game[i].face << endl;
    }
	return 0;
}

