#include<stdio.h>

int main(void)
{
	int all[100],res[100],r,i,j,mid,k,temp;
	
	scanf("%d",&r);
	for(i=0;i<r;i++)
		scanf("%d",&all[i]);			/*�������� */
	/******���ҡ��ؼ�����*******/
	for(i = 0; i<r;i++)			/*�ҵ��뷨�ǣ���ÿһ������һֱ�㵽1���ѹ����е�ÿһ��������ʣ�µ��������Ƚ�
									�����ͬ�Ļ��ͰѸ�����ֵΪ 0*/
	{
		if(all[i] != 0)
		{
			mid = all[i];
			while(mid != 1)
			{
				if(mid%2 ==0)
					mid /= 2;
				else
			 		mid = 3*mid +1;
	 			for(j = 0;j < r;j++)
	 				if(mid == all[j])
	 					all[j] = 0;
			}
		}	
	} 
	/*���������ܱ����ǵ������Ѿ������0��������ֻҪ��all�����еķ�0����ֵ��res����*/
	for(i = 0,j = 0;i<r;i++)
	{
		if(all[i] != 0)
		{
			res[j] = all[i];
			j++;
		}
	}
	/*��res��������*/ 
	for(i=0;i<j;i++)
		for(k=i+1;k<j;k++)					/*ע��ѭ����������*/
			if(res[i]<res[k])
			{
				temp=res[i];
				res[i]=res[k];
				res[k]=temp;
			} 
				
	
	/*�������res����*/
	for(i = 0;i<j;i++)
	{
		printf("%d",res[i]);
		if(i != j-1)
			printf(" ");
		else
			printf("\n");
	} 
}
