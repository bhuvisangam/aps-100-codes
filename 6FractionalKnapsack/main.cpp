//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
//Fractional Knapsack
struct Item{
    int value;
    int weight;
};

bool cmp(Item a, Item b)
{
    return a.value/(a.weight*1.0)>b.value/(b.weight*1.0);
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
       sort(arr,arr+n,cmp);

      int i;
      double sum=0.0;

      for(i=0;i<n;i++)
      {
          if(w-arr[i].weight>=0)
          {
              sum+=arr[i].value;
              w-=arr[i].weight;
          }
          else
          {
              sum+=w*(arr[i].value/(arr[i].weight*1.0));
              break;
          }
      }
       return sum;
    }

};

int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;

		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}

		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
