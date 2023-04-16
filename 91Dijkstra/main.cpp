#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
typedef pair<int,int> pi;
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> distance(V,INT_MAX);
        priority_queue<pi,vector<pi>, greater<pi>> q;

        q.push({0,S});
        distance[S] = 0;
        while(!q.empty()){
            pair<int, int> top = q.top();
            int parentCost = top.first;
            int node = top.second;
            q.pop();

            for(auto it: adj[node]){
                int nextNode = it[0];
                int edgeCost = it[1];
                if((distance[node] + edgeCost) < distance[nextNode]){
                    distance[nextNode] = distance[node] + edgeCost;
                    q.push({distance[nextNode],nextNode});
                }

            }
        }

        return distance;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;

        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);

    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
