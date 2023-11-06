//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*  
    Time Complexity = O(N * M)
    Space Complexity = O(N*M)
*/

// } Driver Code Ends
class Solution {
  public:
    void bfs(int r, int c, vector <vector<char>> &grid, vector<vector<int>> &visit){
        int n = grid.size();
        int m = grid[0].size();
        
        //{row, col} ---> queue
        queue <pair<int, int>> q;
        q.push({r, c});
        visit[r][c] = 1;
        
        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int i = 0; i < 8; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                
                if (nrow < n && nrow >= 0 && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' &&
                    visit[nrow][ncol] != 1){
                        q.push({nrow, ncol});
                        visit[nrow][ncol] = 1;
                    }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector <vector <int>> visit(n, vector<int>(m, 0));
        int cnt = 0;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!visit[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, grid, visit);
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends