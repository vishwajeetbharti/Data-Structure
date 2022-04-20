#include<stdio.h>
#include<stdlib.h>
int a[20][20],q[20],visited[20],reach[10],n,i,j,f=0,r=-1,count=0;
void BFS(int v)
{
	for(i=1;i<=n;i++)
	{
		if(a[v][i]&&!visited[i])
		q[++r]=i;
	}
	if(f<=r)
	{
		visited[q[f]]=1;
		BFS(q[f++]);
	}
}
void DFS(v)
{
	int i;
	reach[v]=1;
	for(i=1;i<=n;i++)
	{
		if(a[v][i]&&!reach[i])
		{
			printf("\n%d->%d",v,i);
			count++;
			DFS(i);
		}
	}
}
void main()
{
	int v,choice;
	printf("Enter the vertices number...\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		q[i]=0;
		visited[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		reach[i]=0;
	}
	printf("Enter the matrix form...\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	while(1)
	{
	
	printf("1. BFS.\n2. DFS.\n3. Exit.\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter the starting vertex:\n");
			scanf("%d",&v);
			BFS(v);
			if((v<1)||(v>n))
			{
				printf("\n BFS is not possible.\n");
			}
			else
			{
				printf("\n The nodes which are reachable from %d:\n",v);
				for(i=1;i<=n;i++)
				{
					if(visited[i])
					printf("%d\t",i);
				}
			}
		case 2:
			DFS(1);
			if(count==n-1)
			printf("\nGraph is connected.\n");
			else
			printf("\nGraph is not connected.\n");
			break;
		case 3:
			exit(0);
	}
}
}
