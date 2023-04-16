/*In order to attract more customers, manager is shuffling the shop positions everyday.
 Every new day, a shop gets relocated to another location.
 If today shop number 10 is at position 1, then tomorrow it may be shuffled to position 5 etc.
 Manager has observed that when the shop-sequence count is higher or equal to the number of shops, there is increase in overall fun-fair profit.
 Given a sequence allocation,help manager to decide if the arrangement has profitable shop-sequence count.
Shop-Sequence Count: For every shop numbers positioned at i and j, If position(j) > position(i) and if shop number of i > shop number of j, then it is added to shop-sequence count. If both the shop numbers are equal,
it does not count under shop-sequence count.*/
#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, int> >& v, vector<int>& ans,
        int l, int mid, int h)
{

    vector<pair<int, int> >
        t; // temporary array for merging both halves
    int i = l;
    int j = mid + 1;

    while (i < mid + 1 && j <= h) {

        // v[i].first is greater than all
        // the elements from j till h.
        if (v[i].first > v[j].first) {
            ans[v[i].second] += (h - j + 1);
            t.push_back(v[i]);
            i++;
        }
        else {
            t.push_back(v[j]);
            j++;
        }
    }

    // if any elements left in left array
    while (i <= mid)
        t.push_back(v[i++]);
    // if any elements left in right array
    while (j <= h)
        t.push_back(v[j++]);
    // putting elements back in main array in
    // descending order
    for (int k = 0, i = l; i <= h; i++, k++)
        v[i] = t[k];
}

void mergesort(vector<pair<int, int> >& v, vector<int>& ans,
            int i, int j)
{
    if (i < j) {
        int mid = (i + j) / 2;

        // calling mergesort for left half
        mergesort(v, ans, i, mid);

        // calling mergesort for right half
        mergesort(v, ans, mid + 1, j);

        // merging both halves and generating answer
        merge(v, ans, i, mid, j);
    }
}

vector<int> constructLowerArray(int* arr, int n)
{

    vector<pair<int, int> > v;
    // inserting elements and corresponding index
    // as pair
    for (int i = 0; i < n; i++)
        v.push_back({ arr[i], i });

    // answer array for keeping count
    // initialized by 0,
    vector<int> ans(n, 0);

    // calling mergesort
    mergesort(v, ans, 0, n - 1);

    return ans;
}

// Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
    auto ans = constructLowerArray(a, n);
        int sum=0;
    for (auto x : ans) {
        sum+=x;
     }
        cout<<sum<<endl;
        if(sum>=n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
