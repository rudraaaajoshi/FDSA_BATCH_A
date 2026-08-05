#include <stdio.h>

// Iterative binary search
int searchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // not found
}

// Recursive binary search
int searchRecursive(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // base case: search space exhausted
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return searchRecursive(arr, mid + 1, high, target); // search right half
    } else {
        return searchRecursive(arr, low, mid - 1, target); // search left half
    }
}

int main() {
    int n;
    printf("Enter number of book codes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter sorted book codes:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int target;
    printf("Enter target code to find: ");
    scanf("%d", &target);

    int posIter = searchIterative(arr, n, target);
    int posRec = searchRecursive(arr, 0, n - 1, target);

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