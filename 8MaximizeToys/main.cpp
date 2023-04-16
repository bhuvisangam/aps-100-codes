/*Given an array arr[ ] of length N consisting cost of N toys and an integer K depicting the amount with you.
Your task is to find maximum number of toys you can buy with K amount. */
#include <bits/stdc++.h>
using namespace std;
int toyCount(int n, int k, vector<int> arr)
    {
        // code here
        sort(arr.begin(),arr.end());
        int i=0;
        int sum=0;
        int c=0;
        while(i<n && arr[i]<=k)
        {
            int x=sum+arr[i];
            if(x>sum && x<=k)
            {
                sum=x;
                c++;
            }
            i++;
        }
        return c;
   }

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        cout<<toyCount(N, K, arr)<<endl;
    }
    return 0;
}
