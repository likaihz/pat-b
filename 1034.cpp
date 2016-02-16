#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>

using namespace std;

long long Gcd(long long a, long long b)
{
	long long c;
	while(b!=0)
	{c = a%b; a = b; b = c ; }
	return a;
}

string trans(long long x, long long y)
{
	if(y<0 ) {
		x = -x;
		y = -y;
	}
	stringstream res ;
	long long  inte = x / y;
	if(x == 0) res << '0';
	else {
		long long rmd = abs(x%y);
		if(x < 0) res << '(';
		if(inte != 0) res << inte ;
		if(rmd != 0) {
			if(inte != 0) res << ' ';
			else if(x < 0) res << '-';
			long long gcd = Gcd(rmd, y);
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
	long long  a1, b1, a2, b2;
	string op1, op2, res;
	scanf("%lld/%lld%lld/%lld", &a1, &b1, &a2, &b2);
	long long r1, r2;
	long long gcd = Gcd(a1, b1);
	a1 /= gcd;
	b1 /= gcd;
	gcd = Gcd(a2, b2);
	a2 /= gcd;
	b2 /= gcd;
	
	/****** plus ***********/
	gcd = Gcd(b1, b2);
	r1 = a1 * (b2 / gcd) + a2 * (b1 / gcd);
	r2 = b1 * (b2 / gcd);
	op1 = trans(a1, b1);
	op2 = trans(a2, b2);
	res = trans(r1, r2);
	cout << op1 << " + " << op2 << " = " << res << endl;

	/***** minus *********/
	r1 = a1 * (b2 / gcd) - a2 * (b1 / gcd);

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
