#include <stdio.h>

void merge(int arr[], int left[], int right[], int leftSize, int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] >= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];
	int i;
    for ( i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for ( i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, right, mid, size - mid);
}

int main() {
     int m, n;
     int i;
    printf("Enter the number of elements in numsl: ");
    scanf("%d", &m);

    printf("Enter the number of elements in nums2: ");
    scanf("%d", &n);

    int A[10],B[10];
    printf("enter a elements in array1:");
    for(i=0;i<m;i++)
    {
    	scanf("%d",&A[i]);
	}
	printf("enter a elements in array2:");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&B[i]);
	}

    int merged[m + n];

    for (i = 0; i < m; i++) {
        merged[i] = A[i];
    }

    for (i = 0; i < n; i++) {
        merged[m + i] = B[i];
    }

    mergeSort(merged, m + n);

    printf("Merged array: ");
    for (i = 0; i < m + n; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
