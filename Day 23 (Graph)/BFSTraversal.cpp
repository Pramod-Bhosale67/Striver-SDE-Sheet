#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity = O(V + E)
    Space Complexity = (N) + O(N) + O(N)
*/

class Solution {
  public:
    void findBFS(int src, vector <int> adj[], vector <int>&bfs, vector <int>&visit){
        queue <int> q;
        q.push(src);
        visit[src] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            bfs.push_back(node);
            
            for (auto it: adj[node]){
                if (!visit[it]){
                    q.push(it);
                    visit[it] = 1;
                }
            }
        }
        
        
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector <int> visit(V, 0);
        vector <int> bfs;
        
        
        findBFS(0, adj, bfs, visit);
        
        
        return bfs;
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
