#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string b)
    {
       stack<string>a;
       string y="";
       for(int i=0;i<b.length();i++)
       {
           if(b[i]=='.')
           {
               a.push(y);
               y="";
               y=y+b[i];
               a.push(y);
               y="";
           }
           else
           y=y+b[i];
       }
       a.push(y);
       string ans="";
       while(!a.empty())
       {
           ans=ans+a.top();
           a.pop();
       }
       return ans;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
