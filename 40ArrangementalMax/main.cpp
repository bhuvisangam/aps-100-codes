/*Changes are good and changes might bring lorels.
The Fun Fair manager has decided to change the arangement of shops in the form of a 2D grid - N X M.
He then wants to find out the sub-grid which gives the maximum profit.
The quest does not stop there. Once he gets the grid, he is adding bosters to all the shops in the selected
sub-grid that are running under loss. If a shop is under L amount of loss, manager is adding 2L booster so that it contributes to further profit of L.*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int  printVector(vector<int> const &input)
{
    int sum=0;
    for (int i = 0; i < input.size(); i++) {
        if(input[i]<0)
            continue;
        else
        sum+=abs(input[i]);

    }
    return sum;
}

int findMaxSumSubmatrix(vector<vector<int>> const &mat)
{
    // base case
    if (mat.size() == 0) {
        return 0;
    }

    int M = mat.size();
    int N = mat[0].size();

    int S[M+1][N+1];

    for (int i = 0; i <= M; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == 0 || j == 0) {
                S[i][j] = 0;
            }
            else {
                S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + mat[i-1][j-1];
            }
        }
    }

    int maxSum = INT_MIN;
    int rowStart, rowEnd, colStart, colEnd;

    for (int i = 0; i < M; i++)
    {
        for (int j = i; j < M; j++)
        {
            for (int m = 0; m < N; m++)
            {
                for (int n = m; n < N; n++)
                {
                    int submatrix_sum = S[j+1][n+1] - S[j+1][m] - S[i][n+1] + S[i][m];

                    if (submatrix_sum > maxSum)
                    {
                        maxSum = submatrix_sum;
                        rowStart = i;
                        rowEnd = j;
                        colStart = m;
                        colEnd = n;
                    }
                }
            }
        }
    }
   int sum=0;
    //cout << "The maximum sum submatrix is\n\n";
    for (int i = rowStart; i <= rowEnd; i++) {
        vector<int> row;
        for (int j = colStart; j <= colEnd; j++) {
            row.push_back(mat[i][j]);
        }
       sum+= printVector(row);
    }
    cout<<maxSum<<endl;
   cout<<sum<<endl;
    return maxSum;
}
int main()
{
    int n,m;
    cin>>n>>m;

   vector<vector<int> > d;
    int val;
   for(int i = 0; i < n; i++){
      vector<int> temp;
      for(int j = 0; j <m; j++){
        cin >> val;
        temp.push_back(val);
     }
      d.push_back(temp);
       temp.clear();
   }
    // cout << "\nThe maximum sum is " << findMaxSumSubmatrix(d);
    int x=findMaxSumSubmatrix(d);
    //cout<<x;
    cout<<endl;
    return 0;
}
