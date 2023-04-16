/*Given a sorted array containing only 0s and 1s, find the transition point. */
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}

int transitionPoint(int a[], int n) {

    int l=0;
    int r=n-1;
    int mid;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(a[mid]==1 && a[mid-1]!=1)
        return mid;
        else if(a[mid]==0)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return -1;
}
