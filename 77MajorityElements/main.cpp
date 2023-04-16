

#include<bits/stdc++.h>
using namespace std;



class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        if(size==1)
        return a[0];
       sort(a,a+size);
       int c=1;
       for(int i=0;i<size;i++)
       {
           if(a[i]==a[i+1])
           c++;
           else
           c=1;
           if(c>size/2)
           return a[i];
       }
     return -1;
    }
};

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];

        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
