// it is same as that of Best Time to Buy and Sell Stock IV but here we are passing 2 to k

// RECURSION + MEMOIZATION
/*
class Solution {
public:
    // 3D Memoization / DP
    int rec(int buy, int idx, vector<int>& prices, int n, int k, vector<vector<vector<int>>>& memo){
        if(k == 0 || idx == n)return 0;
        if(memo[idx][buy][k] != -1)return memo[idx][buy][k];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + rec(0, idx+1, prices, n, k, memo), 0 + rec(1, idx+1, prices, n, k, memo));
        }
        else{
            // when we are done selling the stock our 1 transaction will be done & decrement k by 1;
            profit = max(prices[idx] + rec(1, idx+1, prices, n, k-1, memo), 0 + rec(0, idx+1, prices, n, k, memo));
        }
        return memo[idx][buy][k] = profit;
    }
    
    // it is same as that of Best Time to Buy and Sell Stock IV but here we are passing 2 to k
    int maxProfit(vector<int>& prices, int k = 2) {
        int n = prices.size();
        // 3D vector is created to keep track of all the states 
        // for eg if idx = n-1 we have to check weather we are allowed to buy or sell ie. buy = 1 or 0?
        // and in that also we have to keep track of k values (at which value of k we have current ans or is k = 0)
        vector<vector<vector<int>>> memo (n,vector<vector<int>>(2, vector<int>(k+1, -1)));
        return rec(1, 0, prices, n, k, memo);
    }
};


// DP TABULATION || BOTTOM UP (3D DP)
class Solution {
public:
    // it is same as that of Best Time to Buy and Sell Stock IV but here we are passing 2 to k
    int maxProfit(vector<int>& prices, int k = 2) {
        int n = prices.size();
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

// DP TABULATION || BOTTOM UP (2D DP)
class Solution {
public:
    int maxProfit(vector<int>& p, int k = 2) {
        int n = p.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        
        for(int idx = n-1; idx>=0; idx--){
            for(int tranNo = 2*k -1; tranNo>=0; tranNo--){
                int profit = 0;
                if(tranNo % 2 == 0){
                    profit = max(-p[idx] + dp[idx+1][tranNo+1], dp[idx+1][tranNo]);
                }
                else{
                    profit = max( p[idx] + dp[idx+1][tranNo+1], dp[idx+1][tranNo]);
                }
                dp[idx][tranNo] = profit;
            }
        }
        return dp[0][0]; 
    }
};


// my approach - too complicated and didn't work
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