/*Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
   {
       int t[n+1][W+1];
      for(int i=0;i<n+1;i++)
      {
          for(int j=0;j<W+1;j++)
          {
              if(i==0 || j==0) t[i][j]=0;
          }
      }
      for(int i=1;i<n+1;i++)
      {
          for(int j=1;j<W+1;j++)
          {
              if(wt[i-1]<=j)
               t[i][j]= max(val[i-1]+t[i][j-wt[i-1]] , t[i-1][j]);
              else
               t[i][j]=t[i-1][j];
          }
      }
      return t[n][W];
   }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];

        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
