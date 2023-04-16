/*Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly X.*/

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
	bool hasArrayTwoCandidates(int arr[], int n, int x) {

	    unordered_set<int> s;

	    for(int i=0 ; i<n ; i++){
	        if( s.count(x-arr[i]) == 1) return true;
	        s.insert(arr[i]);
	    }

	    return false;

	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
