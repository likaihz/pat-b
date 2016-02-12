#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> 	vec;
	int n;
	int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	cin >> n;
	bool res[n];
	for(int i = 0; i < n; i++)
	{
		res[i] = true;
		string buf;
		cin >> buf;
		vec.push_back(buf);
	}
	for(int i = 0; i < n; i++)
	{
		int sum = 0;
		auto it = vec[i].begin();
		char x;
		for(int ii = 0; ii <17; it++, ii++)
		{
			int tmp;
			if(*it > '9' || *it < '0') { res[i] = false; break;}
			tmp = *it - '0';
			sum += tmp*weight[ii];
		}
		if(res[i] == false) continue;
		sum %= 11;
		switch(sum)
		{
			case 0: x = '1'; break;
			case 1: x = '0'; break;
			case 2: x = 'X'; break;
			case 3: x = '9'; break;
			case 4: x = '8'; break;
			case 5: x = '7'; break;
			case 6: x = '6'; break;
			case 7: x = '5'; break;
			case 8: x = '4'; break;
			case 9: x = '3'; break;
			case 10: x = '2'; break;
		}
		if(x != *it) res[i]= false;
	}

	int flag = 0;
	for(int i=0; i<n; i++)
		if(res[i] == false)
		{
			flag++;
			cout << vec[i] << endl;
		}
	if(flag == 0)
		cout << "All passed" <<endl;
	return 0;
}
