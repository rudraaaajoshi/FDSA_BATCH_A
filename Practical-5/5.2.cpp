#include <iostream>
using namespace std;

// ---------- SINGLY CIRCULAR LINKED LIST ----------

struct SNode {
    int data;
    SNode *next;
};

SNode *shead = NULL;

// Join a student
void joinSingly(int x) {
    SNode *n = new SNode;
    n->data = x;

    if (shead == NULL) {
        shead = n;
        n->next = shead;
    }
    else {
        SNode *temp = shead;

        while (temp->next != shead)
            temp = temp->next;

        temp->next = n;
        n->next = shead;
    }
}

// Leave a student
void leaveSingly(int x) {
    if (shead == NULL)
        return;

    SNode *temp = shead;
    SNode *prev = NULL;

    do {
        if (temp->data == x)
            break;

        prev = temp;
        temp = temp->next;
    } while (temp != shead);

    if (temp->data != x) {
        cout << "Student not found\n";
        return;
    }

    // Only one student
    if (temp == shead && temp->next == shead) {
        shead = NULL;
        delete temp;
        return;
    }

    // First student leaves
    if (temp == shead) {
        SNode *last = shead;

        while (last->next != shead)
            last = last->next;

        shead = shead->next;
        last->next = shead;
        delete temp;
    }
    else {
        prev->next = temp->next;
        delete temp;
    }
}

// Display
void displaySingly() {
    if (shead == NULL) {
        cout << "Circle is empty\n";
        return;
    }

    SNode *temp = shead;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != shead);

    cout << endl;
}


// ---------- DOUBLY CIRCULAR LINKED LIST ----------

struct DNode {
    int data;
    DNode *prev;
    DNode *next;
};

DNode *dhead = NULL;

// Join a student
void joinDoubly(int x) {
    DNode *n = new DNode;
    n->data = x;

    if (dhead == NULL) {
        dhead = n;
        n->next = n;
        n->prev = n;
    }
    else {
        DNode *last = dhead->prev;

        n->next = dhead;
        n->prev = last;

        last->next = n;
        dhead->prev = n;
    }
}

// Leave a student
void leaveDoubly(int x) {
    if (dhead == NULL)
        return;

    DNode *temp = dhead;

    do {
        if (temp->data == x)
            break;

        temp = temp->next;
    } while (temp != dhead);

    if (temp->data != x) {
        cout << "Student not found\n";
        return;
    }

    // Only one student
    if (temp->next == temp) {
        dhead = NULL;
        delete temp;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == dhead)
        dhead = temp->next;

    delete temp;
}

// Display
void displayDoubly() {
    if (dhead == NULL) {
        cout << "Circle is empty\n";
        return;
    }

    DNode *temp = dhead;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != dhead);

    cout << endl;
}


// ---------- MAIN ----------

int main() {

    cout << "SINGLY CIRCULAR LIST\n";

    joinSingly(1);
    joinSingly(2);
    joinSingly(3);

    cout << "After joining: ";
    displaySingly();

    leaveSingly(2);

    cout << "After student 2 leaves: ";
    displaySingly();


    cout << "\nDOUBLY CIRCULAR LIST\n";

    joinDoubly(1);
    joinDoubly(2);
    joinDoubly(3);

    cout << "After joining: ";
    displayDoubly();

    leaveDoubly(2);

    cout << "After student 2 leaves: ";
    displayDoubly();

    return 0;
}