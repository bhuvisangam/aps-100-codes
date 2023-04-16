#include<bits/stdc++.h>
using namespace std;
/*Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).*/

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> y;
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='[' || x[i]=='{' || x[i]=='(')
            {
                y.push(x[i]);
            }
            else{
                if(!y.empty())
                {
                    char t=y.top();
                    if(matches(x[i],t))
                    {
                        y.pop();
                    }
                    else if(!matches(x[i],t))
                   { return false;}
                }
                else if(y.empty())
                return false;

            }
        }
        if(!y.empty())
        return false;
        return true;
    }
    bool matches(char a,char b)
    {
        if(a==']' && b=='[')
        {
            return true;
        }
        else  if(a=='}' && b=='{')
        {
            return true;
        }
             else  if(a==')' && b=='(')
        {
            return true;
        }
        else
        return false;
    }

};
int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
