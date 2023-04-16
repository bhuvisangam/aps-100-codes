
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int checkPalindrome(string S,int l,int r){
	    if(l>=r){
	        return 1;
	    }
	    else{
	        if(S[l]!=S[r]){
	            return 0;
	        }
	        else{
	            return checkPalindrome(S,l+1,r-1);
	        }
	    }
	}

	int isPalindrome(string S)
	{
	    int l=0;
	    int r=S.length()-1;
	    return checkPalindrome(S,l,r);
	}

};


int main()
{

   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
