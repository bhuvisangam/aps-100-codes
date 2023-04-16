/*Given an array of size N, find the smallest positive integer value that is either
 not presented in the array or cannot be represented as a sum(coz sum means you are adding two or more elements) of some elements from the array.*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    long long smallestpositive(vector<long long> arr, int n)
    {
        // code here
        sort(arr.begin(),arr.end());
        long long sum=1;
        for(int i=0;i<n;i++){
            if(arr[i]>sum)
            return sum;
            sum=sum+arr[i];
        }
        return sum;
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
        vector<long long> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>array[i];
        }
        Solution ob;
        cout<<ob.smallestpositive(array,n)<<"\n";
    }
    return 0;
}
