#include<stdio.h>
#include<string.h>
#define MAX 5

int F(char ch)
{
	switch(ch)
	{
		case'+':
		case'-':return 2;
		case'*':
		case'/':return 4;
		case'^':return 5;
		case'(':return 0;
		case'#':return -1;
		default: return 8;
	}
}

int G(char ch)
{
	switch(ch)
	{
		case'+':
	    case'-':return 1;
	    case'*':
	    case'/':return 3;
	    case'^':return 6;
	    case'(':return 9;
	    case')':return 0;
	    default: return 7;
	}
}

void in2pos(char infix[],char postfix[])
{
	int top=-1,i,j=0;
	char symbol,s[100];
	
	s[++top]='#';
	
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		while(F(s[top])>G(symbol))
		{
			postfix[j++]=s[top--];
		}
		if(F(s[top])!=G(symbol))
		s[++top]=symbol;
		else
		top--;
	}
	while(s[top]!='#')
	{
		postfix[j++]=s[top--];
	}
	postfix[j]='\0';
}
int main()
{
	char infix[100],postfix[100];
	printf("\nEnter the infix statement..\n");
	scanf("%s",infix);
	in2pos(infix,postfix);
	printf("\nThe postfix expession for %s->\t%s",infix,postfix);
}
