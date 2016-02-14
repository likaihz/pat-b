#include<stdio.h>

int main()
{
	int n,i;
	char ch;
	scanf("%d %c",&n,&ch);
	for(i=1; 2*i*i-1<=n; i++)
	{
		if(2*i*i-1==n)
		{
			i++;
			break;
		}
		else continue;
	}
	i--;
	int j;
	for(j = i; j>=1; j--)
	{
		int k;
		for(k = 0; k<i-j; k++)
			printf(" ");
		for(k=0; k<2*j-1; k++)
			printf("%c",ch);
		printf("\n");
	}
	for(j=2;j<=i;j++)
	{
		int k;
		for(k = 0; k<i-j; k++)
			printf(" ");
		for(k=0; k<2*j-1; k++)
			printf("%c",ch);
		printf("\n");
	}
	j = n - 2*i*i+1;
	printf("%d\n",j);
}
