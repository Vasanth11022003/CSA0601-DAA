\#include <stdio.h>
#include <time.h>

int linear_search(int arr[], int size, int key) {
    clock_t start_time = clock();
    int position = -1,i;
    for ( i = 0; i < size; i++) {
        if (arr[i] == key) {
            position = i;
            break;
        }
    }
    clock_t end_time = clock();
    return position;
}

int main() {
	int a[10],key,n,i;
	printf("enter array length:");
	scanf("%d",&n);
	printf("enter array elements:");
	for(i=0;i<n;i++)
	{
	 scanf("%d",&a[i]);	
	}
	printf("enter a key to search");
	scanf("%d",&key);
    
    int position = linear_search(a, n, key); 
    if (position == -1) {
        printf("Element %d Not Found\n", key);
    } else {
        printf("Element %d found in position %d\n", key, position);
    }

    return 0;
}
