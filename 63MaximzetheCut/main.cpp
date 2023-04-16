/*Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
       int cut[3];
       cut[0] = x;
       cut[1] = y;
       cut[2] = z;
       int t[4][n+1];

       for (int i = 0;i<4;i++)
       {
           for (int j =0 ; j<n+1; j++)
           {
               if (i==0)
               {
                   t[i][j]=INT_MIN;
               }
               if (j==0)
               {
                t[i][j]=0;
               }
           }
       }
       for (int i = 1; i<4;i++)
       {
           for (int j =1 ; j<n+1;j++)

           {
               if (cut[i-1]<=j)
               {
                   t[i][j]= max(t[i-1][j],t[i][j-cut[i-1]]+1);
               }
               else
               {
                   t[i][j]= t[i-1][j];
               }
           }
       }
       if(t[3][n]<0)
       {
           return 0;
       }
       return t[3][n];
    }
};
int main() {

    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
