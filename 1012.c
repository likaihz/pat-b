#include <stdio.h>

int main(void)
{
	int a[5]={0,0,0,0,0};
	int in[1000];
	int n,i,flag=1,num=0,ff=0;
	
	scanf("%d",&n);
	for(i = 0;i<n;i++)
		scanf("%d",&in[i]);
	for(i = 0;i<n;i++)
	{
		if(in[i]%5==0&&in[i]%2==0)
			a[0] += in[i];
		if(in[i]%5==1)
		{
			a[1] = a[1]+in[i]*flag;
			flag = 0-flag;
			ff=1;
		}
		if(in[i]%5==2)
			a[2]++;
		if(in[i]%5==3)
		{
			a[3]+=in[i];
			num++;
		}
		if(in[i]%5==4)
			if(in[i]>a[4])
				a[4]=in[i];
	}
				
	for(i=0;i<5;i++)
	{
		if(i==1&&ff!=0)
			printf("%d",a[i]); 
		else if(a[i]==0)
			printf("N");
		else if(i==3)
			printf("%.1f",(float)a[3]/num);
		else
			printf("%d",a[i]);
		if(i<=3)
			printf(" ");
		if(i==4)
			printf("\n");	
	} 
}
