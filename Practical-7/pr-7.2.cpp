
#include <iostream>
using namespace std;

struct Node {
    int patient;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Add patient
void arrive(int x) {
    Node* newNode = new Node;

    newNode->patient = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Patient " << x << " arrived." << endl;
}

// Attend patient
void attend() {
    if (front == NULL) {
        cout << "Ward is empty. No patient to attend." << endl;
        return;
    }

    cout << "Patient " << front->patient << " attended." << endl;

    Node* temp = front;
    front = front->next;

    delete temp;

    if (front == NULL) {
        rear = NULL;
    }
}

// Display front patient
void displayFront() {
    if (front == NULL) {
        cout << "No patient waiting." << endl;
    }
    else {
        cout << "Current front patient: "
             << front->patient << endl;
    }
}

int main() {

    arrive(101);
    displayFront();

    arrive(102);
    displayFront();

    arrive(103);
    displayFront();

    attend();
    displayFront();

    attend();
    displayFront();

    arrive(104);
    displayFront();

    return 0;
}
