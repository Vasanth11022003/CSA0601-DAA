#include <stdio.h>

int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    int num;
    printf("Enter an integer: ");
    
    if (scanf("%d", &num) != 1) {
        printf("Illegal input\n");
        return 1;
    }
    
    int reversed = reverseNumber(num);
    printf("Reversed number: %d\n", reversed);

    return 0;
}

------------------------------------------------------------------------------------------------------
OUTPUT:

Enter an integer: 725372
Reversed number: 273527
