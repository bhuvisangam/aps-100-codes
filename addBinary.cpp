#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    string addBinary(string a, string b) {
        int i=a.length()-1,j=b.length()-1;
        int ans;
        int carry=0;
        string res;
        while(i>=0||j>=0){
            ans=carry;
            if(i>=0)
          ans+=a[i]-'0';
          if(j>=0)
          ans+=b[j]-'0';
          i--;j--;
          carry=ans/2;
          res+=to_string(ans%2);
        }
        if(carry!=0){
          res+='1';
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
  int main()
    {
    string a,b;
    cin>>a>>b;
    Solution ob;
    cout<<ob.addBinary(a,b);
    return 0;
    }
