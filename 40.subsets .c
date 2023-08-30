#include <stdio.h>

void generateSubsets(int arr[], int subset[], int index, int n) {
    if (index == n) {
    	int i;

        printf("{ ");
        for (i = 0; i < n; i++) {
            if (subset[i] == 1) {
                printf("%d ", arr[i]);
            }
        }
        printf("}\n");
        return;
    }

    subset[index] = 1;
    generateSubsets(arr, subset, index + 1, n);

    subset[index] = 0;
    generateSubsets(arr, subset, index + 1, n);
}

int main() {
    int n,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int subset[n];
    printf("All possible subsets:\n");
    generateSubsets(arr, subset, 0, n);

    return 0;
}

