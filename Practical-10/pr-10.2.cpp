#include <iostream>
using namespace std;

struct Node
{
    int book;
    Node* next;
};

int main()
{
    Node* shelf[10] = {NULL};

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int code;
        cout << "Enter book code: ";
        cin >> code;

        // Find shelf using modulo 10
        int index = code % 10;

        // Create new node
        Node* newNode = new Node;
        newNode->book = code;
        newNode->next = NULL;

        // Add book to shelf
        if (shelf[index] == NULL)
        {
            shelf[index] = newNode;
        }
        else
        {
            Node* temp = shelf[index];

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Display all shelves
    cout << "\nFinal Shelf Contents:\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "Shelf " << i << ": ";

        Node* temp = shelf[i];

        if (temp == NULL)
        {
            cout << "Empty";
        }

        while (temp != NULL)
        {
            cout << temp->book << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    return 0;
}
