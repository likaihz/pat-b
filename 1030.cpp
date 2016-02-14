#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	unsigned int n,p;
	unsigned int tmp;
	vector<unsigned int> vec;
	scanf("%u%u",&n, &p);
	
	for(int i=0; i < n; i++)
	{
		scanf("%u", &tmp);
		vec.push_back(tmp);
	}
	
}
