/*Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        int sum = 0;
       for(int i : array)
        sum+=i;
       return n*(n+1)/2 - sum;
}
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}
