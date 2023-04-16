/*Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons.
 Initially the miner can start from any row in the first column. From a given cell, the miner can move

1.to the cell diagonally up towards the right
2.to the right
3.to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect.*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> ar)
    {
        int dp[n][m];
        for(int i=0;i<n;i++)
        {
            dp[i][0] = ar[i][0];
        }
        for(int j=1;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                int right = dp[i][j-1];
                int right_up = (i==0)?0 : dp[i-1][j-1];
                int right_dn = (i==n-1)?0 : dp[i+1][j-1];
                dp[i][j] = ar[i][j] + max(right,max(right_up,right_dn));
            }
        }
        int result = INT_MIN;
        for(int i=0;i<n;i++){
            result = max(result,dp[i][m-1]);
        }
        return result;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }

        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
