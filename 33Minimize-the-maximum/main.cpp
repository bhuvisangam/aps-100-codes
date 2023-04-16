#include <iostream>
#include<vector>
#include <bits/stdc++.h>
//https://www.codechef.com/problems/MINMAXARR
using namespace std;
bool fun(vector<long long int> t,long long int a)
{
    for(int j=t.size()-1;j>0;j--)
    {
        if(t[j]>a)
        {
            t[j-1]+=t[j]-a;
        }
    }
    if(t[0]>a)
    {
        return false;
    }
    else
    return true;
}
void fun2()
{
    int s;
    cin>>s;
    vector<long long int>x(s);
    for(int i=0;i<s;i++)
    {
        cin>>x[i];
    }
    long long int sum=0;
    long long int mx=0;
    for(int i=0;i<s;i++)
    {
        if(mx<x[i])
        {
            mx=x[i];
        }

    }
    long long int l=0,h=mx;
    long long int an=mx;
    while(l<=h)
    {
        long long int md=(l+h)/2;
        if(fun(x,md))
        {
            h=md-1;
            an=md;
        }
        else
        {
            l=md+1;
        }
    }
    cout<<an<<endl;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t!=0){
	fun2();
	t--;

	}return 0;

}
