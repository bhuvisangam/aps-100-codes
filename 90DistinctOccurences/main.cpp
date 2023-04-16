#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
   #define mod 1000000007

int subsequenceCount(string S, string T)
{ int m=S.size();
int n=T.size();
if(n>m)
return 0;
int dp[m+1][n+1];
for(int i=0;i<=n;i++)
{
dp[0][i]=0;
}
for(int i=0;i<=m;i++)
{
dp[i][0]=1;
}
for(int i=1;i<=m;i++)
{
for(int j=1;j<=n;j++)
{
if(S[i-1]==T[j-1])
{
dp[i][j]=((dp[i-1][j-1])%mod+(dp[i-1][j])%mod)%mod;
}
else
{
dp[i][j]=(dp[i-1][j])%mod;
}
}
}
return (dp[m][n])%mod;
}


};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;

		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;


	}

}
