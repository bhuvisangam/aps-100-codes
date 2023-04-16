/*Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m.
 Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. */
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

string isSubset(int a1[], int a2[], int n, int m) {

    int b1[100000]={0};
    int b2[100000]={0};
    string n1="No";
    string y="Yes";
    for(int i=0;i<n;i++)
    {
        b1[a1[i]]++;
    }
    for(int j=0;j<m;j++)
    {
        b2[a2[j]]++;
    }
    for(int i=0;i<100000;i++)
    {
        if(b1[i]<b2[i])
        {
            return n1;
        }
    }
    return y;
}
