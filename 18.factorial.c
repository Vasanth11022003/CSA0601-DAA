#include<stdio.h>
int fact(n)
{
    if(n>=1)
	{
		return n*fact(n-1);
	}
	else
	{
		return 1;
	}
}
int main()
{
	int n;
	printf("enter a number:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("negative number:");
	}
	else{
	printf("factorial of number:%d",fact(n));
}
}
