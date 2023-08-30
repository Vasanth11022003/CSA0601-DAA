#include <stdio.h>

int isPerfect(int num) {
    int sum = 1;
    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return (sum == num);
}

void printPerfectNumbers(int n) {
    int count = 0, num = 2;
    printf("The first %d perfect numbers are:\n", n);
    while (count < n) {
        if (isPerfect(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printPerfectNumbers(n);
    return 0;
}

