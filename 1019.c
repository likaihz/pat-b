#include<stdio.h>

int main()
{
	int n,i,j,k,re=0;
	int num[4],b[4];
	
	scanf("%d",&n);
	k = n;
	re = n;
	for(i=0;i<4;++i)		//将各位数保存到一个数组中 
	{
		num[i] = k%10;
		k /= 10;
	}
	
	if(num[0]==num[1]&&num[1]==num[2]&&num[2]==num[3])
	{
		printf("%d - %d = 0000\n",n,n);
		return 0;
	} 
	do
	{
		for(i=0;i<4;++i)
		{		//将各位数保存到一个数组中 
			num[i] = re%10;
			re /= 10;
		}
		
		for(i=0;i<4;++i)				//对数组中的数从小到大排序 
			for(j=i+1;j<4;++j)
			{
				int temp;
				if(num[i]>num[j])
				{
					temp = num[i];
					num[i]=num[j];
					num[j]=temp;
				}
			}
		
		int p,q;
		p = num[0]+num[1]*10+num[2]*100+num[3]*1000;
		q = num[3]+num[2]*10+num[1]*100+num[0]*1000;
		re = p-q;
		printf("%04d - %04d = %04d\n",p,q,re);
	}while(re != 6174);

	
	return 0;
}
