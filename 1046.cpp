#include <iostream>

using namespace std;

int main()
{
	int n;
	int cnt1 = 0, cnt2 = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int hand1, hand2;
		int mouth1, mouth2;
		cin >> mouth1 >> hand1 >> mouth2 >>hand2;
		if(mouth1 + mouth2  == hand1 && mouth1 + mouth2 != hand2) cnt2++;
		else if(mouth1 + mouth2  == hand2 && mouth1 + mouth2 != hand1) cnt1++;
	}
	cout << cnt1 << ' ' << cnt2 << endl;
	return 0;
}
