/*1016. 部分A+B (15)

正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
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
