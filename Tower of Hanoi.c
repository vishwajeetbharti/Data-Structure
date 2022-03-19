  #include<stdio.h>
Tower(int k, char frompeg,char topeg, char midpeg)
{
	if(k==1)
	{
		printf("Move the disk 1 from peg %c to peg %c",frompeg,topeg);
		return; 
	}
	Tower(k-1,frompeg,midpeg,topeg);
	printf("\nMove disk %d from peg %c to peg %c\n", k, frompeg, topeg);
	Tower(k-1,midpeg,topeg,frompeg);
}
void main()
{
	int a;
	printf("Enter the number of disk...\n");
	scanf("%d",&a);
	printf("The moves involved in the Tower of Hanoi are :\n");
	Tower(a,'A','C','B');
}
