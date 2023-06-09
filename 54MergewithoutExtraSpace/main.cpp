/*Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted
 order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m)
        {
                  int i=n-1;
          int j=0;
          while(i>=0 && j <m){
              if(arr1[i]>arr2[j]){
                  swap(arr1[i], arr2[j]);
              }
              i--;
              j++;
          }
          sort(arr1, arr1+n);
          sort(arr2, arr2+m);
        }
};

int main()
{

	int T;
	cin >> T;

	while(T--){
	    int n, m;
	    cin >> n >> m;

	    long long arr1[n], arr2[m];

	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }

	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout<<arr1[i]<<" ";


	    for (int i = 0; i < m; i++)
		    cout<<arr2[i]<<" ";

	    cout<<endl;
	}

	return 0;
}
