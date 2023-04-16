#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
      cin>>vec[i];
    }
    int MAX = vec[0];
    int count = 1;
    for(int i=1;i<n;i++)
    {
      if(vec[i] > MAX)
      {
        MAX = vec[i];
        count++;
      }
    }
    if(count%2 == 0)
    {
      cout<<"ANDY\n";
    }
    else
    {
      cout<<"BOB\n";
    }
  }
  return 0;
}
