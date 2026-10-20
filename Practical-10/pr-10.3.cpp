#include <iostream>
using namespace std;

#define SIZE 10

int main()
{
    int table[SIZE];

    // Make all slots empty
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int id;
        cout << "Enter student ID: ";
        cin >> id;

        // First hash function
        int h1 = id % SIZE;

        // Second hash function
        int h2 = 7 - (id % 7);

        int index = h1;
        int j = 0;

        // Find an empty slot
        while (table[index] != -1)
        {
            j++;
            index = (h1 + j * h2) % SIZE;

            // Table is full
            if (j == SIZE)
            {
                cout << "Table is full!" << endl;
                break;
            }
        }

        // Insert ID
        if (table[index] == -1)
            table[index] = id;
    }

    // Display table
    cout << "\nFinal Hash Table:\n";

    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] == -1)
            cout << "Slot " << i << " : Empty" << endl;
        else
            cout << "Slot " << i << " : " << table[i] << endl;
    }

    return 0;
}
