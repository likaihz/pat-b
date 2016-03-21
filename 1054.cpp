#include <iostream>
#include <string>
#include <sstream>

using namespace std;

double toNum(string num)
{
	stringstream ss;
	double res;
	ss << num;
	ss >> res;
	return res;
}


bool illegal(string num)
{
	bool point = false;
	double buf = toNum(num);
	if(buf < -1000 || buf > 1000) return true;
	auto it = num.begin();
	if((*it < '0' || *it > '9') && *it != '-') return true;
	if(num.length() == 1 && !(*it >= '0' && *it <= '9')) return true;
	for(it++; it != num.end(); it++)
	{
		if(*it >= '0' && *it <= '9') continue;
		else if(*it =='.' && !point) point = true;
		else return true;
	}
	int ppos = num.find('.');
	if(ppos == string::npos) return false;
	int len = num.length();
	int dec = len - 1 - ppos;
	if(dec > 2) return true;
	return false;
}

int main()
{
	int N, cnt = 0;
	string num;
	double sum = 0.0;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> num;
		if(illegal(num))
			printf("ERROR: %s is not a legal number\n", num.c_str());
		else sum+= toNum(num), cnt++;
	}
	if(cnt == 0) 
		printf("The average of 0 numbers is Undefined\n");
	else if(cnt == 1)
		printf("The average of 1 number is %.2f\n", sum);
	else {
		double avg = sum / cnt;
		printf("The average of %d numbers is %.2f\n", cnt, avg);
	}
	return 0;
}
