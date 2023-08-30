#include <stdio.h>
void printPascal(int n)
{
	int line,space,i;
    for ( line = 1; line <= n; line++) {
        for ( space = 1; space <= n - line; space++)
            printf("  ");

        int coef = 1;
        for ( i = 1; i <= line; i++) {

            printf("%4d", coef);
            coef = coef * (line - i) / i;
        }
        printf("\n");
    }
}
  
int main()
{
    int n;
    printf("enter a number:");
    scanf("%d",&n);
    printPascal(n);
    return 0;
}
