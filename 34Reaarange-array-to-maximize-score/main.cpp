#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
/*You are given a 0-indexed integer array nums. You can rearrange the elements of nums to any order (including the given order).
Let prefix be the array containing the prefix sums of nums after rearranging it.
In other words, prefix[i] is the sum of the elements from 0 to i in nums after rearranging it.
The score of nums is the number of positive integers in the array prefix.
Return the maximum score you can achieve.*/
int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int count=0;
        long long int sum=0;
        if(nums[0]>0)
        {
         count++;
         sum=nums[0];
        }
        for(int i=1;i<nums.size();i++){
             sum += nums[i];
            if(sum > 0)
            count++;
            else break;
        }
        return count;
}
int main(){
 vector<int> a={2,-1,0,1,-3,3,-3};
 cout<<maxScore(a);
}
