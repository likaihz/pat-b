#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10001



int main(int argc,char *argv[])
{
	char i_num;//整数部分
	char f_num[MAX],e_num[MAX];//分别表示小数部分，指数部分
	char str[MAX];
	int i,k,len;
	scanf("%s",str);
	if(str[0]=='-')
		printf("-");
	i_num=str[1];
	k=0;
	for(i=3;str[i]!='E';i++)
	{
		f_num[k]=str[i];
		k++;
	}
	f_num[k]='\0';
	i++;
	strcpy(e_num,&str[i]);
	int e=atoi(&e_num[1]);
    if(e_num[0]=='+')
	{
		len=strlen(f_num);
		if(len==e)
			printf("%c%s\n",i_num,f_num);
		else if(len<e)
		{
			printf("%c%s",i_num,f_num);
			int j;
			for(j=1;j<=e-len;j++)
				printf("0");
			printf("\n");
		}
		else
		{
			printf("%c",i_num);
			int j;
			for(j=0;j<len;j++)
			{
				if(j==e)
					printf(".%c",f_num[j]);
				else
					printf("%c",f_num[j]);
			}
		}
	}
	else
	{
		if(e==0)
			printf("%c.%s\n",i_num,f_num);
		else
		{
			printf("0.");
			int j;
			for(j=1;j<e;j++)
				printf("0");
			printf("%c%s\n",i_num,f_num);
		}
	}

	return 0;
}
