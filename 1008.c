#include<stdio.h>


int main(void)
{
	int i,j,n,m,temp;
	int a[100];
	
	scanf("%d%d",&n,&m);
	for(i = 0;i<n;i++)
		scanf("%d",&a[i]);
	for(j=1;j<=m;j++)
	{
		temp = a[0];
		for(i = 0;i<n-1;i++)
			temp^=a[i+1]^=temp^=a[i+1];
		a[0] = temp;
	}
	for(i = 0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i!=n-1)
			printf(" ");
		else
			printf("\n");
	}
}
