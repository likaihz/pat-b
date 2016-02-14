#include<stdio.h>
#include<string.h>

int main(void)
{
	int n,i,bai,shi,ge;
	scanf("%d",&n);
	bai = n/100;
	shi = n/10%10;
	ge = n%10;
	for(i = 1;i <= bai; i++)
		printf("B");
	for(i = 1;i <= shi; i++)
		printf("S");
	for(i = 1; i<= ge;i++)
		printf("%d",i);
	printf("\n");

}
