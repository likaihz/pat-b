#include<iostream>
#include<string>
using namespace std;

void check();
int main()
{
    int n;
    cin >> n;
    for(;n--;) check();
    return 0;
}


void check()
{
    string s;
    cin>>s;
    int n[3] = {0,0,0};
    int idx = 0;
    int len = s.length();
    int res = 0;
    string::size_type pos_p, pos_a, pos_t;
    pos_p = s.find('P');
    pos_a = s.find('A');
    pos_t = s.find('T');
    if(pos_p == s.npos || pos_a == s.npos || pos_t == s.npos )
        res = 1;
    else
    for(int i = 0; i<len; i++)
    {
        char tmp = s[i];
        switch(tmp)
        {
        case 'P':
            if(idx == 0)
                idx++;
            else
                res = 1;
            break;
        case 'A':
            n[idx]++;
            break;
        case 'T':
            if(idx == 1)
                idx++;
            else
                res = 1;
            break;
        default:
            res = 1;
        }
        if(res) break;
    }

    if(res) cout<< "NO" <<endl;
    else if(n[0] * n[1] == n[2]) cout << "YES" << endl;
    else cout <<"NO" <<endl;
    return;
}

