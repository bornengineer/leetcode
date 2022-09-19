// Memoization
/*
class Solution {
public:
    int rec(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row == 0 && col == 0)return grid[0][0];
        
        if(dp[row][col] != -1)return dp[row][col];
        
        int top = INT_MAX, left = INT_MAX;
        if(row > 0)top = grid[row][col] + rec(row-1, col, grid, dp);
        
        if(col > 0)left = grid[row][col] + rec(row, col-1, grid, dp);
        
        return dp[row][col] = min(top, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(m-1, n-1, grid, dp);
    }
};
*/

// Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int row = 0; row<m; row++){
            for(int col = 0; col<n; col++){
                if(row == 0 && col == 0) dp[row][col] = grid[0][0];
                else{   
                    int top = INT_MAX, left = INT_MAX;
                    if(row > 0)top = grid[row][col] + dp[row-1][col];

                    if(col > 0)left = grid[row][col] + dp[row][col-1];

                    dp[row][col] = min(top, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};