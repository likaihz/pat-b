#include <iostream>

using namespace std;

int main()
{
	int N, D;
	double e;

	cin >> N >> e >> D;
	int Empty = 0, MB_Empty = 0;
	for(int i = 0; i < N; i++)
	{
		int days, cnt = 0;
		cin >> days;
		for(int j = 0; j < days; j++){
			double tmp;
			cin >> tmp;
			if(tmp < e) cnt++;
		}
		
		if(cnt <= (days / 2)) continue;
		if(days > D) Empty ++;
		else MB_Empty ++;
	}
	double p1 = (double)(MB_Empty)/(double)(N) *100.0;
	double p2 = (double)(Empty)/(double)(N) *100.0;
	printf("%.1f%% %.1f%%\n",p1, p2);
	return 0;
}
