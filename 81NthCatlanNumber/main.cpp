

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;



class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int catalan(int n, vector<cpp_int>&dp)
    {
        if (n <= 1)
        return 1;
        if(dp[n]!=-1) return dp[n];
    // catalan(n) is sum of
    // catalan(i)*catalan(n-i-1)
    cpp_int  res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i,dp)*catalan(n - i - 1,dp);
            //return dp[i]
            return dp[n]=res;
    }
    cpp_int findCatalan(int n)
    {
        vector<cpp_int>dp(n+10,-1);
        return catalan(n,dp);

    }
};

int main()
{
	int t;
	cin>>t;
	while(t--) {

	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";
	}
	return 0;
}
