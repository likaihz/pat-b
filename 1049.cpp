#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
int main()
{
  int N, i;
  cin>>N;
  vector<double> Nums(N);
  double sum = 0;
  for(i = 0; i < N; i++)
    cin>>Nums[i];
  for(i = 0; i < N; i++)
    sum += (N - i)*Nums[i]*(i + 1);
  cout<<fixed<<setprecision(2)<<sum << endl;

  return 0;
}


/*每个数字出现的次数为(N - i) * (i + 1) 次*/
