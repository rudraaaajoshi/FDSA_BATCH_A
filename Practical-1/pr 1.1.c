#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, h;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number of hours: ");
    scanf("%d", &h);

    // Key optimization: reduce h to an effective shift within [0, n)
    int shift = h % n;

    int result[n];
    for (int i = 0; i < n; i++) {
        result[i] = arr[(i + shift) % n];
    }

    printf("Final display order: ");
    printArray(result, n);

    return 0;
}