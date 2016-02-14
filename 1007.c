#include<stdio.h>


int prime(int x);
int main(void)
{
	int N,count=0,i;
	
	scanf("%d",&N);
	for(i = 2; i<= N-2;i++)
		if(prime(i)==1&&prime(i+2)==1)
			count++;
	printf("%d\n",count);
}

int prime(int x)			//判断是否为素数,返回值为1则x是素数，返回0则不是素数。 
{
	int i;
	for(i = 2; i<=sqrt(x);i++)				//要用开根号，，特么要是用一半的话，PAT上竟然会超时。。。 
		if(x%i==0)
			break;
	if(i>sqrt(x) && x!=1)
		return 1;
	else
		return 0;
}
