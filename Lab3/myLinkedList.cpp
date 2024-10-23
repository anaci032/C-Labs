/*Ex2 - a3 CSI2372A
Student Name: Ayman Naciri
Student Number: 300143727
Course Code: CSI2372A*/

#include <iostream>
#include "myLinkedList.h"

using namespace std;

int main()
{
    Evaluation* first = nullptr;
    int choice;
    int number = 0;

    do
    {
        cout << endl << endl << "1) Display of the complete linked list.\n";
        cout << "2) Insert an element\n";
        cout << "3) Remove an element.\n";
        cout << "4) Calculation of the class average.\n";
        cout << "5) Exit the program.\n" << endl << endl;
        cout << "Your choice ??:";

        //validate user input
        while (!(cin >> choice) || choice < 1 || choice > 5) {
			//clear the error flag
            cin.clear(); 
			//discard invalid input
            cin.ignore(10000, '\n');  
            cout << "Invalid input. Please enter a valid number between 1 and 5.\n";
            cout << "Your choice ??:";
        }

        switch (choice)
        {
        case 1: display(first);
            break;
        case 2: first = add(first, number);
            break;
        case 3: first = remove(first, number);
            break;
        case 4: average(first, number);
            break;
        case 5: exit(0);
        default:
            break;
        }
    } while (true);
    
    return 0;
}

/**
*add() Function*
**/
Evaluation* add(Evaluation* head, int& count) {
    Evaluation* newEval = new Evaluation;
    
    cout << "After which element do you want to insert? (0 for start): ";
    int position;
    cin >> position;
    
    //name&grade
    cout << "Enter the student name: ";
    cin.ignore();
    //soft cap
	cin.getline(newEval->student, 100);
    cout << "Enter the grade: ";
    cin >> newEval->grade;

    if (position < 0 || position > count) {
        cout << "Invalid position!" << endl;
        delete newEval; //invalid pos
        return head;
    }

    //position 0
    if (position == 0) {
        newEval->next = head;
        head = newEval;
    } else {
        //select position
        Evaluation* current = head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        newEval->next = current->next;
        current->next = newEval;
    }

    count++;
    return head;
}

/**
*remove() Function*
**/
Evaluation* remove(Evaluation* head, int& count) {
    cout << "Enter the number of the element to delete: ";
    int position;
    cin >> position;

    if (position < 1 || position > count) {
        cout << "Invalid position!" << endl;
        return head;
    }

    Evaluation* toDelete;
    if (position == 1) {
        //remove 1
        toDelete = head;
        head = head->next;
    } else {
        //remove select
        Evaluation* current = head;
        for (int i = 0; i < position - 2; ++i) {
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;
    }

    delete toDelete;
    count--;
    return head;
}

/**
*display() Function*
**/
void display(Evaluation* head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    
    Evaluation* current = head;
    while (current != nullptr) {
        cout << "Student: " << current->student << ", Grade: " << current->grade << endl;
        current = current->next;
    }
}

/**
*average() Function*
**/
int average(Evaluation* head, int const& count) {
    if (count == 0) {
        cout << "No students to calculate average." << endl;
        return 0;
    }

    Evaluation* current = head;
    int sum = 0;
    while (current != nullptr) {
        sum += current->grade;
        current = current->next;
    }

    cout << "The average grade is: " << static_cast<double>(sum) / count << endl; // Ensures decimal output
    return 1;
}
