/*Moby has stepped out to make some purchases in national market. He is carrying a bag with him which can hold goods till certain capacity.
 His aim is to look out for all the items and fill his bag with most profitable items.*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int fun(int n,int w[],int v[],int index,int cap)
{
    if(index==0)
    {
        if(w[index]<=cap)
            return v[index];
        return 0;
    }
    int tk=-1;
    int notak;
    notak=0+fun(n,w,v,index-1,cap);
    if(w[index]<=cap)
        tk=v[index]+fun(n,w,v,index-1,cap-w[index]);
    return max(tk,notak);
}


int main() {
   int n;
    cin>>n;
    int w[n];
    int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }
    int c;
    cin>>c;
    cout<<fun(n,w,v,n-1,c);
    return 0;
}
