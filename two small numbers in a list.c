#include <stdio.h>
#include <limits.h>

void findFirstTwoMin(int arr[], int n) {
    if (n < 2) {
        printf("Not enough elements to find two minimum values.\n");
        return;
    }

    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }

    if (min1 == INT_MAX || min2 == INT_MAX) {
        printf("Unable to find two distinct minimum values.\n");
    } else {
        printf("(%d, %d)\n", min1, min2);
    }
}

int main() {
    int n;
    int i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findFirstTwoMin(arr, n);

    return 0;
}

