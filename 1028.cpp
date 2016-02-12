#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class person{
public:
	string name;
	int year;
	int month;
	int day;
	person() {};
	person(string & _name, int _year, int _month, int _day): name(_name), year(_year), month(_month), day(_day) {};

	bool valid() 
	{
		if(year < 1814 || year > 2014) return false;
		else if(year == 1814 && month < 9 ) return false;
		else if(year == 1814 && month == 9 && day < 6) return false;
		else if(year == 2014 && month > 9) return false;
		else if(year == 2014 && month == 9 && day >6) return false;
		return true;
	}
	bool older_than(person & p)
	{
		if(year < p.year) return true;
		else if(year == p.year && month < p.month) return true;
		else if(year == p.year && month == p.month && day < p.day) return true;

		return false;
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	person old, young;
	bool valid = false;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		string name_buf, date_buf;
		int year, month, day;
		cin >> name_buf >> date_buf;
		string buf = date_buf.substr(0, 4);
		year = atoi(buf.c_str());
		buf = date_buf.substr(5, 2);
		month = atoi(buf.c_str());
		buf = date_buf.substr(8, 2);
		day = atoi(buf.c_str());
		person p_buf(name_buf, year, month, day);
		if(p_buf.valid()) cnt++;
		else continue;
		if(!valid && p_buf.valid())
		{
			old = p_buf;
			young = p_buf;
			valid = true;
		}
		else
		{
			if(p_buf.older_than(old)) old = p_buf;
			if(young.older_than(p_buf)) young = p_buf;
		}

	}
	if (cnt != 0)
		cout << cnt << ' ' << old.name << ' ' << young.name << endl;
	else cout << '0' << endl;
	return 0;
}
