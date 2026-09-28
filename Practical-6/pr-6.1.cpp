#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

// Push - add tray
void push(int tray) {
    if (top == SIZE - 1) {
        cout << "Stack is FULL\n";
        return;
    }

    top++;
    stack[top] = tray;
    cout << "Tray added: " << tray << endl;
}

// Pop - remove tray
void pop() {
    if (top == -1) {
        cout << "Stack is EMPTY\n";
        return;
    }

    cout << "Tray removed: " << stack[top] << endl;
    top--;
}

// Display stack
void display() {
    if (top == -1) {
        cout << "Stack is EMPTY\n";
        return;
    }

    cout << "Stack: ";

    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";

    cout << endl;
}

int main() {

    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    pop();
    display();

    return 0;
}
