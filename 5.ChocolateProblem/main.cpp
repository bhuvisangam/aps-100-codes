#include <bits/stdc++.h>
using namespace std;

/*Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum*/

class Solution{
    public:
    long long findMinDiff(vector<long long> arr, long long n, long long m){
        sort(arr.begin(),arr.end());
        long long ans = INT_MAX;
        long long left = 0;
        long long right = left+m-1;
        while(right < n){
            long long diffrence = arr[right]-arr[left];
            ans = min(ans,diffrence);
            right++;
            left++;
        }
        return ans;
    }
};
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}

		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
