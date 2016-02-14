#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[100],b[100]="",c[100];
	int i,k=0;
	
	a[0]=' ';
	gets(a+1);
	i=strlen(a);
	for(i=i-1;i>=0;i--)
		if(a[i]==' ') 
		{
			strcat(b,a+i);
			a[i]='\0';
		}
	puts(b+1);
}