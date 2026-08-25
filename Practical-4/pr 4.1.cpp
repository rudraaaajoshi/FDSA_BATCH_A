#include <iostream>
using namespace std;

struct Node {
    int token;
    Node* next;
};

Node* head = NULL;


void insertFront(int x) {
    Node* newNode = new Node;
    newNode->token = x;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int x) {
    Node* newNode = new Node;
    newNode->token = x;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


void insertPosition(int x, int pos) {
    if (pos == 1) {
        insertFront(x);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->token = x;
    newNode->next = temp->next;
    temp->next = newNode;
}


void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    insertFront(101);
    display();

    insertEnd(102);
    display();

    insertEnd(103);
    display();

    insertPosition(104, 2);
    display();

    return 0;
}
