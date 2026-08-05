#include <stdio.h>

int main() {
    int n;

    printf("Enter number of borrow records: ");
    scanf("%d", &n);

    int book[n];

    printf("Enter Book IDs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &book[i]);
    }

    printf("Book IDs borrowed more than once:\n");

    for (int i = 0; i < n; i++) {
        int count = 1;
        int printed = 0;

        // Check if already printed
        for (int k = 0; k < i; k++) {
            if (book[i] == book[k]) {
                printed = 1;
                break;
            }
        }

        if (printed)
            continue;

        // Count occurrences
        for (int j = i + 1; j < n; j++) {
            if (book[i] == book[j])
                count++;
        }

        if (count > 1)
            printf("%d ", book[i]);
    }

    return 0;
}