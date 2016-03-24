#include <iostream>
#include <vector>

using namespace std;

class Person {
public:
	string name;
	int height;
	Person(string n, int h):name(n),height(h) {};
	int operator > (Person &p2);
};
int Person::operator >(Person & p2)
{
	return
		(height == p2.height)?(name < p2.name):(height > p2.height);
}

vector<Person> vec;

void Print_line(int this_line, int in_line)
{
	for(int right = this_line - this_line%2; right > 0; right -= 2)
		cout << vec[right+in_line-1].name << ' ';
	int tmp = (this_line%2)?0:1;
	for(int left = 1; left <= this_line - tmp; left += 2)
	{
		cout << vec[left+in_line-1].name;
		if(left != this_line - tmp)
			cout << ' ';
		else
			cout << endl;
	}
}
int main()
{
	int N, K;
	string t_name;
	int t_height;
	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		int flag = 0;
		cin >> t_name >> t_height;
		Person p(t_name, t_height);
		if(i == 0) { vec.push_back(p); flag = 1;}
		else for(auto it = vec.begin(); it != vec.end(); it++)
			if(p > *it) {
				vec.insert(it, p);
				flag = 1;
				break;
			}
		if(!flag) vec.push_back(p);
	}
	int in_line = 0;
	int this_line = N - N / K * (K-1);
	while(in_line != N) {
		Print_line(this_line, in_line);
		in_line += this_line;
		this_line = N / K;
	}
	return 0;
}

//这四题中分最高的反而一次ac了。。不过用时有点长啊，可能是因为插入排序效率太低
