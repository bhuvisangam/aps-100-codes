/*Given a rod of length N inches and an array of prices, price[]. pricei denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
Note: Consider 1-based indexing.*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution{
 public:
   int cutRod(int price[], int n) {

       int arr[n];
       for(int i=0;i<n;i++){
           arr[i]=i+1;
       }
       int t[n+1][n+1];
       for(int i=0;i<n+1;i++){
           for(int j=0;j<n+1;j++){
               if(i==0){
                   t[i][j]=0;
               }
               else if (j==0){
                   t[i][j]=0;
               }
           }
       }


       for(int i=1;i<n+1;i++){
           for(int j=1;j<n+1;j++){
               if(arr[i-1]<=j){
                   t[i][j]=max(price[i-1]+t[i][j-arr[i-1]],t[i-1][j]);
               }
               else if(arr[i-1]>j){
                   t[i][j]=t[i-1][j];
               }
           }
       }
       return t[n][n];
   }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
