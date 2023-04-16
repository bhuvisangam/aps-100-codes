#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int isValid(string s)
       {
           int dot_count = 0;
           int digit_count = 0;

           for(int i = 0; i < s.length(); i++)
           {
               if(s[i] == '.')
                   dot_count++;
           }
           if(dot_count != 3)
               return 0;

           unordered_set<string> us;

           for(int i = 0; i < 256; i++)
           {
               us.insert(to_string(i));
           }

           string temp = "";

           for(int i = 0; i < s.length(); i++)
           {
               if(s[i] != '.')
                   temp = temp + s[i];
               else
               {
                   if(us.find(temp) != us.end())
                   {
                       digit_count++;
                       temp = "";
                   }
               }
           }
           if(us.find(temp) != us.end())
               digit_count++;

           if(digit_count == 4)
               return 1;
           else
               return 0;
       }


};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
