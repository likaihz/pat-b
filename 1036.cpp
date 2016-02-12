#include <iostream>

using namespace std;

int main()
{
	int n;
	char c;
	cin >> n;
	cin >> c;
	int cnt = n/2 + n%2;
	for(int i = 0; i<cnt; i++)
	{
		if(i == 0 || i == cnt-1)
		{
			for(int j = 0; j < n; j++)
				cout << c;
			cout << endl;
		}
		else
		{
			cout << c;
			for(int j = 0; j<n-2; j++)
				cout << ' ';
			cout << c <<endl;
		}
	}
}
