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
    
    int maxProfit(vector<int>& prices, int k = 2) {
        int n = prices.size();
        vector<vector<vector<int>>> memo (n,vector<vector<int>>(2, vector<int>(k+1, -1)));
        return rec(1, 0, prices, n, k, memo);
    }
};


// DP TABULATION || BOTTOM UP
// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int k = 2) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp (n+1,vector<vector<int>>(2, vector<int>(k+1, 0)));
//         // No need to write base case ie dp[][][] = something, cause we are already starting from 0
//         for(int idx = n-1; idx >= 0; idx--){
//             for(int buy = 0; buy <= 1; buy++){
//                 for(int cap = 1; cap<=k ; cap++){
//                     int profit = 0;
//                     if(buy){
//                         profit = max(-prices[idx] + dp[idx+1][0][cap], 0 + dp[idx+1][1][cap]);
//                     }
//                     else{
//                         profit = max(prices[idx] + dp[idx+1][1][cap-1], 0 + dp[idx+1][0][cap]);
//                     }
//                     dp[idx][buy][cap] = profit; 
//                 }
//             }
//         }
//         return dp[0][1][k];
//     }
// };



// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         // int k = 2;
//         // int interval = 0;
//         /*
//         int maxProfit = 0;
//         int profit = 0;
//         int maxTillNow = INT_MIN;
//         int min = INT_MAX;
//         bool second = true;
//         for(int i = 0; i<prices.size(); i++){
//             if(i>0 && prices[i] == prices[i-1])continue;
            
//             if(prices[i] < maxTillNow || (i == prices.size() && prices[i] > maxTillNow)){
//                 if(prices[i] > maxTillNow)maxTillNow = prices[i];
//                 maxProfit = max(maxTillNow - min, maxProfit);
//                 if(second){
//                     profit += maxProfit;
//                     second = false;
//                     maxProfit = 0;
//                     maxTillNow = INT_MIN;
//                 }
//             }
            
//             if(prices[i] < min)min = prices[i];
//             if(prices[i] > min && prices[i] > maxTillNow)maxTillNow = prices[i];
//             if(i == prices.size() - 1)profit += maxProfit;    
//         }
//         return profit;
//         */
//     }
// };