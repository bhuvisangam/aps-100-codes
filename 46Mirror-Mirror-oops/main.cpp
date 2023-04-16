/*Every string goes through two mirrors. The first mirror changes A to Z, B to Y, C to X and so on.
The second mirror reverses/switches the characters. All this happens between the given range L to R, inclusive.*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    cin>>s;
    int l,r;
    cin>>l>>r;
    string y="";
    for(int i=0;i<s.length();i++)
    {
        if((i+1)>=l && (i+1)<=r)
        {
            s[i]='Z'+'A'-s[i];
        }
    }
    //cout<<s<<endl;
    for(int i=0;i<l-1;i++)
        y=y+s[i];
    for(int i=r-1;i>=l-1;i--)
        y=y+s[i];
    for(int i=r;i<s.length();i++)
        y=y+s[i];
    cout<<y<<endl;
    return 0;
}
