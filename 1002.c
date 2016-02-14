/*念数字*/

#include<stdio.h>
#include<string.h>

int sum(char *in);
void read(int sum);

int main(void)
{
	int num;
	char in[101];
	gets(in);
	num = sum(in);
	read(num);
}

int sum(char *in)			//求和函数
{
	int s = 0,i = 0;
	while(*(in+i) != '\0')
	{
		s = s + (*(in + i) - '0');
		i++;
	}
	return s;
}

void read(int num)
{
	int temp;
	int n=0,i,j; 
	int power(int x,int n); 
	
	
	temp = num;
	do
	{
		temp = temp/10;
		n++;
	}while(temp != 0);
	j=n-1;
	for(i=1;i<=n;i++)
	{
		temp=num/power(10,j);
		num%=power(10,j--);
		switch(temp){
			case 0 :printf("ling");break;
			case 1 :printf("yi");break;
			case 2 :printf("er");break;
			case 3 :printf("san");break;
			case 4 :printf("si");break;
			case 5 :printf("wu");break;
			case 6 :printf("liu");break;
			case 7 :printf("qi");break;
			case 8 :printf("ba");break;
			case 9 :printf("jiu");break;
		}
		if(i!=n)
			printf(" ");
		else
			printf("\n");
		
	}
}

int power(int x,int n)
{
	int i,res=1;
	
	for(i=1;i<=n;i++)
		res = res*x;
	return res;
}
