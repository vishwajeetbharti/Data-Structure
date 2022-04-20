#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
double cal(double op1,char op,double op2)
{
	switch(op)
	{
		case'+': return(op1+op2);
		case'-': return(op1-op2);
		case'*': return(op1*op2);
		case'/': return(op1/op2);
		case'^': return(pow(op1,op2));
	}
}
void main()
{
	double s[50],res,op1,op2;
	int top=-1,i;
	char pos[50],sym;
	
	printf("Enter the postfix expression.\n");
	scanf("%s",pos);
	for(i=0;i<strlen(pos);i++)
	{
		sym=pos[i];
		if(isdigit(sym))
		{
			s[++top]=sym-'0';
		}
		else
		{
			op2=s[top--];
			op1=s[top--];
			res=cal(op1,sym,op2);
			s[++top]=res;
		}
	}
	res=s[top--];
	printf("\n%s = %f",pos,res);
}
