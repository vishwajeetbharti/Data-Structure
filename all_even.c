#include<stdio.h>
#include<stdlib.h>
int sum=0;
int oddsum=0;
int odd(int n)
{
	if(n%2!=0&&n>=0)
	{
		oddsum=oddsum+n;
		n=n-2;
		if(n<=0)
		return 0;
		odd(n);
	}
	else
	{
		n=n-1;
		if(n<=0)
		return 0;
		odd(n);
	}
}
int addition(int n)
{
	if(n%2==0&&n>=0)
	{
		sum=sum+n;
		n=n-2;
		if(n<=0)
		return 0;
		addition(n);
	}
	else
	{
		n=n-1;
		if(n<=0)
		return 0;
		addition(n);
	}
}

void main()
{
	int i;
	printf("Enter the number for add all even natural number.\n");
	scanf("%d",&i);
	addition(i);
	odd(i);
	printf("\nEven:- %d\nOdd:- %d",sum,oddsum);
}
