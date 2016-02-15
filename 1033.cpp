#include <iostream>
#include <string>

using namespace std;
int main()
{
	string lostkey;
	string in, out = "";
//	cin >> lostkey;
//	cin >> in;
	getline(cin, lostkey);
	getline(cin, in);

	for(auto it = in.begin(); it != in.end(); it++)
	{
		if(*it >= 'A' && *it <= 'Z')
			if(lostkey.find('+') != string::npos) continue;
		char tmp = *it;
		if(tmp >= 'a' && tmp <= 'z')
			tmp = 'A' + (tmp - 'a');
		if(lostkey.find(tmp) != string::npos) continue;
		
		out += *it;
	}
	cout << out << endl;
	return 0;
}


/* summary:
 *  the statement just garantees that the second line is not empty, but the first line can be empty,
 *  which is that there is no lost key. So it's wrong to use "cin >> " to get input;
 */
