//You are given two strings A and B that are made of lowercase english alphabets. Find the numbers of different pairs (( i , j) , (k , l )) such that the substring A[i...j] and B[k...l] are equal and the value of j-i+1 is minimum.
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    string A,B;
    cin>>A>>B;
    int fa[26] = {0};
    int fb[26]={0};
  for (char c : A) {
  fa[c - 'a']++;
  }

  int sum = 0;

   for (char c : B) {
   fb[c - 'a']++;
  }
   for(int i=0;i<26;i++){
    sum+=(fa[i]*fb[i]);
  }
    cout<<sum<<endl;
    return 0;
}
