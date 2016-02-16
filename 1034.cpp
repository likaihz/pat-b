#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>

using namespace std;

string trans(int x, int y)
{
	if(y<0 ) {
		x = -x;
		y = -y;
	}
	stringstream res ;
	int inte = x / y;
	if(x == 0) res << '0';
	else {
		int rmd = abs(x%y);
		if(x < 0) res << '(';
		if(inte != 0) res << inte ;
		if(rmd != 0) {
			if(inte != 0) res << ' ';
			else if(x < 0) res << '-';
			int gcd = 1;
			for(int i = 2; i <= rmd; i++)
				if(rmd % i == 0 && y % i == 0) 
					gcd = i;
			rmd /= gcd;
			y /= gcd;
			res << rmd << '/' << y;
		}
		if(x < 0) res << ')';
	}

	string tmp = res.str();
	return tmp;
}

int main()
{
	int a1, b1, a2, b2;
	string op1, op2, res;
	scanf("%d/%d%d/%d", &a1, &b1, &a2, &b2);
	//printf("%d %d %d %d\n", a1, b1, a2, b2);
	int r1, r2;

	/****** plus ***********/
	r1 = a1 * b2 + a2 * b1;
	r2 = b1 * b2;
	op1 = trans(a1, b1);
	op2 = trans(a2, b2);
	res = trans(r1, r2);
	cout << op1 << " + " << op2 << " = " << res << endl;

	/***** minus *********/
	r1 = a1 * b2 - a2 * b1;
	res = trans(r1, r2);
	cout << op1 << " - " << op2 << " = " << res << endl;

	/******** multiple *********/
	r1 = a1 * a2;
	r2 = b1 * b2;
	res = trans(r1, r2);
	cout << op1 << " * " << op2 << " = " << res << endl;

	/******** divide *********/
	if(a2 == 0)
		res = "Inf";
	else {
		r1 = a1 * b2;
		r2 = a2 * b1;
		res = trans(r1, r2);
	}
	cout << op1 << " / " << op2 << " = " << res << endl;
	return 0;
}
