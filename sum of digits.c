#include <stdio.h>

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int maxSumOfDigits(int nums[], int size) {
    int maxSum = -1,i,j;
    
    for ( i = 0; i < size; i++) {
        for ( j = i + 1; j < size; j++) {
            if (sumOfDigits(nums[i]) == sumOfDigits(nums[j])) {
                int currentSum = nums[i] + nums[j];
                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
            }
        }
    }
    
    return maxSum;
}

int main() {
    int nums[10],size,i;
	printf("enter the size of the array:");
	scanf("%d",&size);
	printf("enter the array elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&nums[i]);
	}
    
    int result = maxSumOfDigits(nums, size);
    printf("Maximum value of nums[i] + nums[j]: %d\n", result);
    
    return 0;
}
