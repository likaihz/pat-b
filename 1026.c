#include<stdio.h>

int main()
{
	int c1,c2;
	scanf("%d%d",&c1,&c2);
	int sec = (c2-c1)/100 + (c2-c1)%100/10/5;
	int h = sec / 3600;
	sec %= 3600;
	int m = sec / 60;
	sec %= 60;
	printf("%02d:%02d:%02d\n",h,m,sec);
}
