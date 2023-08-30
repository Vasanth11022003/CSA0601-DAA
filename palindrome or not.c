#include<stdio.h>
#include<string.h>
int main()
{
	char s1[10];
	int i,flag=0;
	printf("enter a string:");
	gets(s1);
	int len=strlen(s1);
    for(i=0;i<=len;i++)
    {
    	if(s1[i]!=s1[len-i-1])
    	{
    		flag=1;
    		break;
		}
    }
    if(flag==1)
	{
		printf("string not is palindrome");
	}
	else
	{
		printf("string is palindrome");
	}
}
