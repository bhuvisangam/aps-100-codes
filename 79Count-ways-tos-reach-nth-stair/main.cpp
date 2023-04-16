#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int mod = 1e9+7;
    int dp[10001];

    int helper(int n){
        if(n == 0 || n == 1) return 1;

        if(dp[n] != -1) return dp[n] % mod;

        return dp[n] = (helper(n-1) % mod + helper(n-2) % mod) % mod;
    }

    int countWays(int n)
    {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
