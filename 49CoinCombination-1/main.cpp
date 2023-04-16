#include<bits/stdc++.h>
#define pb push_back
#define int long long int
using namespace std;
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  int sum;
  cin>>sum;
  vector<int>coins(n);
  for(int i=0;i<n;i++)
  {
    cin>>coins[i];
  }
  vector<int>dp(sum+1,0);
  dp[0] = 1;
  for(int i=1;i<=sum;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i-coins[j] >= 0)
      {
        dp[i] = dp[i] + dp[i - coins[j]];
        dp[i] = dp[i] % 1000000007;
      }
    }
  }
  cout<<dp[sum];
  return 0;
}
