#include <iostream>
using namespace std;

struct Node {
    string page;
    Node *next;
};

Node *top = NULL;

// Visit a new page
void visit(string page) {
    Node *newNode = new Node;
    newNode->page = page;
    newNode->next = top;
    top = newNode;

    cout << "Current page: " << top->page << endl;
}

// Back button
void back() {
    if (top == NULL) {
        cout << "No history left\n";
        return;
    }

    Node *temp = top;
    top = top->next;
    delete temp;

    if (top != NULL)
        cout << "Current page: " << top->page << endl;
    else
        cout << "No page left\n";
}

int main() {

    visit("Google");
    visit("YouTube");
    visit("Instagram");

    back();
    back();
    back();
    back();

    return 0;
}
