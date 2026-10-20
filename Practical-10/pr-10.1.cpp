#include <iostream>
using namespace std;

#define SIZE 10

int main()
{
    int table[SIZE];

    // Initially all slots are empty
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int reg;
        cout << "Enter registration number: ";
        cin >> reg;

        // Last digit gives the initial slot
        int index = reg % 10;
        int start = index;

        // Find an empty slot
        while (table[index] != -1)
        {
            index = (index + 1) % SIZE;

            // Parking lot is full
            if (index == start)
            {
                cout << "Parking lot is full!" << endl;
                break;
            }
        }

        // Insert vehicle
        if (table[index] == -1)
            table[index] = reg;
    }

    // Display parking lot
    cout << "\nFinal Parking Slots:\n";

    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] == -1)
            cout << "Slot " << i << " : Empty" << endl;
        else
            cout << "Slot " << i << " : " << table[i] << endl;
    }

    return 0;
}
