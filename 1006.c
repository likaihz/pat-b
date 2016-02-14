#include<stdio.h>
#include<string.h>


int main(void)
{
	int n,bai=0,shi=0,ge=0,i;
	char res[30];
	scanf("%d",&n);
	bai = n/100;
	shi = n/10%10;
	ge = n%10;
	for(i=0;i < bai; i++)
		res[i] = 'B';
	for(; i < bai+shi; i++)
		res[i] = 'S';
	for(; i<bai+shi+ge;i++)
		res[i] = i-bai-shi +1+'0';
	res[i+1] = '\0';
	puts(res);
}
