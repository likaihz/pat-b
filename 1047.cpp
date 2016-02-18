#include <iostream>
#include <map>
using namespace std;
int main()
{
	int n;
	map<int, int> score;
	scanf("%d", &n);
	int winner, max = 0;
	for(int i = 0; i < n; i++)
	{
		int team, mem, sco;
		scanf("%d-%d%d",&team, &mem, &sco);
		if(score.find(team) == score.end())  score[team] = sco;
		else score[team] += sco;
	}
	for(auto it = score.begin(); it != score.end(); it++)
		if(it -> second >= max) { winner = it -> first; max = it -> second; }
	cout << winner << ' ' << max << endl;
	return 0;
}

