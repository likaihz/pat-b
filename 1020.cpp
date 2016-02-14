#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class MoonCake{
	public:
		float storage;
		float total;
		float price;
		MoonCake(float s, float p): storage(s), total(p) {price = 0; };
};

void Push(vector<MoonCake> &vec, float s, float p)
{
	MoonCake tmp(s, p);
	vec.push_back(tmp);
}

int compare(const void * a, const void * b)
{
	float p1, p2;
	p1 = (*((MoonCake *)a)).price;
	p2 = (*((MoonCake *)b)).price;
	return p1 < p2;
}

int main()
{
	int type, dmd;
	vector<MoonCake> vec;
	scanf("%d%d",&type, &dmd);
	for(int i = 0; i < type; i++)
	{
		float tmp;
		scanf("%f", &tmp);
		Push(vec, tmp, 0);
	}
	for(int i = 0; i < type; i++)
	{
		float tmp;
		scanf("%f", &tmp);
		vec[i].total = tmp;
		vec[i].price = tmp / vec[i].storage;
	}
	qsort(&vec[0], vec.size(),sizeof(MoonCake), compare);
	float rest = dmd, income = 0;
	int i = 0;
	while(rest > 0 && i < type)
	{
		if(rest >= vec[i].storage)
		{
			income += vec[i].total;
			rest -= vec[i].storage;
			i++;
		}
		else
		{
			income += rest * vec[i].price;
			rest = 0;
		}
	}
	
	printf("%.2f\n", income);
}
