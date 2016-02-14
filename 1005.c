#include<stdio.h>

int main(void)
{
	int all[100],res[100],r,i,j,mid,k,temp;
	
	scanf("%d",&r);
	for(i=0;i<r;i++)
		scanf("%d",&all[i]);			/*输入数据 */
	/******查找“关键数“*******/
	for(i = 0; i<r;i++)			/*我的想法是，把每一个数都一直算到1，把过程中的每一个数都和剩下的所有数比较
									如果相同的话就把该数赋值为 0*/
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
	/*现在所有能被覆盖的数都已经变成了0，接下来只要把all数组中的非0数赋值给res数组*/
	for(i = 0,j = 0;i<r;i++)
	{
		if(all[i] != 0)
		{
			res[j] = all[i];
			j++;
		}
	}
	/*给res数组排序*/ 
	for(i=0;i<j;i++)
		for(k=i+1;k<j;k++)					/*注意循环的上下限*/
			if(res[i]<res[k])
			{
				temp=res[i];
				res[i]=res[k];
				res[k]=temp;
			} 
				
	
	/*下面输出res数组*/
	for(i = 0;i<j;i++)
	{
		printf("%d",res[i]);
		if(i != j-1)
			printf(" ");
		else
			printf("\n");
	} 
}
