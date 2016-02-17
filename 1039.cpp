#include <iostream>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
/*	map<char, int> given, wanted;
	string str_given, str_wanted;
	getline(cin , str_given);
	getline(cin , str_wanted);
	int cnt = 0, res;
	bool enough = true;
	for(auto it = str_wanted.begin(); it != str_wanted.end(); it++)
		if(wanted.find(*it) != wanted.end()) wanted[*it] ++;
		else wanted[*it] = 1;
	for(auto it = str_given.begin(); it != str_given.end(); it++)
		if(given.find(*it) != given.end()) given[*it] ++;
		else given[*it] = 1;
	for(auto it = wanted.begin(); it != wanted.end(); it++)
	{
		int tmp = given.find(it->first) -> second;
		enough = (it -> second <= tmp)?true:false;

		if(!enough && it -> second > tmp)
			cnt += (it -> second - tmp);
	}

	if(enough) {
		res = str_given.length() - str_wanted.length();
		cout << "Yes " << res << endl;
	}
	else {
		res = cnt;
		cout << "No " << res << endl;
	}
	return 0;*/
	
	bool enough = true;
	int cnt_g = 0, cnt_w = 0;
	int lack = 0;
	char given[62] = {0}, wanted[62] = {0};
	char c;
	while((c = getchar()) != '\n')
	{
		int idx;
		if(c >= '0' && c <= '9') idx = c - '0';
		else if(c >= 'a' && c <= 'z') idx = c - 'a' + 10;
		else if(c >= 'A' && c <= 'Z') idx = c - 'A' + 36;
		given[idx]++;
	}
	while((c = getchar()) != '\n')
	{
		int idx;
		if(c >= '0' && c <= '9') idx = c - '0';
		else if(c >= 'a' && c <= 'z') idx = c - 'a' + 10;
		else if(c >= 'A' && c <= 'Z') idx = c - 'A' + 36;
		wanted[idx]++;
	}
	for(int i = 0; i < 62; i++)
	{
		cnt_g += given[i]; cnt_w += wanted[i];
		if(enough)
			enough = (given[i] >= wanted[i])?true:false;
		if(!enough && given[i] < wanted[i])
			lack += wanted[i] - given[i];
	}
	if(enough)
		cout << "Yes " << cnt_g - cnt_w << endl;
	else
		cout << "No " << lack << endl;

	return 0;

}
