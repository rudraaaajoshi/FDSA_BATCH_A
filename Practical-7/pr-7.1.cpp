#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int token[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Add token
    void join(int x) {
        // Queue is full
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is full. Token cannot be added.\n";
            return;
        }

        // First token
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % SIZE;
        }

        token[rear] = x;
        cout << "Token " << x << " joined the queue.\n";
    }

    // Serve token
    void serve() {
        if (front == -1) {
            cout << "Queue is empty. No token to serve.\n";
            return;
        }

        cout << "Token " << token[front] << " is served.\n";

        // Only one token was present
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % SIZE;
        }
    }

    // Display front token
    void displayFront() {
        if (front == -1) {
            cout << "Queue is empty.\n";
        }
        else {
            cout << "Front token: " << token[front] << endl;
        }
    }

    // Display complete queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue: ";

        int i = front;

        while (true) {
            cout << token[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    q.join(1);
    q.join(2);
    q.join(3);

    q.display();

    q.serve();
    q.display();

    q.join(4);
    q.join(5);
    q.join(6);

    q.display();

    q.displayFront();

    return 0;
}
