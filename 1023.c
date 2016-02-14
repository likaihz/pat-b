//组个最小数

#include<stdio.h>


int main()
{
	int a[10];
	int i,j,n;
	
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	i=1;
	while(a[i] == 0)
		i++;
	printf("%d",i);
	a[i]--;
	for(i=0;i<=9;i++)
		for(j=1;j<=a[i];j++)
			printf("%d",i);
	printf("\n");
} 
