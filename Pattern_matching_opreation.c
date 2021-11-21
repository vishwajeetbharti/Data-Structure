#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],pat[100],rep[100],ans[100];
	int k,c=0,m=0,i=0,j=0,flag=0;
	printf("Enter the main string:-\n");
	gets(str);
	printf("Enter the pattern string:-\n");
	gets(pat);
	printf("Enter the replace string:-\n");
	gets(rep);
	while(str[c]!='\0')
	{
		if(str[m]==pat[i])
		{
			i++;
			m++;
			flag=1;
			if(pat[i]=='\0')
			{
				for(k=0;rep[k]!='\0';k++,j++)
				ans[j]=rep[k];
				i=0;
				c=m;
			}
			
		}
		else
		{
			ans[j]=str[c];
			j++;
			c++;
			m=c;
			i=0;
		}
	}
	if(flag==0)
	{
		printf("Pattern is not found!!!\n");
	}
	else
	{
		ans[j]='\0';
		printf("The resultent string is:-\n%s",ans);
	}
	return 0;
}
