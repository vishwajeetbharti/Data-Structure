#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
struct stu
{
//	long long int ph;
	int sem;
	char name[50],usn[20],branch[10];
	struct stu *next;
};
struct stu *head=NULL,*temp=NULL,*tail=NULL,*temp1;
 
void create(int s, char n[20],char u[15],char b[5])
{
    if(head==NULL)
    {
    	head=(struct stu*)malloc(1*sizeof(struct stu));
//    	head->ph=a;
    	head->sem=s;
    	strcpy(head->name,n);
    	strcpy(head->usn,u);
    	strcpy(head->branch,b);
    	head->next=NULL;
    	tail=head;
    	count++;
	}
	else
	{
		temp=(struct stu*)malloc(1*sizeof(struct stu));
//		temp->ph=a;
		temp->sem=s;
		strcpy(temp->name,n);
    	strcpy(temp->usn,u);
    	strcpy(temp->branch,b);
		temp->next=head;
		head=temp;
		count++;
	}
}
void display()
{
	temp1=head;
	if(temp1==NULL)
	{
	    printf("List is empty...");
	}
	else
	{
		printf("The details of student are:-\n");
		while(temp1!=NULL)
		{
			printf("***    ****    ****\n");
			printf("NAME:-%s.\nUSN:-%s.\nBranch:-%s.\n",temp1->name,temp1->usn,temp->branch);
			printf("***    ****    ****\n");
			temp1=temp1->next;
		}
		 printf("\nNo. of nodes=%d\n",count);

	}
	
}
void insert_head(int s,char n[20],char u[10],char b[5])
{
	temp=(struct stu*)malloc(1*sizeof(struct stu));
//	temp->ph=k;
	temp->sem=s;
	strcpy(temp->name,n);
    strcpy(temp->usn,u);
    strcpy(temp->branch,b);
	temp->next=head;
	head=temp;
	count++;
}
void insert_tail(int s,char n[20],char u[10],char b[5])
{
	temp=(struct stu*)malloc(1*sizeof(struct stu));
//	temp->ph=k;
	temp->sem=s;
	strcpy(temp->name,n);
    strcpy(temp->usn,u);
    strcpy(temp->branch,b);
	tail->next=temp;
	temp->next=NULL;
	tail=temp;
	count++;
}
void delete_head()
{
	temp1=head;
	if(temp1==NULL)
	{
		printf("List is already empty...\n");
	}
	else
	{
		head=head->next;
		free(temp1);
		count--;
	}
}
void delete_tail()
{
	temp1=head;
	if(tail==NULL)
	{
    	printf("List is already empty...\n");
	}
	else if(temp1->next==NULL)
	{
		printf("\nthe deleted node is :-\n");
		printf("\nName: %s\nUSN:%s\nBranch: %s\nSem: %d\n",temp1->name,temp1->usn,temp1->branch,temp1->sem);
		head=tail=NULL;
		count--;
	}
	else
	{
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		printf("\nthe deleted node is :-\n");
		printf("\nName: %s\nUSN:%s\nBranch: %s\nSem: %d\n",tail->name,tail->usn,tail->branch,tail->sem);
		free(tail);
		tail=temp1;
		tail->next=NULL;
		count--;
	}
}
void main()
{
    int choice,no,i=0;
//    long long int ph;
    int sem;
    char name[50],usn[20],branch[10];
   
    while(1)
    {
    	printf("***   MENU   ***\n");
            printf("1.Create\n2.Insert from head\n3.Insert from tail\n4.Delete from head\n5.Delete from tail\n6.Display\n7.Exit\n");
            printf("***   ****  ***\n");
    	    printf("\nEnter the choice.\n");
    	    scanf("%d",&choice);
    	switch(choice)
    	{
    		
    		case 1:
			printf("Enter the number of students.\n");
    		scanf("%d",&no);
    		while(i<no)
    		{
    			printf("Enter the Name.\n");
    			scanf("%s",&name);
    			printf("\nEnter the USN.\n");
    			scanf("%s",&usn);
    			printf("\nEnter the Branch.\n");
    			scanf("%s",branch);
    			printf("Enter the Sem.\n");
    			scanf("%d",&sem);
//    			printf("Enter the Phone no. .\n");
//    			scanf("%lld",ph);
    			create(sem,name,usn,branch);
    			i++;
			}
			break;
			case 2: printf("Enter the Name.\n");
    			scanf("%s",&name);
    			printf("\nEnter the USN.\n");
    			scanf("%s",&usn);
    			printf("\nEnter the Branch.\n");
    			scanf("%s",branch);
    			printf("Enter the Sem.\n");
    			scanf("%d",&sem);
//    			printf("Enter the Phone no. .\n");
//    			scanf("%ld",ph);
    			insert_head(sem,name,usn,branch);
    			break;
    		case 3:printf("Enter the Name.\n");
    			scanf("%s",&name);
    			printf("\nEnter the USN.\n");
    			scanf("%s",&usn);
    			printf("\nEnter the Branch.\n");
    			scanf("%s",branch);
    			printf("Enter the Sem.\n");
    			scanf("%d",&sem);
//    			printf("Enter the Phone no. .\n");
//    			scanf("%ld",ph);
				insert_tail(sem,name,usn,branch);
				break;
			case 4:
			delete_head();
			break;
			case 5:
			delete_tail();
			break;
			case 6:
			display();
			break;
			case 7:
			exit(0);
			default : printf("\nInvalid option...\n");		
			break;
		}
	}
}
