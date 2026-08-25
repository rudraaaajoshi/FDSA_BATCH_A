#include <iostream>
using namespace std;

struct Node {
    int token;
    Node* next;
};

Node* head = NULL;

// Insert at end
void insert(int x) {
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

// Delete by value
void deleteToken(int x) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->token != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Token not found" << endl;
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
}

// Forward printing
void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->token << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Reverse printing
void reversePrint(Node* temp) {
    if (temp == NULL)
        return;

    reversePrint(temp->next);
    cout << temp->token << " ";
}

int main() {
    insert(101);
    insert(102);
    insert(103);
    insert(104);

    cout << "Queue: ";
    display();

    deleteToken(102);

    cout << "After deletion: ";
    display();

    cout << "Reverse: ";
    reversePrint(head);

    return 0;
}
