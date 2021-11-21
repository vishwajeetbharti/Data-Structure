#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();
int a[10],top=-1,choice;
void main(){

    while (1)
    {
        printf("Choose option for Operation\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: push();
        break;
        case 2: pop();
        break;
        case 3: display();
        break;
        case 4: exit(0);
        break;
        default:
        printf("you have entered wrong choice\n");
            break;
        }
    }
    

}
void push(){
    if(top == 9){
        printf("Stack is full");
    }
    else {
  int temp;
    printf("enter number which you want push\n");
    scanf("%d",&temp);
    a[++top] = temp;
    printf("%d is pushed into stack\n",temp);
    }
  
}
void pop(){
    if(top == -1){
        printf("Stack is already empty\n");
    }
    else
    {
        int temp;
        temp = a[top];
        a[top] = '\0';
        printf("%d is the deleted number\n",temp);
        top--;
    }
    

}
void display(){

    printf("The stcak contains the following values - \n");
    for(int i=0;i<=10;i++){
        printf("%d \n",a[i]);
    }
}
