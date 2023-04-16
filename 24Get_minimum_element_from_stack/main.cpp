//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.*/

class Solution{
     int minEle;
   stack<int> s;
   public:

      /*returns min element from stack*/
       int getMin(){
           if(s.size() == 0)
               return -1;
           return minEle;
       }

      /*returns popped element from stack*/
       int pop()
       {
           if(s.empty())
               return -1;

           if(s.top() >= minEle)
           {
               int ans = s.top();
               s.pop();
               return ans;
           }
           else if(s.top() < minEle)
           {
               int ans = minEle;
               minEle = 2*minEle-s.top();
               s.pop();
               return ans;
           }
       }

      /*push element x into the stack*/
       void push(int x)
       {
           if(s.size() == 0)
           {
               s.push(x);
               minEle = x;
           }
           else
           {
               if(x >= minEle)
               {
                   s.push(x);
               }
               else
               {
                   s.push(2*x-minEle);
                   minEle = x;
               }
           }
       }
};


int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
