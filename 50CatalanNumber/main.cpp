#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int>dp(n+1);
  dp[0] = 1;
  dp[1] = 1;
  for(int i=2;i<=n;i++)
  {
    dp[i] = 0;
    for(int j=0;j<i;j++)
    {
      dp[i] += dp[j] * dp[i - j - 1];
    }
  }
  cout<<dp[n]<<"\n";
  return 0;
}
