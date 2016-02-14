#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	int max = 0, best_school;
	cin >> n;
	map<int, int> record;
	for(int i = 0; i < n; i++)
	{
		int no, score;
		cin >> no >> score;
		auto it = record.find(no);
		if(it == record.end())
			record[no] = score;
		else
			record[no] += score;
	}
	for(auto it = record.begin(); it != record.end(); it++)
		if(it -> second > max) {
			max = it -> second;
			best_school = it -> first;
		}
	cout << best_school << ' ' << max << endl;
	return 0;
}
