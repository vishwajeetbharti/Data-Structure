#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_size 4
int stack[max_size],top=-1,flag=1,count=-1;
int i,temp,item,rev[max_size],num[max_size];
void push()
{
	if(top==max_size-1)
	{
		printf("Stack Overflow.");
	}
	else
	{
		printf("Enter the element to be inserted:-\n");
		scanf("%d",&item);
		top++;
		stack[top]=item;
	}
	temp=top;
}
void pop()
{
	if(top==-1)
	{
		printf("Stack Underflow:");
		flag=0;
	}
	else
	{
		item=stack[top];
		top=top-1;
	}
}
void palin()
{
	if(top==-1)
	{
		printf("Push some elements into the stack.\n");
	}
	else
	{
	    temp=top;
		for(i=0;i<=temp;i++)
		 {
		 	rev[i]=stack[top];
		 	top--;
		 }
		 for(i=0;i<=temp;i++)
		 {
		 	if(stack[i]==rev[i])
		 	count++;
		 }
		 top=temp;
		if(count==temp)
		printf("Palindrome.\n");
		else
		printf("Not Palindrome.\n");
	}
}
	void display()
	{
		if(top==-1)
		{
			printf("\nStack is empty:");
		}
		else
		{
			printf("\nThe stack elements are:\n");
			for(i=top;i>=0;i--)
			{
				printf("%d\t",stack[i]);
			}
		}
	}

int main()
{
	int choice;
	for(;;)
	{
		printf("\n\n----STACK OPERATION----\n1.Push\n2.Pop\n3.Palindrome\n4.Dispaly\n5.Exit\n------------------------\nEnter your choice:-\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();
			break;
			case 2:pop();
			if(flag)
			printf("\nThe poped element: %d\t",item);
			temp=top;
			break;
			case 3:palin();
			top=temp;
			break;
		    case 4:display();
		    break;
		    case 5:exit(0);
		    break;
		    default:
			printf("\nInvalid choice:\n");
            break;
			
		}
	}
	return 0;
}
