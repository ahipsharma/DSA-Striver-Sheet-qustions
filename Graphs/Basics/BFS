// BFS traversal

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        int vis[V] = {0};
        vector<int> res;
        // Insert 1st node;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return res;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> adj[n];
        for(int i=0; i<m; i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution ob;
        vector<int> res = ob.bfsOfGraph(n, adj);
        for(auto it : res)
            cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}
