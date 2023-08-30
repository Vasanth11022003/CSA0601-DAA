#include <stdio.h>

int binary_search(int nums[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int nums[10],target,size;
    int i;
    printf("enter the length:");
    scanf("%d",&size);
    printf("enter the array elements:");
    for(i=0;i<size;i++)
    {
      scanf("%d",&nums[i]);	
	}
	printf("enter a target to search:");
	scanf("%d",&target);
    
    int result = binary_search(nums, size, target);
    if (result != -1) {
        printf("Target %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found in the array\n", target);
    }
    
    return 0;
}
