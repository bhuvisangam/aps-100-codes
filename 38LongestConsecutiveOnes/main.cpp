//Given a number N. Find the length of the longest consecutive 1s in its binary representation.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxConsecutiveOnes(int n)
    {
        int max=0;
        int c=0;
        while(n!=0){
            if((n&1)==1){
                c++;
                if(c>max)
                max=c;
            }
            else{
                c=0;
            }
            n>>=1;
        }
        return max;
    }
};

int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}
