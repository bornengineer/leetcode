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