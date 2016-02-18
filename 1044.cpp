#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
string low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string e2m(string num)
{
	stringstream buf ;
	buf << num;
	int val;
	buf >> val;
	string res = "";
	int h = val / 13;
	res += high[h];
	int l = val %13;
	//cout << 
	if(h == 0 )
		res = res + low[l];
	else if(h != 0&& l != 0)
		res = res + ' ' + low[l];
	return res;
}

string m2e(string num)
{
	int flag = true;
	int val = 0;
	if(num.length() == 4) return "0";
	else if(num.length() == 3) { 
		for(int i = 0; i < 13; i++)
			if(num.compare(high[i]) == 0)
			{ val += i*13; flag = false; break;}
		if(flag)
		{
			for(int i = 0; i < 13; i++)
			if(num.compare(low[i]) == 0)
				{ val += i; break; }
		}
	}
	else if(num.length() == 7) {
		string tmp = num.substr(0,3);
		for(int i = 0; i < 13; i++)
			if(tmp.compare(high[i] )== 0)
			{val += i*13; break; }
		tmp = num.substr(4, 3);
		for(int i = 0; i < 13; i++)
			if(tmp.compare(low[i] )== 0)
			{ val += i; break;}
	}
	stringstream buf;
	buf << val;
	string res = buf.str();
	return res;

}
void trans(string num)
{
	auto it = num.begin();
	string res;
	if(*it>='0' && *it<='9')
		res = e2m(num);
	else
		res = m2e(num);
	cout << res << endl;
}

int main()
{
	vector<string> vec;
	int n;
	//scanf("%d", &n);
	string buf1;
	stringstream buf0;
	getline(cin, buf1);
	buf0 << buf1;
	buf0 >> n;
	for(int i = 0; i < n; i++)
	{
		string tmp;
		getline(cin, tmp);
		vec.push_back(tmp);
	}
	for(int i = 0; i < n; i++) {
		string buf = vec.at(i);
		trans(buf);
	}
	return 0;

}
