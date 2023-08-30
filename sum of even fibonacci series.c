#include <stdio.h>

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);

    int a = 1, b = 2, c = a + b, even_sum = 2;

    while (c <= N) {
        if (c % 2 == 0) {
            even_sum += c;
        }
        a = b;
        b = c;
        c = a + b;
    }

    printf("Sum of even Fibonacci numbers up to %d is: %d\n", N, even_sum);

    return 0;
}

