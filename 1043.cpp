#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
	int cnt[6] = {0};
	char c;
	char out[7] = "PATest";
	while((c = getchar()) != '\n')
		switch(c)
		{
			case 'P': cnt[0]++; break;
			case 'A': cnt[1]++; break;
			case 'T': cnt[2]++; break;
			case 'e': cnt[3]++; break;
			case 's': cnt[4]++; break;
			case 't': cnt[5]++; break;
			default: break;
		}
	int flag = 1;
	while(flag)
	{
		flag = 0;
		for(int i = 0; i < 6 ; i++)
			if(cnt[i] != 0) {
				cout << out[i];
				cnt[i]--;
				flag = 1;
			}
	}
	cout <<endl;
	return 0;
}
