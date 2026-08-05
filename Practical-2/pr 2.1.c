#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

// Iterative approach - guard checks one by one himself
int searchIterative(char plates[][MAX_LEN], int n, char target[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(plates[i], target) == 0) {
            return i;  // found at this position
        }
    }
    return -1; // not found
}

// Recursive approach - guard calls a helper to continue from current position
int searchRecursive(char plates[][MAX_LEN], int n, char target[], int index) {
    if (index >= n) {
        return -1; // base case: reached end, not found
    }
    if (strcmp(plates[index], target) == 0) {
        return index; // found at this position
    }
    return searchRecursive(plates, n, target, index + 1); // hand off to helper
}

int main() {
    int n;
    printf("Enter number of vehicles: ");
    scanf("%d", &n);

    char plates[n][MAX_LEN];
    printf("Enter license plates:\n");
    for (int i = 0; i < n; i++)
        scanf("%s", plates[i]);

    char target[MAX_LEN];
    printf("Enter target plate to find: ");
    scanf("%s", target);

    int posIter = searchIterative(plates, n, target);
    int posRec = searchRecursive(plates, n, target, 0);

    if (posIter != -1)
        printf("Iterative search: Found at position %d\n", posIter);
    else
        printf("Iterative search: Not found\n");

    if (posRec != -1)
        printf("Recursive search: Found at position %d\n", posRec);
    else
        printf("Recursive search: Not found\n");

    return 0;
}