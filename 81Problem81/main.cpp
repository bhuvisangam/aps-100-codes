/*Given N friends, each one can remain single or can be paired up with some other friend.
Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int f(int n,vector<int>&dp)
    {
        if(n==3)
        return 4;
        if(n==2)
        return 2;
        if(n==1)
        return 1;
        if(dp[n]!=-1)
        return dp[n];
        return dp[n]=(f(n-1,dp)+(n-1)*f(n-2,dp))%1000000007;
    }
    int countFriendsPairings(int n)
    {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n);
    	cout<<endl;
    }
}
