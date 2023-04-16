#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//https://www.codechef.com/problems/ARRHALVES
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t!=0)
	{
	    int n;
	    cin>>n;
	    long long int a[2*n];
	    for(int j=0;j<2*n;j++)
	    cin>>a[j];
	    vector<long long int>a1;
	    vector<long long int>a2;
	    for(int i=0;i<2*n;i++)
	    {
	        if(a[i]>n && i<n)
	        a1.push_back(i+1);
	        if(a[i]<=n && i>=n)
	        a2.push_back(i+1);
	    }
	    sort(a1.begin(),a1.end());
	    sort(a2.begin(),a2.end());
	    long long int x=0;
	    n=a1.size();
	    for(int i=0;i<n;i++)
	    x+=abs(a1[i]-a2[i]);
	    cout<<x<<endl;
	    t--;
	}
	return 0;
}

