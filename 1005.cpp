#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Num
{
public:
    int n;
    int iskey;
    //Num() { n = 1; iskey = 1; }
    //Num(int x) { n = x; iskey = 1; }
};




int dec(const void * a, const void * b)
{
    return ((*(Num * )a).n) < ((*(Num * )b).n);
}



int main()
{
    int n, cnt = 0;
    vector<Num> vec;
    int i;
    cin >> n;
    Num x[n];
    for(i = 0; i < n; i++)
    {
        cin >> x[i].n;
        x[i].iskey = 1;
    }
    for(int j = 0; j < n; j++)
    {
        if(x[j].iskey == 0)
            continue;
        int tmp = x[j].n;
        while(tmp != 1)
        {
            if(tmp % 2 ==0)
                tmp /= 2;
            else
                tmp = (3 * tmp + 1) / 2;
            for(int h = 0; h < n; h++)
            {
                if(h == j || x[h].iskey == 0)
                    continue;
                if(tmp == x[h].n)
                    x[h].iskey = 0;
            }
        }
    }
    for(i = 0; i < n; i++)
        if(x[i].iskey == 1)
        {
            cnt++;
            vec.push_back(x[i]);
        }
    qsort(&vec[0], vec.size(), sizeof(Num), dec);
    
    cout << vec[0].n;
    for(i = 1; i < vec.size(); i++)
        cout << " " << vec[i].n;

    return 0;
}
