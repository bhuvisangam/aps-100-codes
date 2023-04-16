/*An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
Given an array arr[] of size N, Return the index of any one of its peak elements.
Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0. */
//{ Driver Code Starts
//Initial Template for C

#include<stdio.h>
#include<stdbool.h>

int peakElement(int arr[], int n)
{
   int left = 0;
      int right = n - 1;
      while(left < right){
          int mid = left + (right - left)/2;
          if(arr[mid] < arr[mid + 1]){
              left = mid + 1;
          }else{
              right = mid;
          }
      }
      return left;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			tmp[i] = a[i];
		}
		bool f=0;

		int A = peakElement(tmp,n);

		if(A<0 && A>=n)
		    printf("0\n");
		else
		{
    		if(n==1 && A==0)
    		    f=1;
    		else if(A==0 && a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 && a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] && a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		printf("%d\n", f);
		}

	}

	return 0;
}
