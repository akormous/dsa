// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    // the idea is to go in all directions
    void travelIsland(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if(grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        // go down
        if(i + 1 < m)
            travelIsland(grid, i+1, j, m, n);
        
        // go right
        if(j + 1 < n)
            travelIsland(grid, i, j+1, m, n);
        
        // go up
        if(i - 1 >= 0)
            travelIsland(grid, i-1, j, m, n);
            
        // go left
        if(j-1 >= 0)
            travelIsland(grid, i, j-1, m, n);
            
        // go up-right
        if(i-1 >= 0 && j+1 < n)
            travelIsland(grid, i-1, j+1, m, n);
        
        // go up-left
        if(i-1 >=0 && j-1 >= 0)
            travelIsland(grid, i-1, j-1, m, n);
            
        // go down-right        
        if(i+1 < m && j+1 < n)
            travelIsland(grid, i+1, j+1, m, n);
        
        // go down-left
        if(i+1 < m && j-1 >= 0)
            travelIsland(grid, i+1, j-1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    travelIsland(grid, i, j, m, n);
                    count++;
                }
                    
            }
        }
        return count;
    }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends