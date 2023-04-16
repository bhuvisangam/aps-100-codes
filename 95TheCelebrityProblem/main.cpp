/*A celebrity is a person who is known to all but does not know anyone at a party.
If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j
is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n)
    {
      int start=0,end=n-1;

    while(start < end){

        if(M[start][end]==1) start++;

        else end--;
    }

        for(int i=0;i<n;i++){
            if(i!=start){
                 if(M[i][start]==0 || M[start][i]==1)
                 return -1;
            }
        }
    return start;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
