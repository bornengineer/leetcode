// class Solution {
// public:
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

class Solution {
public:
    // RECURSION + MEMOIZATION
    int rec(int buy, int idx, vector<int>& prices, int n, vector<vector<int>>& memo){
        if(idx == n)return 0;
        if(memo[idx][buy] != -1)return memo[idx][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + rec(0, idx+1, prices, n, memo) , 0 + rec(1, idx+1, prices, n, memo));    
        }
        else{
            profit = max(prices[idx] + rec(1, idx+1, prices, n, memo) , 0 + rec(0, idx+1, prices, n, memo));    
        }
        return memo[idx][buy] = profit;
    }    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n,vector<int>(2,-1));
        return rec(1, 0, prices, n, memo);
    }
};