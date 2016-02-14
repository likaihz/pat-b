/*读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112
*/


#include<stdio.h>
#include<string.h>

struct stud{
	char name[11];
	char num[11];
	int score;
};

int main(void)
{
	struct stud *p,*max_head,*min_head;
	int i,amount,score;
	char name[10],num[10];
	int size = sizeof(struct stud);
	
	p = (struct stud *)malloc(size);
	max_head = (struct stud *)malloc(size);
	min_head = (struct stud *)malloc(size);
	scanf("%d",&amount);
	for(i = 1;i<=amount;i++)
	{
		scanf("%s%s%d",name,num,&score);
		strcpy(p->name,name);
		strcpy(p->num,num);
		p->score = score;
		if(i==1)
		{
			strcpy(max_head->name,name);
			strcpy(min_head->name,name);
			strcpy(max_head->num,num);
			strcpy(min_head->num,num);
			max_head ->score = min_head ->score = score;
		}
		else
		{
			if(p->score > max_head -> score)
				*max_head = *p;
			if(p->score < min_head->score)
				*min_head = *p;
		} 
	}
	printf("%s %s\n",max_head->name,max_head->num);
	printf("%s %s\n",min_head->name,min_head->num);
}
