#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int dp[x+1][y+1];//create a 2d array
        for(int i=0;i<=x;i++)  //if s1 is a empty string it won't match with any charcter of s2
        {
            dp[i][0]=0;

        }
            for(int j=0;j<=y;j++){//if s2 is a empty string it won't match with any charcter of s1
                dp[0][j]=0;
            }

        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1])//check if character of both strings are equal
                {
                    dp[i][j]=dp[i-1][j-1]+1;//check for longest match at that instance and increment it
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//dont change the value of longest match
                }
            }
        }
        return dp[x][y];//return the longest match
    }
};

int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
