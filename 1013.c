#include<stdio.h>
#include<math.h>

int main(void) 
{
	int m,n;
	int is,temp=1,i,num=0;
	int isprime(int x);
	
	scanf("%d%d",&m,&n);
	while(num<n)
	{
		temp++;
		if(isprime(temp))
		{
			num++;
			if(num>=m)
			{
				printf("%d",temp);
				if((num-m+1)%10==0)
					printf("\n");
				else if(num != n)
					printf(" ");
			}
		}
		
	}
	return 0; 
	
}

int isprime(int x)
{
	int i,n;
	if(x==1)
		return 0;
	else if(x==2);
	else
		for(i=2; i<=sqrt(x); i++)
			if(x%i == 0)
				return 0;
	return 1;
}
