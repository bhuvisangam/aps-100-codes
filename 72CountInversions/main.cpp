/*Given an array of integers. Find the Inversion Count in the array.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted.
If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    long long merge(vector<long long>&nums, int low,int mid,int high)
    {
        long long inv_count=0, k=0;
        int l = low, r = mid+1, size = high-low+1;
        vector<long long>sorted(size);
        while(l <= mid and r <= high)
        {
            if(nums[l] <= nums[r]){
                sorted[k++] = nums[l++];
            }
            else
            {
                sorted[k++] = nums[r++];
                inv_count = inv_count + (mid-l+1); // only these changes
            }
        }

        while(l <= mid)
            sorted[k++] = nums[l++];

        while(r <= high)
            sorted[k++] = nums[r++];

        for(k = 0 ; k < size ; k++)
            nums[k+low] = sorted[k];
        return inv_count;
    }

    long long mergeSort(vector<long long>&nums,int low,int high)
    {
        long long inv_count = 0;
        if(low >= high) return 0;

        long long mid = low + (high-low)/2;
        inv_count += mergeSort(nums,low,mid);
        inv_count += mergeSort(nums,mid+1,high);
        inv_count += merge(nums,low,mid,high);
        return inv_count;
    }

    long long int inversionCount(long long arr[], long long n)
    {
        vector<long long>nums;
        for(int i=0;i<n;i++)
            nums.push_back(arr[i]);

        return mergeSort(nums, 0, n-1);
    }
};

int main() {

    long long T;
    cin >> T;

    while(T--){
        long long N;
        cin >> N;

        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }

    return 0;
}
