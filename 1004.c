/*����n��ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�

�����ʽ��ÿ�������������1��������������ʽΪ

  ��1�У�������n
  ��2�У���1��ѧ�������� ѧ�� �ɼ�
  ��3�У���2��ѧ�������� ѧ�� �ɼ�
  ... ... ...
  ��n+1�У���n��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
�����ʽ����ÿ�������������2�У���1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ��ַ�������1�ո�

����������
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
���������
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
