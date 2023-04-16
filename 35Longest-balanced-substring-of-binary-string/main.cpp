#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
/*You are given a binary string s consisting only of zeroes and ones.

A substring of s is considered balanced if all zeroes are before ones and the number of zeroes is equal to the number of ones inside the substring. Notice that the empty substring is considered a balanced substring.

Return the length of the longest balanced substring of s.

A substring is a contiguous sequence of characters within a string.*/
 int findTheLongestBalancedSubstring(string s) {
        int zero=0,one=0,count=0;
        int len=s.length();
        int i=0;
      while(len){
          one=0;
          zero=0;
          while(s[i]=='0'){
              zero++;
              len--;
              i++;
          }
          while(s[i]=='1'){
              one++;
              len--;
              i++;
          }
          count=max(count,min(zero,one));
      }
        return count*2;
}

int main(){
 string s;
 s="01000111";
 cout<<findTheLongestBalancedSubstring(s);
}
