#include<stdio.h>
#include<string.h>

int main(void)
{
	char a[1001];
	int num[10]={0,0,0,0,0,0,0,0,0,0};
	int i=0,temp;
	
	gets(a);
	while(a[i] != '\0') {
		temp = a[i] - '0';
		num[temp]++;
		i++;
	}
	for(i=0;i<10;i++)
		if(num[i]!=0)
			printf("%d:%d\n",i,num[i]);	
}
