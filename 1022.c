#include<stdio.h>

void p(int,int);
int main()
{
	int a,b,d;
	scanf("%d %d %d",&a,&b,&d);
	int c=a+b;
	p(c,d);
	printf("\n");
	return 0;
} 

void p(int c,int d)
{
	int re=c/d;
	if(re!=0)
		p(c/d,d);
	printf("%d",c%d);
		
}
