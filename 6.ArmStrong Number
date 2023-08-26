#include <stdio.h>
int main() {
    int num, originalNum, remainder, result = 0;
    printf("Enter a three-digit integer: ");
    scanf("%d", &num);
    originalNum = num;

    while (originalNum != 0) {
    
        remainder = originalNum % 10;
        
       result += remainder * remainder * remainder;
   
       originalNum /= 10;
    }

    if (result == num)
        printf("true");
    else
        printf("false");

    return 0;
}

---------------------------------------------------------------------
OUTPUT:

Enter a three-digit integer: 153
true
