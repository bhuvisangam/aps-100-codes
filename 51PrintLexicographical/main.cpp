#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
int findSecond(string s , char first , int firstIndex , int len)
{
  int second = firstIndex;
  for(int i=firstIndex+1 ; i<len ; i++)
  {
    if(s[i] > first && s[i] < s[second])
      second = i;
  }
  return second;
}
void sortedPer(string s)
{
  int len = s.size();
  sort(s.begin(),s.end());
  int flag = 0;
  while(flag == 0)
  {
    cout<<s<<"\n";
    int i;
    for(i=len-2;i>=0;i--)
    {
      if(s[i] < s[i+1])
      {
        break;
      }
    }
    if(i==-1)
      flag = 1;
    else
    {
      int secondIndex = findSecond(s , s[i] , i+1 , len);
      swap(s[i] , s[secondIndex]);
      sort(s.begin()+i+1 , s.end());
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  string s;
  cin>>s;
  sortedPer(s);
  return 0;
}
