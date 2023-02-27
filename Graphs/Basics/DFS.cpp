// DFS
#include <iostream>
#include <vector>

using namespace std;

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
        vector<int> ans = ob.dfsOfGraph(n, adj);
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}

class Solution {
  private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
        vis[node] = 1;
        ls.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, ls);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int start = 0;
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
};