#include<stdio.h>

int main()
{
	int n,i;
	int j[3] = {0,0,0}, y[3] = {0,0,0},draw = 0;
	char jia,yi;
	
	scanf("%d",&n);
	getchar();
	for(i = 1; i <= n; i++)
	{
		scanf("%c", &jia);
		getchar();
		scanf("%c", &yi);
		getchar();
		if(jia == yi)
			draw++;
		if(jia == 'B'&&yi == 'C')
			j[0]++;
		if(jia == 'C'&&yi=='J')
			j[1]++;
		if(jia == 'J'&&yi == 'B')
			j[2]++;
		if(yi == 'B'&&jia == 'C')
			y[0]++;
		if(yi == 'C'&&jia=='J')
			y[1]++;
		if(yi == 'J'&&jia == 'B')
			y[2]++;
	}
	printf("%d %d %d\n",j[0]+j[1]+j[2],draw,n-j[0]-j[1]-j[2]-draw);
	printf("%d %d %d\n",y[0]+y[1]+y[2],draw,n-y[0]-y[1]-y[2]-draw);
	int max1 = j[0],max2 = y[0];
	int flag1 = 0,flag2=0;
	for(i=1;i<3;++i)
		if(max1<j[i]){
			max1 = j[i];
			flag1=i;
		}
		
	for(i=1;i<3;++i)
		if(max2<y[i]){
			max2 = y[i];
			flag2=i;
		}
	if(flag1==0)
		printf("B ");
	if(flag1==1)
		printf("C ");
	if(flag1==2)
		printf("J ");
	if(flag2==0)
		printf("B\n");
	if(flag2==1)
		printf("C\n");
	if(flag2==2)
		printf("J\n");
	
	return 0;
}
