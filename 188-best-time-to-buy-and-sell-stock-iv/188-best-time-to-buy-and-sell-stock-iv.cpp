/*
// RECURSION + MEMOIZATION
class Solution {
public:
    int rec(int buy, int idx, vector<int>& prices, int n, int k, vector<vector<vector<int>>>& memo){
        if(k == 0 || idx == n)return 0;
        if(memo[idx][buy][k] != -1)return memo[idx][buy][k];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + rec(0, idx+1, prices, n, k, memo), 0 + rec(1, idx+1, prices, n, k, memo));
        }
        else{
            profit = max(prices[idx] + rec(1, idx+1, prices, n, k-1, memo), 0 + rec(0, idx+1, prices, n, k, memo));
        }
        return memo[idx][buy][k] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo (n,vector<vector<int>>(2, vector<int>(k+1, -1)));
        return rec(1, 0, prices, n, k, memo);
    }
};


// DP TABULATION || BOTTOM UP
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // initializing by k+1 because we'll have to use the 0 indexed value of cap by - dp[idx+1][1][cap-1]
        vector<vector<vector<int>>> dp (n+1,vector<vector<int>>(2, vector<int>(k+1, 0)));
        // No need to write base case ie dp[][][] = something, cause we are already starting from 0
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap<=k ; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[idx] + dp[idx+1][0][cap], 0 + dp[idx+1][1][cap]);
                    }
                    else{
                        profit = max(prices[idx] + dp[idx+1][1][cap-1], 0 + dp[idx+1][0][cap]);
                    }
                    dp[idx][buy][cap] = profit; 
                }
            }
        }
        return dp[0][1][k];
    }
};
*/

// RECURSION + MEMOIZATION USING 2D VECTOR
class Solution {
public:
    int f(int idx, int tranNo, vector<int>& p, int k, int n, vector<vector<int>>& memo){
        if(idx == n || tranNo == 2*k)return 0;
        
        if(memo[idx][tranNo] != -1)return memo[idx][tranNo];
        
        int profit = 0;
        if(tranNo % 2 == 0){
            profit = max(-p[idx] + f(idx+1, tranNo+1, p, k, n, memo), 0 + f(idx+1, tranNo, p, k, n, memo));
        }
        else{
            profit = max( p[idx] + f(idx+1, tranNo+1, p, k, n, memo), 0 + f(idx+1, tranNo, p, k, n, memo));
        }
        return memo[idx][tranNo] = profit;
    }
    
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<int>> memo(n, vector<int>(2*k, -1));
        return f(0, 0, p, k, n, memo);
    }
};