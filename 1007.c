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

int prime(int x)			//�ж��Ƿ�Ϊ����,����ֵΪ1��x������������0���������� 
{
	int i;
	for(i = 2; i<=sqrt(x);i++)				//Ҫ�ÿ����ţ�����ôҪ����һ��Ļ���PAT�Ͼ�Ȼ�ᳬʱ������ 
		if(x%i==0)
			break;
	if(i>sqrt(x) && x!=1)
		return 1;
	else
		return 0;
}
