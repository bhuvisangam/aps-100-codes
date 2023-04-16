/*Some people(n) are standing in a queue. A selection process follows a rule where people standing on even positions are selected.
Of the selected people a queue is formed and again out of these only people on even position are selected.
This continues until we are left with one person. Find out the position of that person in the original queue.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
 long long int nthPosition(long long int n){
       if(n==1)
           return 1;

       return nthPosition(n/2)*2;
   }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout<<ob.nthPosition(n)<<endl;
    }
    return 0;
}
