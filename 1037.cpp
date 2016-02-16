#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
	int galleon1, sickle1, knut1;
	int galleon2, sickle2, knut2;
	int res_gal, res_sic, res_knu;
	bool enough = true;
	scanf("%d.%d.%d%d.%d.%d",&galleon1, &sickle1, &knut1, &galleon2, &sickle2, &knut2);
	long long sum1 = knut1 + sickle1 * 29 + galleon1 * 17 * 29;
	long long sum2 = knut2 + sickle2 * 29 + galleon2 * 17 * 29;
	long long diff = sum2 - sum1;
	if(diff < 0) { enough = false; diff = -diff;}
	res_gal = diff / (17*29);
	diff %= (17*29);
	res_sic = diff / 29;
	diff %= 29;
	res_knu = diff;
	if(!enough) cout << '-' ;
	cout << res_gal << '.' << res_sic << '.' << res_knu << endl;
	
	return 0;
}
