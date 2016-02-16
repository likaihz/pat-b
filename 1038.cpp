#include <iostream>
#include <map>

using namespace std;
int main()
{
	map<int, int> record;
	int n, k;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if(record.find(tmp) == record.end()) record[tmp] = 1;
		else record[tmp] += 1;
	}
	cin >> k;
	for(int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		if(record.find(tmp) == record.end()) cout << '0';
		else cout << record[tmp];
		if(i != k-1) cout << ' ' ;
		else cout << endl;
	}

	return 0;
}

/*其实也用不着map，反正百分制，开个数组就行。。
 #include<cstdio>

int main()
{
    int fenshu[101]={0},chafen=0;
    int num=0,temp=0;
    scanf("%d",&num); 
    for(int i=0;i<num;i++) 
    {
            scanf("%d",&temp);
            if(0<=temp && temp<=100) fenshu[temp]++;
    }
    scanf("%d",&num);  
    for(int i=0;i<num;i++)
    {
            scanf("%d",&chafen);
            if(i) printf(" %d",fenshu[chafen]);
            else printf("%d",fenshu[chafen]);
    }    
    return 0;    
}

*/
