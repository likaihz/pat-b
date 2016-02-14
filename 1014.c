#include<stdio.h>
#include<string.h>

int main()
{
	char s[4][61],day[4];
	int i,len[4],flag=0,hour,min;
	
	for(i=0;i<4;++i)
	{
		scanf("%s",s[i]);
		len[i] = strlen(s[i]);
	}
	
	for(i=0;i<len[0]&&i<len[1];++i)		//处理前两个字符串 ，得出星期几和小时 
	{
		if(s[0][i]==s[1][i]&&s[0][i]>='A'&&s[0][i]<='G')
		{
			switch(s[0][i])
			{
				case 'A': strcpy(day,"MON"); break;
				case 'B': strcpy(day,"TUE"); break;
				case 'C': strcpy(day,"WED"); break;
				case 'D': strcpy(day,"THU"); break;
				case 'E': strcpy(day,"FRI"); break;
				case 'F': strcpy(day,"SAT"); break;
				case 'G': strcpy(day,"SUN"); break;
			} 
			int j;
			for(j=i+1;j<len[0]&&j<len[1];++j)
			{
				if(s[0][j]==s[1][j]&&(s[0][j]>='0'&&s[0][j]<='9'||s[0][j]>='A'&&s[0][j]<='N'))
				{
					if(s[0][j]>='0'&&s[0][j]<='9')
						hour = s[0][j]-'0';
					if(s[0][j]>='A'&&s[0][j]<='N')
						hour = 10+(s[0][j]-'A');
					break;	
				}
				
			}
			break;
		}
	}
	
	for(i=0;i<len[2]&&i<len[3];++i)		//处理后两个字符串 ，得出分钟 
	{
		if(s[2][i]==s[3][i]&&(s[2][i]>='a'&&s[2][i]<='z'||s[2][i]>='A'&&s[2][i]<='Z'))
		{
			min = i; 
			break;
		}
	} 
	printf("%s %02d:%02d\n",day,hour,min);
} 
