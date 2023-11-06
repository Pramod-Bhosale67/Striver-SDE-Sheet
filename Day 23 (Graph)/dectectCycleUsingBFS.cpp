//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity = O(V + E)
    Space Complexity = (N) + O(N)
*/

class Solution {
  public:
    bool isPossible(int src, vector <int> adj[], vector <int> &visit){
        //{node, parent}
        queue <pair<int, int>> q;
        q.push({src, -1});
        visit[src] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto it: adj[node]){
                if (!visit[it]){
                    q.push({it, node});
                    visit[it] = 1;
                }else if (parent != it){
                    return true;
                }
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector <int> visit(V, 0);
        
        for (int i = 0; i < V; i++){
            if (!visit[i]){
                if (isPossible(i, adj, visit) == true)
                    return true;
            }
        }
        
        return false;
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
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
