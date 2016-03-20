#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	vector<string> emo[3];
	char c;
	int line = 0;
	string buf("");
	while((c = getchar())!= '\n' || line != 2)
	{
		if(c == '[' || c == ' ') continue;
		else if(c == ']') { emo[line].push_back(buf); buf = "";}
		else if(c == '\n') line++;
		else  buf+= c;
	}
	int n;
	cin >>n;
	int rqst[n][5];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 5; j++)
			cin >> rqst[i][j];
	for(int i = 0; i < n; i++)
	{
		buf = "";
		int err = 0;
		for(int j = 0; j < 5; j++)
			if(rqst[i][j] > emo[abs(abs(j-2)-2)].size()||rqst[i][j] <= 0)
			{ err = 1; break; }
		if(err)
			cout << "Are you kidding me? @\\/@" << endl;
		else
		{
			for(int j = 0; j < 5; j++)
			{
				if(j == 1) buf += '(';
				else if(j == 4) buf += ')';
				buf += emo[abs(abs(j-2)-2)].at(rqst[i][j]-1);
			}

		cout << buf << endl;}
	}
	return 0;
}

//32行：还要考虑输入的请求小于等于零的情况。。是坑
