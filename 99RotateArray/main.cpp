#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

void rotateArr(int arr[], int d, int n){

       d=d%n;

       reverse(arr, arr+d);
       reverse(arr+d, arr+n);
       reverse(arr, arr+n);

   }
};


int main() {
	int t;
	//taking testcases
	cin >> t;

	while(t--){
	    int n, d;

	    //input n and d
	    cin >> n >> d;

	    int arr[n];

	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);

	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
