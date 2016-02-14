#include <stdio.h>
#include <string.h>

int main (void)
{
	char num[1001],q[1001];
	int dvd,r;
	int len,i,temp = 0;
	
	scanf("%s %d",num,&dvd);
	len = strlen(num);
	for(i=0; i<len; i++)
	{
		int digi;
		digi = (int)num[i]-48 + 10*temp;
		q[i] = (char)(digi / dvd+48);
		temp = digi % dvd;
	}
	if(q[0]=='0'&&(q[1]>'0'&&q[1]<='9'))
		printf("%s %d",q+1,temp);
	else
		printf("%s %d",q,temp);
	
	return 0; 
}
