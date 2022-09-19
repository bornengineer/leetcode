// Memoization
/*
Solution {
public:
    int rec(int row, int col, int m, int n, vector<vector<int>> &dp){
        if(row == m-1 && col == n-1)return 1;
        
        if(dp[row][col] != -1)return dp[row][col];
        
        int sameRow = 0;
        if(col < n-1){
            sameRow = rec(row, col+1, m, n, dp);
        }
        
        int nextRow = 0;
        if(row < m-1){
            nextRow = rec(row+1, col, m, n, dp);
        }
        
        return dp[row][col] = sameRow + nextRow;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(0, 0, m, n, dp);
    }
};*/

// Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int row = 0; row<m; row++){
            for(int col = 0; col<n; col++){
                if(row == 0 && col == 0)dp[row][col] = 1;
                else{
                    int sameRow = 0;
                    if(col > 0){
                        sameRow = dp[row][col-1];
                    }
                    int nextRow = 0;
                    if(row > 0){
                        nextRow = dp[row-1][col];
                    }
                    dp[row][col] = sameRow + nextRow;
                }
            }
        }
        return dp[m-1][n-1];
    }
};