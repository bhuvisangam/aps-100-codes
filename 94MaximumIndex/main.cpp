#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
         vector<int > suffMax(n + 1, 0);
       for(int i = n - 1; i >= 0; --i)
           suffMax[i] = max(suffMax[i + 1], arr[i]);


       int i = 0, j = 0, ans = 0;
       while(i < n and j < n){
           if(arr[i] <= suffMax[j]){
               ++j;
           } else {
               ++i;
           }

           ans = max(ans, j - i - 1);
       }

       return ans;
    }

};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
