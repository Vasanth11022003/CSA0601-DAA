#include<stdio.h>
int main()
{
	int i,arr[20];
    int n,t,j,m,k;
    printf("enter m position:");
    scanf("%d",&m);
    printf("enter nth position:");
    scanf("%d",&k);
    if(m>0)
    {
    	if(m>n)
    	{
		
	
    printf("enter the length of the array:");
    scanf("%d",&n);
    printf("enter the array elements");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]<arr[j])
			{
				t=arr[i];
				arr[i]=arr[j];
				arr[i]=t;
			}
		}
	}
	printf("mth maximum number:%d\n",arr[m-1]);
	printf("nth minimum number:%d\n",arr[n-k]);
	printf("sum is:%d\n",arr[m-1]+arr[n-k]);
	printf("difference is:%d\n",arr[m-1]-arr[n-k]);
}
}
else
{
	printf("invalid input");
}
   
}
