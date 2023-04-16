#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*Token provider system has a very simple goal:
Generate a token for every request. Every new day begins with a token number that starts with 1.
The generated token number is appended to the date. The token provider system suppots the following operations:
**request** - generates a new token
**cancel** - cancels the previously generated token
**print** - prints the last generated token number.*/

int main() {
    string s;
    getline(cin,s);
    int n;
    cin>>n;
    int c=0;
    string y="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
            continue;
        else
            y=y+s[i];
    }
    for(int i=0;i<n;i++)
    {
          string in;
        cin>>in;
        if(in=="request")
            c++;
        else if(in=="cancel")
            c--;
        else
        {
            if(c<0)
                c=0;
            cout<<y<<c<<endl;
        }
    }
    return 0;
}
