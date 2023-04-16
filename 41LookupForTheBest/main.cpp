/*There is a fun fair in town led by a dynamic manager.
With no doubts on the creativity and the leadership qualities of the manager, he is also a multi-discipline believer.
A technology pandit who once visited the fun fair said that every shop has a lucky number.
The lucky number is the number of bits set to one in the shop number assigned to each.
Manager now wants to build a table which comprises of these (shop number, lucky number) so
that he can further make queries to find the sum of lucky numbers of several shops put together.*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long int countSetBits(long long int num){
   long long int  remainder, base = 1, binary = 0, no_of_1s = 0;
     while (num > 0)
    {
        remainder = num % 2;
        /*  To count no.of 1s */
        if (remainder == 1)
        {
            no_of_1s++;
        }
        binary = binary + remainder * base;
        num = num / 2;
        base = base * 10;
    }
    return no_of_1s;
}

int main() {
    long long int n;
    cin>>n;
   long long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

   long long int count=0;
    for(int i=0;i<n;i++){
         count=count+countSetBits(a[i]);
    }
    cout<<count<<endl;
    return 0;
}
