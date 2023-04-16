/*Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
 public:
   int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
       vector<vector<int>>r(N,vector<int>(M,INT_MAX));
      queue<pair<int, int>> q;
          if(A[0][0]==0 || A[X][Y]==0){
          return -1;
          }
       r[0][0]=0;
       q.push({0,0});

       while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;

        if(i!=0 && A[i-1][j]==1 && r[i][j]+1<r[i-1][j]){
            q.push({i-1,j});
            r[i-1][j]=r[i][j]+1;
        }

        if(i+1!=N && A[i+1][j]==1 && r[i][j]+1<r[i+1][j]){
            q.push({i+1,j});
            r[i+1][j]=r[i][j]+1;
        }

            if(j+1!=M && A[i][j+1]==1 && r[i][j]+1<r[i][j+1]){
            q.push({i,j+1});
            r[i][j+1]=r[i][j]+1;
        }

            if(j!=0 && A[i][j-1]==1 && r[i][j]+1<r[i][j-1]){
            q.push({i,j-1});
            r[i][j-1]=r[i][j]+1;
        }

        q.pop();
    }
       if(r[X][Y]==INT_MAX){
           return -1;
       }
       return r[X][Y];

   }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
