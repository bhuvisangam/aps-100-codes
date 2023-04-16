#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

class Solution
{
    public:
   void merge(int arr[], int l, int m, int r)
{
    int left = m - l + 1, right = r - m;
    int leftArr[left], rightArr[right];
    for(int i=0;i<left;i++)
        leftArr[i] = arr[l + i];
    for(int i=0;i<right;i++)
        rightArr[i] = arr[m+1+i];
    int i = 0, j = 0, k = l;
    while(i < left && j < right){
        if(leftArr[i] < rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    while(i < left)
        arr[k++] = leftArr[i++];
    while(j < right)
        arr[k++] = rightArr[j++];

}
void mergeSort(int arr[], int l, int r)
{
    if(l < r){
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}
};

int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
