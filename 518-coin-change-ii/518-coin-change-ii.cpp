/*class Solution {
public:
    int rec(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(dp[idx][amount] != -1)return dp[idx][amount];
        
        if(idx <= 0){
            return(amount % coins[0] == 0);
        }
        // not pick
        int notPick = rec(idx-1, amount, coins, dp);   
        
        //pick
        int pick = 0;
        if(coins[idx] <= amount){
            pick = rec(idx, amount - coins[idx], coins, dp);
        }
            
        return dp[idx][amount] = pick + notPick;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // making vector of amount+1 size cause it's value can be 0 also
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return rec(n-1, amount, coins, dp);
    }
};*/

class Solution {
public:    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // making vector of amount+1 size cause it's value can be 0 also
        vector<vector<int>> dp(n+1, vector<int>(amount+1,0));
        
        for(int t = 0; t<=amount; t++){
            dp[0][t] = t % coins[0] == 0;
        }
        
        for(int idx = 1; idx < n; idx++){
            for(int t = 0; t<=amount; t++){
                // not pick
                int notPick = dp[idx-1][t];
        
                //pick
                int pick = 0;
                if(coins[idx] <= t){
                    pick = dp[idx][t - coins[idx]];
                }

                dp[idx][t] = pick + notPick;
            }
        }
        
        return dp[n-1][amount];
    }
};