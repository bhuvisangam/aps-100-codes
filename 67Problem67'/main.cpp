/*Given two integers ‘n’ and ‘sum’, find the count of all n digit numbers whose sum of digits is ‘sum’. Leading 0’s are not counted as digits. */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
long int count(int n,int sum,vector<vector<int>> &vec){
if(n==0){
return sum==0;
}
if(vec[n][sum]!=-1){
return vec[n][sum];
}
long int ans=0;
for(int i=0;i<=9;i++){
if(sum-i>=0){
ans+=count(n-1,sum-i,vec);
ans=ans%1000000007;
}
}
return vec[n][sum]=ans;
}
long int countWays(int n, int Sum){
vector<vector<int>> vec(n+1,vector<int>(Sum+1,-1));
long int ans=0;
for(int i=1;i<=9;i++){
if(Sum-i>=0){
ans+=count(n-1,Sum-i,vec);
ans=ans%1000000007;
}
}
return ans?ans:-1;
}
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, Sum;
        cin>>n>>Sum;

        Solution ob;
        cout<<ob.countWays(n, Sum)<<endl;
    }
    return 0;
}
