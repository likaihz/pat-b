/*1016. ����A+B (15)

������A�ġ�DA��Ϊ1λ���������֡�����Ϊ��A������DA��ɵ�������PA�����磺����A = 3862767��DA = 6����A�ġ�6���֡�PA��66����ΪA����2��6��

�ָ���A��DA��B��DB�����д�������PA + PB��

�����ʽ��

������һ�������θ���A��DA��B��DB���м��Կո�ָ�������0 < A, B < 1010��

�����ʽ��

��һ�������PA + PB��ֵ��

��������1��
3862767 6 13530293 3
�������1��
399
��������2��
3862767 1 13530293 8
�������2��
0*/

#include<stdio.h>

int findp(int a,int d);
int main(void)
{
	int a,b,d1,d2,p1=0,p2=0;
	
	scanf("%d%d%d%d",&a,&d1,&b,&d2);
	p1 = findp(a,d1);
	p2 = findp(b,d2);
	printf("%d\n",p1+p2);
}

int findp(int a, int d)
{
	int p=0,r=0,temp,i;
	while(a!=0)
	{
		temp = a%10;
		if(temp==d)
			r++;
		a = a/10;
	}
	for(i = 1;i<=r;i++)
		p = p*10+d;
	return p;
}
