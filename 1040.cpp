#include <iostream>
#include <map>

using namespace std;

int main()
{
	char c;
	int idx = 0;
	int cnt_p = 0, cnt_PA = 0;
	long long  res = 0;
	while((c = getchar()) != 'P') ;
	while(c != '\n') {
		switch(c) {
		case 'P': cnt_p ++; break;
		case 'A': cnt_PA += cnt_p; break;
		case 'T': res += cnt_PA; break;
		}
		idx++;
		c = getchar();
	}
	res %= 1000000007;
	cout << res <<endl;
}

/*既然数据很大，那嵌套循环肯定超时，所以只能循环一次。*/

