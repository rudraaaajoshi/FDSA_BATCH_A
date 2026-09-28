#include <iostream>
#include <stack>
using namespace std;

int priority(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main() {
    string infix;
    stack<char> s;
    string postfix = "";

    cout << "Enter expression: ";
    cin >> infix;

    for (char ch : infix) {

        // If operand
        if (isalnum(ch)) {
            postfix += ch;
        }

        // Opening bracket
        else if (ch == '(') {
            s.push(ch);
        }

        // Closing bracket
        else if (ch == ')') {
            while (s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();   // remove '('
        }

        // Operator
        else {
            while (!s.empty() && priority(s.top()) >= priority(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Remove remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix: " << postfix;

    return 0;
}
