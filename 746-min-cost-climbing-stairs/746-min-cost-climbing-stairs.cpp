class Solution {
public:
    // recursive approach (gives TLE but 259 / 283 test cases passed)
//     int helper(int i, vector<int>& cost){
//         if(i >= cost.size())return 0;
        
//         return min(helper(i+1, cost), helper(i+2, cost)) + cost[i];
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) {
//         return min(helper(0, cost),helper(1,cost));
//     }
    
    
    // Memoization
//     int helper(int i, vector<int>& cost, vector<int>& memo){
//         if(i>=cost.size())return 0;
        
//         if(memo[i])return memo[i];
        
//         memo[i] = min(helper(i+1, cost, memo), helper(i+2, cost, memo)) + cost[i];
        
//         // for(auto i : memo)cout<<i<<" ";
//         // cout<<endl<<"memo["<<i<<"] = "<<memo[i]<<endl;
        
//         return memo[i];
//     }
        
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> memo(n);
//         int ans = min(helper(0, cost, memo),helper(1,cost, memo));
//         return ans;
//     }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[n-1] = cost[n-1];
        dp[n-2] = cost[n-2];
        
        for(int i = n-3; i>=0; i--){
            dp[i] = min(dp[i+1], dp[i+2]) + cost[i];
        }
        
        return min(dp[0], dp[1]);
    }
};