#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:

    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int t=0,s=0,fs=0;
       for(int i=0;i<n;i++){
           t=t+(p[i].petrol-p[i].distance);
           if(t<0)
           {
               fs=fs+t;
               s=i+1;
               t=0;
           }
       }
       if(fs+t>0)
       return s;
       else
       return -1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
