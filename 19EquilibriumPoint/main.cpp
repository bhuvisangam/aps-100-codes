/*Given an array A of n positive numbers.
The task is to find the first Equilibrium Point in an array.
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Note: Return the index of Equilibrium point. (1-based index)*/
#include <iostream>
using namespace std;
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {

        // Your code here
        int sum=0;
        int isum;
        int jsum=a[0];
        for(int i=0;i<n;i++)
        sum=sum+a[i];
        if(n==1)
        return 1;
        for(int i=1;i<n-1;i++)
        {
            jsum=jsum+a[i];
             isum=sum-jsum;
             if(jsum-a[i]==isum)
             return i+1;
        }
        return -1;
    }

};
int main() {

    long long t;

    //taking testcases
    cin >> t;

    while (t--) {
        long long n;

        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
