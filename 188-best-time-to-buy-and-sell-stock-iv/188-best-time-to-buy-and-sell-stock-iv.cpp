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