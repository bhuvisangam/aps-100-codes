/*There is one meeting room in a firm.
There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
         vector<pair<int,int>>v;
       for(int i=0;i<n;i++)

       {
           pair<int,int>p(end[i],start[i]);
            v.push_back(p);
       }
        sort(v.begin(),v.end());
       int count=1,p=v[0].first;
        for(int i=1;i<n;i++)
          {
           if(v[i].second>p)
           {
               count++;
               p=v[i].first;
           }

       }return count;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
