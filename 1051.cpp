#include<iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	double r1, r2;
	double p1, p2;
	cin >> r1 >> p1 >> r2 >> p2;
	double sa = r1 * r2 * cos(p1+p2);
	double sb = r1 * r2 * sin(p1+p2);
	if(-0.005 < sa && sa < 0) printf("0.00");
	else printf("%.2f",sa);

	if(sb>=0) printf("+%.2fi\n",sb);
	else if(-0.005 < sb && sb<0) printf("+0.00i\n");
	else printf("%.2fi\n",sb);
	return 0;
}

//有坑，要防止输出-0.00
