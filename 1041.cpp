#include <iostream>
#include <map>
#include <string>

using namespace std;

class stu{
public:
	string id;
	int seat2;
	stu() {}
	stu(string _id, int _seat2): id(_id), seat2(_seat2) {};
};

int main()
{
	map<int, stu> m0;
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i++){
		string buf;
		int t1, t2;
		cin >> buf;
		cin >> t1;
		cin >> t2;
		stu tmp(buf, t2);
		m0[t1] = tmp;
	}
	cin >> m;
	for(int i = 0; i<m; i++){
		int s;
		stu buf;
		cin >> s;
		buf = m0[s];
		cout << buf.id << ' ' <<buf.seat2 <<endl;

	}
}
