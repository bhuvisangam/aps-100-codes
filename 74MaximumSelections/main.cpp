/*You are given a finite number of courses and N range of numbers each depicting a bundle of courses. Select the maximum number of bundles such that no courses overlap in any of the bundle.

Note: The ending of a range being the same as start of another isn't considered as an overlap.*/
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int max_non_overlapping( vector< vector<int> >& ranges )
    {
        int n=ranges.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)v[i]={ranges[i][1],ranges[i][0]};
        sort(v.begin(),v.end());
        int cnt=1;
        int strt=v[0].first;
        for(int i=1;i<n;i++){
            if(v[i].second>=strt){
                cnt++;
                strt=v[i].first;

            }
        }
        return cnt;
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

		vector< vector<int> > v(n,vector<int>(2));
		for(int i=0; i<n; i++)
			cin>> v[i][0] >> v[i][1];

        Solution ob;
		cout<< ob.max_non_overlapping(v) << endl;
	}
	return 1;
}
