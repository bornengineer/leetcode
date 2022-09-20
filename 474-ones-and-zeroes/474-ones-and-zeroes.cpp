// Memoization
/*
class Solution {
public:
    int countSetBits(string s){
        int cnt = 0;
        while(!s.empty()){
            char c = s.back();
            cnt += c == '1'? 1 : 0;
            s.pop_back();
        } 
        return cnt;
    }
    
    int rec(int idx, int m, int n, vector<string>& strs, vector<vector<vector<int>>> &dp){
        if(idx < 0)return 0;
        
        if(dp[idx][m][n] != -1)return dp[idx][m][n];
        
        int ones = countSetBits(strs[idx]);
        int zeroes = strs[idx].size() - ones;
        
        int take= 0;
        if(m >= zeroes && n >= ones){
            take = 1 + rec(idx-1, m-zeroes, n-ones, strs, dp);
        }
        int notTake = 0 + rec(idx-1, m, n, strs, dp);
        
        return dp[idx][m][n] = max(take,notTake);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int idx = strs.size();
        vector<vector<vector<int>>> dp(idx, vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        return rec(idx-1, m, n, strs, dp); 
    }
};
*/

class Solution {
public:
    int countSetBits(string s){
        int cnt = 0;
        while(!s.empty()){
            char c = s.back();
            cnt += c == '1'? 1 : 0;
            s.pop_back();
        } 
        return cnt;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int i = strs.size();
        vector<vector<vector<int>>> dp(i+1, vector<vector<int>>(m+1, vector<int>(n+1)));
        
        for(int idx = 1; idx<=i; idx++){
            for(int zeroes = 0; zeroes<=m; zeroes++){
                for(int ones = 0; ones<=n; ones++){
                    
                    int o = countSetBits(strs[idx-1]);
                    int z = strs[idx-1].size() - o;

                    int take = 0;
                    if(z <= zeroes && o <= ones){
                        take = 1 + dp[idx-1][zeroes-z][ones-o];
                    }
                    int notTake = 0 + dp[idx-1][zeroes][ones];
        
                    dp[idx][zeroes][ones] = max(take,notTake);
                }
            }
        }
        return dp[i][m][n]; 
    }
};