/*Given a binary string S consisting of 0s and 1s. The task is to find the maximum difference of the number of 0s and the number of 1s
(number of 0s – number of 1s) in the substrings of a string.

Note: In the case of all 1s, the answer will be -1.*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int maxSubstring(string s) {
    int sweep = 0, ans = -1;
    for (auto c : s) {
        if (c == '0')sweep++;
        else sweep--;
        ans = max(ans, sweep);
        if (sweep < 0)sweep = 0;
    }
    return ans;
}
};

int main()
{


   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

