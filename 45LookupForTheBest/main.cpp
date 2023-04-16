/*There is a fun fair in town led by a dynamic manager.
With no doubts on the creativity and the leadership qualities of the manager, he is also a multi-discipline believer.
A technology pandit who once visited the fun fair said that every shop has a lucky number.
The lucky number is the number of bits set to one in the shop number assigned to each.
Manager now wants to build a table which comprises of these (shop number, lucky number)
so that he can further make queries to find the sum of lucky numbers of several shops put together.*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  long long int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
   long long int c=0;
    for(int i=0;i<n;i++)
    {
        while(a[i]!=0)
        {
            if(a[i]%2==1)
                c++;
            a[i]=a[i]/2;
        }

    }
    cout<<c<<endl;
    return 0;
}
