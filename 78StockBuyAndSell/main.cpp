/*The cost of stock on each day is given in an array A[] of size N.
Find all the segments of days on which you buy and sell the stock so that in between those days  for which profit can be generated*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<vector<int> > stockBuySell(vector<int> A, int n){
       int s, e;
       vector<vector<int>>ans;
       int buy = 1;
// buy = 1 means buy is allowed

       for(int i = 0; i < n-1; i++){
           if(buy){
               if(A[i] < A[i+1]){
                   buy = 0;
                   s = i;
               }
           }
           else{
               if(A[i] > A[i+1]){
                   e = i;
                   ans.push_back({s,e});
                   buy = 1;
               }
           }

       }
// After the end of loop if buy is false then we have to sell last Item for making the profit higher
       if(buy == 0){
           ans.push_back({s,n-1});
       }
       return ans;
   }
};

//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}
