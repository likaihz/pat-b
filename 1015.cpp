#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

class Stu{
public:
    int No;
    int mor;
    int abl;
    Stu(int n, int m, int a) : No(n), mor(m), abl(a) {};
};

void Push(vector<Stu> & vec, int n, int m, int a)
{
    Stu stu(n, m, a);
    vec.push_back(stu);

}


int compare(const void* a1, const void* a2)
{
    int res;
    if(((*(Stu *)a1).mor + (*(Stu *)a1).abl) != ((*(Stu *)a2).mor + (*(Stu *)a2).abl))
        res = (((*(Stu *)a1).mor + (*(Stu *)a1).abl) < ((*(Stu *)a2).mor + (*(Stu *)a2).abl));
    else if((*(Stu *)a1).mor != (*(Stu *)a2).mor)
        res = ((*(Stu *)a1).mor < (*(Stu *)a2).mor);
    else 
        res = ((*(Stu *)a1).No > (*(Stu *)a2).No);

    return res;
    
}

void Print(Stu &s)
{
	printf("%d %d %d\n",s.No, s.mor, s.abl);
}

int main()
{
    int N, L, H;
    int i,j;
    vector<Stu> vec1, vec2, vec3, vec4;
    cin >> N >> L >> H;
    for(i=0; i < N; i++)
    {
        int tn, tm, ta;
        cin >> tn >> tm >> ta;
        if(tm >= L && ta >= L)
            if(tm >= H && ta >= H)
                Push(vec1, tn, tm, ta);
            else if(tm >= H && ta < H)
                Push(vec2, tn, tm, ta);
            else if(tm >= ta )
                Push(vec3, tn, tm, ta);
            else 
                Push(vec4, tn, tm, ta);
    }

    qsort(&vec1[0], vec1.size(), sizeof(Stu), compare);
    qsort(&vec2[0], vec2.size(),sizeof(Stu), compare);
    qsort(&vec3[0], vec3.size(),sizeof(Stu), compare);
    qsort(&vec4[0], vec4.size(), sizeof(Stu),compare);
    int num = vec1.size() + vec2.size() + vec3.size() + vec4.size();
    cout << num << endl;
    for_each(vec1.begin(), vec1.end(), Print);
    for_each(vec2.begin(), vec2.end(), Print);
    for_each(vec3.begin(), vec3.end(), Print);
    for_each(vec4.begin(), vec4.end(), Print);
}
