#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

void generatePermutations(int arr[], int size, int n) {
	int i;
    if (size == 1) {
        printArray(arr, n);
        return;
    }

    for (i = 0; i < size; i++) {
        generatePermutations(arr, size - 1, n);

        if (size % 2 == 1) {
            swap(&arr[0], &arr[size - 1]);
        } else {
            swap(&arr[i], &arr[size - 1]);
        }
    }
}

int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Possible permutations:\n");
    generatePermutations(arr, n, n);

    return 0;
}

