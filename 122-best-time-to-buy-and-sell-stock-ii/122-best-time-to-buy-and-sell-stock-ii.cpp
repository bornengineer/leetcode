// class Solution {
// public:
// my O(n) accepted approach
//     int maxProfit(vector<int>& prices) {
//         int maxProfTillNow = 0;
//         int min = INT_MAX;
//         int totalProfit = 0;
//         for(int i = 0; i<prices.size(); i++){
//             if(prices[i] < min) min = prices[i];
//             else if(prices[i] > min){
//                 maxProfTillNow = prices[i] - min;
//                 totalProfit += maxProfTillNow;
//                 maxProfTillNow = 0;
//                 min = prices[i];
//             }
//         }
//         return totalProfit;
//     }
// };


    // RECURSION + MEMOIZATION
// class Solution {
// public:
//     int rec(int buy, int idx, vector<int>& prices, int n, vector<vector<int>>& memo){
//         if(idx == n)return 0;
//         if(memo[idx][buy] != -1)return memo[idx][buy];
//         int profit = 0;
//         if(buy){
//             // if we buy we are currently in loss (that's why we are using -prices[idx]) and it
//             // will be replenished by selling the stock and adding a +ve value to it
//             // below we are taking max of two cases-
//             // 1. buying the stock
//             // 2. not buying the stock (same cases are considered in the else block for sell)
//             profit = max(-prices[idx] + rec(0, idx+1, prices, n, memo) , 0 + rec(1, idx+1, prices, n, memo));   
//         }
//         else{
//             profit = max(prices[idx] + rec(1, idx+1, prices, n, memo) , 0 + rec(0, idx+1, prices, n, memo));   
//         }
//         return memo[idx][buy] = profit;
//     }    
    
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> memo(n,vector<int>(2,-1));
//         return rec(1, 0, prices, n, memo);
//     }
// };


    // DP BOTTOM UP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    // if we buy we are currently in loss (that's why we are using -prices[idx]) and it
                    // will be replenished by selling the stock and adding a +ve value to it
                    // below we are taking max of two cases-
                    // 1. buying the stock
                    // 2. not buying the stock (same cases are considered in the else block for sell)
                    profit = max(-prices[idx] + dp[idx+1][0] , 0 + dp[idx+1][1]);   
                }
                else{
                    profit = max( prices[idx] + dp[idx+1][1] , 0 + dp[idx+1][0]);
                }
                dp[idx][buy] = profit;                
            }
        }
        return dp[0][1];
    }
};