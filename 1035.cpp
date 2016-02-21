#include <iostream>
#include <vector>

using namespace std;
int in[100];
int tmp[100];
int flag = 0;
vector<int> is, ms;
int n;

void inertion_sort(int i)
{
	auto it = is.begin();
	for(int j = 0; j <= i; it++, j++)
		if((j != i && is[j] > in[i]) || (j == i))
		{ is.insert(it, in[i]); break;}
	for(int j = i+1; j < n; j++)
		is[j] = in[j];
}

void merge_sort(int i)
{
	if(i > n) i = n;
	int start = 0, end = 0;
	for(int j = 0; j < n;)
	{
		start = j;
		end = (start+i > n)?n:start+i;
		for(int k = end-1; k >= start; k--)
		{
			int iloc = -1, max = ms[start], l = 0;
			for(l = start; l <= k; l++)
				if(ms[l] >= max) { iloc = 1; max = ms[l];}
			if(iloc >= 0) ms[iloc] = ms[l-1], ms[l-1] = max;
		}
		j += i;
	}
}

int main()
{
	cin >> n;
//	cout << n  << endl;
	for(int i = 0; i < n; i++) {
		cin >> in[i];
		is.push_back(in[i]);
		ms.push_back(in[i]);
	}
	for(int i = 0; i < n; i++)
		cin >> tmp[i];
	for(int i = 1; i < n; i++)
	{
		inertion_sort(i);
		for(int j = 0; j < n; j++)
			if(tmp[j] != is[j]) {flag = -1; break; }
		if(flag == -1) {flag = 0; continue;}
		else {
			flag = 1;
			inertion_sort(i+1);
			break;}
	}
	if(flag == 0)
	{
		for(int i = 1;;)
		{
			merge_sort(i);
			for(int j = 0; j < n; j++)
				if(tmp[j] != ms[j]) {flag = -1; break;}
			if(flag == -1) {
				flag = 0; i*= 2;
				if(i >2*n) break;
			}
			else {
				flag = 2;
				merge_sort(i*2);
				break;
			}
		}
	}

	if(flag == 1) {
		cout << "Insertion Sort" << endl;
		cout << is[0];
		for(int j = 1; j < n; j++)
			cout << ' '<< is[j];
	}
	else{
		cout << "Merge Sort" << endl;
		cout << ms[0];
		for (int j=1; j<n; j++)
			cout << ' '<< ms[j];
	}
	
	cout <<endl;
	return 0;
	
}



/*#include<cstdio>


void Insertion(int *num,int k,int len) 
{
     if(k>=len) k=len-1;
     int temp=num[k];
     for(int i=k-1;i>=0;i--)
     {
             if(num[i]>temp)  num[i+1]=num[i],num[i]=temp;
             else 
                 break;  
     }
}


void Merge(int *num,int k,int len)
{
     if(k>=len) k=len;
     int start=0,end=0;
     for(int i=0;i<len;)
     {
             start=i;
             end=(start+k>len?len:start+k);
             for(int m=end-1;m>=start;m--)
             {
                 int iloc=-1,max=num[start],l=0;
                 for(l=start;l<=m;l++)  if(num[l]>=max) iloc=l,max=num[l]; 
                 if(iloc>=0) num[iloc]=num[l-1],num[l-1]=max;  
             }
             i+=k;
     }
}

int match(int *num0,int *num3,int len)
{
    for(int i=0;i<len;i++)
        if(num0[i]!=num3[i]) return 0;
    return 1;
}


int main()
{
    int n=0;
    int num[100]={0};    // 原数据 
    int num0[100]={0};   // 处理后 
    int num1[100]={0};
    
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    for(int i=0;i<n;i++) scanf("%d",&num0[i]);
        
    for(int i=0;i<n;i++)  num1[i]=num[i];
    for(int i=1;i<n;i++)
    {
        Insertion(num1,i,n);
        if(match(num0,num1,n))
        {
            printf("Insertion Sort\n"); 
            Insertion(num1,i+1,n);
            for(int j=0;j<n;j++)
            {   
                if(j==n-1) printf("%d",num1[j]);
                else  printf("%d ",num1[j]);
            }
            return 0;
        }
    }
    
    for(int i=0;i<n;i++) num1[i]=num[i]; 
    for(int i=1;;)
    {
        Merge(num1,i,n);
        if(match(num0,num1,n))
        {
            printf("Merge Sort\n");
            Merge(num1,i*2,n);
            for(int j=0;j<n;j++)
            {   
                if(j==n-1) printf("%d",num1[j]);
                else  printf("%d ",num1[j]);
            }
            return 0;
        }
        i*=2;
        if(i>2*n)  break;
    }  
        
    return 0;
}


*/
