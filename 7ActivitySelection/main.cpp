
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.

    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector< pair<int,int>> p;
        for(int i=0;i<n;i++)
        {
            p.push_back(make_pair(end[i],start[i]));
        }
        int c=1;
        sort(p.begin(),p.end());
        int ans=p[0].first;
        for(int i=1;i<n;i++)
        {
            if(p[i].second>ans)
            {
                ans=p[i].first;
                c++;
            }
        }
        return c;
    }
};
int main()
{
    int t;

    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

