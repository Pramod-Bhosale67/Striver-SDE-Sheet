//code on gfg
#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity = O(V + E)
    Space Complexity = (N) + O(N) + O(N)
*/

class Solution {
  public:
    void findDFS(int src, vector<int> adj[], vector <int> &dfs, vector<int> &visit){
        visit[src] = 1;
        dfs.push_back(src);
        
    //now visiting the non visited adj Nodes to the given source
        for (auto it: adj[src]){
            if (!visit[it]){
                findDFS(it, adj, dfs, visit);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector <int> visit(V, 0);
        vector <int> dfs;
        
        for (int i = 0; i < V; i++){
            if (!visit[i]){
                findDFS(i, adj, dfs, visit);
            }
        }
        
        return dfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
