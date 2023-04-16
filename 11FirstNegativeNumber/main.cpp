//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}



vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {

                                 vector<long long int>v;
                                 queue<long long int>q;
                                 for(int i=0;i<K-1;i++)
                                 {
                                     if(A[i]<0)
                                     {
                                         q.push(A[i]);
                                     }
                                 }
                                 for(int i=K-1;i<N;i++)
                                 {
                                     if(A[i]<0)
                                     {
                                         q.push(A[i]);
                                     }
                                     if(!q.empty())
                                     {
                                         v.push_back(q.front());
                                         if(q.front()==A[i-K+1])
                                     {
                                         q.pop();
                                     }
                                     }
                                      else if(q.empty())
                                     {
                                         v.push_back(0);
                                     }
                                 }
                                 return v;
 }
