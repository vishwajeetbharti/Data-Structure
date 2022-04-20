#include<stdio.h> 
#include<stdlib.h>
int i,a[20];
int n,val,pos;

void create()
{ 
    printf("Enter the size of the array element.\n");
    scanf("%d", &n);
    printf("Enter the elements for the array.\n");

    for(i=0; i<n; i++)
    {
	    scanf("%d",&a[i]);
    }
}

void display()
{
	 printf("The array elements are:\n");
	 for(i=0; i<n; i++)
	 {
	 	 printf("%d\n",a[i]);
	 }
}

void insert()
  {
  	
  	    printf("Enter the position of the new elements.\n");
  	  
  	    scanf("%d", &pos);
  	   
  	    printf("Enter the elements to be inserted.\n");
  	    scanf("%d", &val);
  	    for(i=n-1; i>=pos-1; i--)
		 {
  	   	    a[i+1] = a[i];
		 }  
		  a[pos-1]= val;
		  n=n+1;
  }

void deleted() 
{
	
      	
      	 printf("Enter the position of the elements to be deleted.\n");
      	 scanf("%d", &pos);
      	 val= a[pos-1];
      	 for(i=pos-1; i<n-1; i++)
      	 {
      	 	a[i] =a[i+1];
		 }
      	 n=n-1;
      	 printf("The deleted elements is %d",val);
}
      	  
int main()
      	  {
      	  	int choice;
      	  	for(;;)
      	  	{
      	  		 printf("\n\n----MENU----\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.EXIT\n-----------\nENTER YOUR CHOICE:\n");
      	  		 scanf("%d", &choice);
      	  		 switch(choice)
					 {
      	  		 	case 1: create();
      	  		 	break;
      	  		 	case 2: display();
      	  		 	break;
      	  		 	case 3:insert();
      	  		 	break;
      	  		 	case 4: deleted();
      	  		 	break;
      	  		 	case 5 : exit(0);
      	  		 	break;
      	  		 	default:
      	  		    printf("Enter wroung value...");
      	  		 	 	
					 }
      	  		 
      	  		 
				}
			}
