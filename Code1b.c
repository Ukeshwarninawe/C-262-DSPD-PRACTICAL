#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int arr[], int n, int key) {
    if (arr == NULL || n == 0) {
        printf("NULL\n");
        return false;
    }

    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        printf("Examining value: %d at index %d\n", arr[mid], mid);

        if (arr[mid] == key) {
            printf("Value found at index %d\n", mid);
            return true;
        }
        else if (key > arr[mid]) {
            printf("Value is greater than midpoint. Adjusting start to index %d\n", mid + 1);
            start = mid + 1;
        }
        else {
            printf("Value is less than midpoint. Adjusting end to index %d\n", mid - 1);
            end = mid - 1;
        }
    }

    printf("Value not found.\n");
    return false;
}

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("NULL\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements (sorted order):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    binarySearch(arr, n, key);

    return 0;
}