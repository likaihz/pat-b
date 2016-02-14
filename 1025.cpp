#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
class Node{
public:
	int addr;
	int data;
	int next;
	Node(int a, int d, int n): addr(a), data(d), next(n) { };
	void Print();
};

void Node::Print()
{
	printf("%05d %d ",addr, data);
	if(next < 0)
		printf("%d\n", next);
	else
		printf("%05d\n", next);
}

void MyPush(vector<Node>& vec, int addr, int data, int next)
{
	Node node(addr, data, next);
	vec.push_back(node);
}

void Sort(vector<Node>& vec, vector<Node>& des, int head, int N)
{
	int nxt = head;
	while(nxt != -1)
	{
		for(int i = 0; i < N; i++)
		{
			if(vec[i].addr == nxt)
			{
				MyPush(des, vec[i].addr, vec[i].data, vec[i].next);
				nxt = vec[i].next;
			}
		}
	}
}

int main()
{
	
	int N,K,head;
	vector<Node> vec, or_vec;
	cin >> head >> N >> K;
	if(head == -1)
		return 0;
	for(int i = 0; i < N; i++)
	{
		int ta, td, tn;
		cin >> ta >> td >> tn;
		MyPush(vec, ta, td, tn);
	}
	Sort(vec, or_vec, head, N);
	N = or_vec.size();
	if(K == 1)
	{
		for(int i = 0; i<N; i++)
			or_vec[i].Print();
		return 0;
	}
	vec.erase(vec.begin(), vec.end());
//	MyPush(or_vec, -1, -1, -1);

	int time = N / K;

/*	for(int i = 0; i < time; i++)
	{
		if(i == time -1 )
			or_vec[K * i].next = or_vec[K * i + K].addr;
		else
			or_vec[K * i].next = or_vec[K * i + K + K -1].addr;
		for(int j = K * i +1; j < K * i +K; j++)
		{
			or_vec[j].next = or_vec[j-1].addr;
		}
	}
	or_vec.erase(or_vec.end()-1);
	Sort(or_vec, vec, or_vec[K-1].addr, N);*/
	for(int i = 0; i < time; i++)
	{
		for(int j = K-1; j >= 0; j--)
			MyPush(vec, or_vec[K*i+j].addr, or_vec[K*i+j].data, or_vec[K*i+j].next);
	}
	for(int i = time * K; i < N; i++)
		MyPush(vec, or_vec[i].addr, or_vec[i].data, or_vec[i].next);
	for(int i = 0; i<N-1; i++)
		vec[i].next = vec[i+1].addr;
	vec[N-1].next = -1;
	for(int i = 0; i<N; i++)
		vec[i].Print();
}
