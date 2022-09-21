// Memoization (gives TLE)
/*
class Solution {
public:
    int rec(int i1, int i2, string t1, string t2, vector<vector<int>> &dp){
        if(i1 < 0 || i2 < 0)return 0;
        
        if(dp[i1][i2] != -1)return dp[i1][i2];
        
        // match
        if(t1[i1] == t2[i2]){
            return dp[i1][i2] = 1 + rec(i1-1, i2-1, t1, t2, dp);
        }
        // notMatch
        return dp[i1][i2] = max(0 + rec(i1-1, i2, t1, t2, dp), 0 + rec(i1, i2-1, t1, t2, dp));  
    }
    
    int longestCommonSubsequence(string t1, string t2) {
        int i1 = t1.size();
        int i2 = t2.size();
        vector<vector<int>> dp(i1, vector<int>(i2, -1));
        return rec(i1, i2, t1, t2, dp);
    }
};
*/

class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // for(int j = 0 ; j<=m; j++)dp[0][j] = 0;  // base case for i
        // for(int i = 0 ; i<=n; i++)dp[i][0] = 0;  // for j
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                // match
                if(t1[i-1] == t2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                // notMatch
                else dp[i][j] = max(0 + dp[i-1][j], 0 + dp[i][j-1]);  
            }
        }
        return dp[n][m];
    }
};