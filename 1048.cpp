#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
int main()
{
	string a, b;
	string res = "";
	cin >> a ;
	cin >> b;
	int i = 1;
	int len1 = a.length(), len2 = b.length();
	if(len2 < len1)
		for(int i = 0; i < len1 - len2; i++)
			b = "0" + b;
	stringstream buf;
	auto ait = a.rbegin();
	auto bit = b.rbegin();
	for(bit = b.rbegin(); bit != b.rend(); bit++, i++)
	{

		if(ait == a.rend()) {
			reverse(res.begin(), res.end());
			string buf(b.begin(), bit.base());
			res = buf + res;
			break;
		}
		else {
			int tmpa, tmpb;
			buf << *ait; buf >> tmpa; buf.clear();
			buf << *bit; buf >> tmpb; buf.clear();
			if(i%2) 
			{
				int sum = tmpa + tmpb;
				sum %= 13;
				if(sum < 10)
					buf << sum;
				else
					switch(sum) {
						case 10: buf << "J"; break;
						case 11: buf << "Q"; break;
						case 12: buf << "K"; break;
					}
				string tmp;
				buf >> tmp;	res += tmp; buf.clear();
			}
			else { 				//even
				int diff = tmpb - tmpa;
				if(diff < 0) diff += 10;
				string tmp;
				buf << diff; buf >> tmp; res += tmp;
				buf.clear();
			}
		}
		ait++;	
	}
	if(bit == b.rend()) reverse(res.begin(), res.end());
	for(auto it = res.begin(); it != res.end(); )
	{
		if(*it == '0') res.erase(it);
		else break;
	}
	cout << res << endl;
}

/*简直坑爹，如果B比A位数少，还要在B高位补零。。。*/

