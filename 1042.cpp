#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int cnt[26] = {0};
	char c;
	int idx, rec = 0;
	while((c = getchar()) != '\n')
	{
		if(c >= 'A' && c <= 'Z')
			c = 'a' +(c - 'A');
		if(c >= 'a' && c <= 'z')
			cnt[c-'a'] ++;
	}
	for(int i = 0; i < 26; i++)
		if(cnt[i] > rec) { idx = i; rec = cnt[i];}
	c = 'a' + idx;
	cout << c << ' ' << rec << endl;
}
