#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Enode
{
	int sn;
	char name[10];
	char branch[5];
	int usn;
	struct Enode *left;
	struct Enode *right;
	
};
struct Enode *head=NULL;
struct Enode *tail=NULL,*temp=NULL,*temp1=NULL;
int count=0;

void create(int s,char n,char b,int u)
{
	if(head==NULL)
	{
		head=(struct Enode*)malloc(1*sizeof(struct Enode));
		head->sn=s;
		strcpy(head->name,n);
        strcpy(head->branch,b);
        head->usn=u;
        head->left=NULL;
        head->right=NULL;
        tail=head;
        count++;
	}
	else
	{
		temp1=(struct Enode*)malloc(1*sizeof(struct Enode));
        temp1->sn=s;
		strcpy(temp1->name,&n);
        strcpy(temp1->branch,&b);
        temp1->usn=u;
        tail->right=temp1;
        temp1->right=NULL;
        temp1->left=tail;
        tail=temp1;
        count++;
	}
}
void display()
{
	temp1=head;
	printf("Students Details...\n");
	if(temp1==NULL)
	{
		printf("\nList is Empty...");
	}
	else
	{
		printf("Students Details...\n");
		while(1)
		{
			printf("***   ***   ***\n");
			printf("Serial No:-%d.\nName:-%s\nBranch:-%s\nUSN:-%d\n",temp1->sn,temp1->name,temp1->branch,temp1->usn);
			printf("***   ***   ***\n");
			temp1=temp1->right;
		}
		printf("The no. of students are %d",count);
	}
}

void ins_beg(int s,char n,char b,int u)
{
	temp1=(struct Enode*)malloc(1*sizeof(struct Enode));
	temp1->sn=s;
	strcpy(temp1->name,&n);
    strcpy(temp1->branch,&b);
    temp1->usn=u;
    if(head==NULL)
    {
    	head=tail=temp1;
    	count++;
    	return;
	}
	temp1->right=head;
	head->left=temp1;
	head=temp1;
	temp1->left=NULL;
	count++;
}
void ins_end(int s,char n,char b,int u)
{
	temp1=(struct Enode*)malloc(1*sizeof(struct Enode));
	temp1->sn=s;
	strcpy(temp1->name,&n);
    strcpy(temp1->branch,&b);
    temp1->usn=u;
    if(tail==NULL)
    {
    	head=tail=temp1;
    	count++;
    	return;
	}
	else
	{
		tail->right=temp1;
		temp1->left=tail;
		temp1->right=NULL;
		tail=temp1;
		count++;
	}
}
void del_beg()
{
	if(head==NULL)
	{
		printf("deletion not possible");
		return;
	}
	else
	{
		temp1=head;
		head=head->right;
		free(temp1);
		count--;
	}
}
void del_end()
{
	temp1=head;
	if(head==NULL)
	{
		printf("deletion not possible");
		return;
	}
	else if(temp1->left==NULL&&temp1->right==NULL)
	{
		free(temp1);
		head=tail=NULL;
		count--;
	}
	else
	{
		while(temp1!=tail)
		{
			temp1=temp1->right;
		}
		tail=tail->left;
		tail->right=NULL;
		free(temp1);
		count--;
	}
}
void main()
{
	int choice,i,no;
	char nam[10],branch[5];
	int sn,usn;
	while(1)
	{
		printf("1.Create.\n2.Display.\n3.Insert at beginning.\n4.Insert at End.\n5.Delete at beginning.\n6.Delete at End.\n7.Exit\n");
		printf("Enter the choice:-...\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
			printf("Enter the number of student:-...\n");
		    scanf("%d",&no);
			for(i=0;i<no;i++)
			{
				printf("Enter the serial no.\n");
				scanf("%d",&sn);
				printf("Enter the name of students.");
				scanf("%s",&nam);
				printf("Enter the name of branch...");
				scanf("%s",&branch);
				printf("Enter the USN...");
				scanf("%d",&usn);
				create(sn,nam,branch,usn);
			}
			break;
			case 2:
				display();
				break;
			case 3:
				printf("Enter the serial no.");
				scanf("%d",&sn);
				printf("Enter the name of students.");
				scanf("%s",nam);
				printf("Enter the name of branch...");
				scanf("%s",&branch);
				printf("Enter the USN...");
				scanf("%d",&usn);
				ins_beg(sn,nam,branch,usn);
				break;
			case 4:
			    printf("Enter the serial no.");
				scanf("%d",&sn);
				printf("Enter the name of students.");
				scanf("%s",nam);
				printf("Enter the name of branch...");
				scanf("%s",&branch);
				printf("Enter the USN...");
				scanf("%d",&usn);
				ins_end(sn,nam,branch,usn);
				break;
			case 5:
			    del_beg();
				break;
			case 6:
			    del_end();
				break;
			case 7:
				exit(0);
		    default : 
			    printf("\nInvalid option...\n");		
			    break;			
		}
	}
}
