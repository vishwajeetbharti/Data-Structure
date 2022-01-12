#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#define QUEUE_SIZE 5
int front=0,rear=-1,count=0,q[QUEUE_SIZE],item,itemdel;

void insert()
{
	if(count==(QUEUE_SIZE-1))
	{
		printf("Circular queue overflow\n");
	}
	else
	{
		printf("Enter the item to be inserted\n");
		scanf("%d",&item);
		rear=(rear+1)%QUEUE_SIZE;
		printf("%d",&rear);
		q[rear]=item;
		count++;
	}
}
void del()
{
	if(count==0)
	{
		printf("Circular queue underflow\n");
	}
	else
	{
		itemdel=q[front];
		printf("Item deleted is %d\n",itemdel);
		front=(front+1)%QUEUE_SIZE;
		count--;
	}
}
void display()
{
	int i,f;
	if(count==0)
	{
		printf("Circular queue underflow\n");
	}
	else
	{
		printf("The Circular queue are\n");
		for(i=1,f=front;i<=count;i++)
		{
			printf("%d\t",q[f]);
			f=(f+1)%QUEUE_SIZE;
		}
	}
}
void main()
{
	int ch;
	//clrscr();
	printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	while(1)
	{
		printf("\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert();
			break;
			case 2: del();
			break;
			case 3: display();
			break;
			case 4: exit(0);
		}
	}
}
