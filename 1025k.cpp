#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<utility>
using namespace std;
typedef pair<int, int> P;
vector<P> coll(100000);
struct node
{
    int adress;
    int data;
    int next;
    node(int a, int b, int c) :adress(a), data(b), next(c){};
};
vector<node> vec;
int main()
{
/*#ifdef ONLINE_JUDGE
#else
    freopen("D:\\in.txt", "r", stdin);
    freopen("D:\\out.txt", "w", stdout);
#endif*/
    int adress, data, next;
    int n, k, first;
    while (scanf("%d%d%d", &first, &n, &k) != EOF)
    {
        int num = n;
        while (n--)
        {
            scanf("%d%d%d", &adress, &data, &next);
            P p;
            p.first = data;
            p.second = next;
            coll[adress] = p;
        }
        int index = first;
        int cnt(0);//�������ϵĽ�����
        while (index != -1)
        {
            cnt++;
            vec.push_back(node(index, coll[index].first, coll[index].second));
            index = coll[index].second;
        }
        int t = cnt / k;
        for (int i = 0; i < t; i++)
            std::reverse(vec.begin() + i*k, vec.begin() + (i + 1)*k);
        for (int i = 0; i < vec.size()-1;i++)
        {
            printf("%05d %d %05d\n", vec[i].adress, vec[i].data, vec[i + 1].adress);
        }
        printf("%05d %d %d\n", vec[vec.size() - 1].adress, vec[vec.size() - 1].data, -1);
        
    }
    return 0;
}